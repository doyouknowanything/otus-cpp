#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>


auto stringToTuple(std::string ip = "0.0.0.0")
{
    auto getByteFromString = [&ip]()
    {
        std::string::size_type start = 0;
        std::string::size_type stop = ip.find_first_of('.');

        uint16_t byte = std::stoul(ip.substr(start, stop - start));
        ip = ip.substr(stop + 1);

        return byte;
    };

    auto result = std::tuple{getByteFromString(),
                                  getByteFromString(),
                                  getByteFromString(),
                                  getByteFromString()};

    return result;
}

using IpAddress = decltype(stringToTuple());
using IpsList = std::vector<IpAddress>;

inline void outputIpAddress(const IpAddress& ip)
{
    std::cout   << std::get<0>(ip) << "."
                << std::get<1>(ip) << "."
                << std::get<2>(ip) << "."
                << std::get<3>(ip) << std::endl;
}

template<typename... Args>
void filter(const IpsList& ips, Args... bytesArgs)
{
    auto bytes = std::make_tuple(bytesArgs...);
    constexpr auto filteringBytesCount = std::tuple_size<decltype(bytes)>::value;

    for (const auto& ip: ips)
    {
        bool match;

        if constexpr (filteringBytesCount == 1)
        {
            match = (std::get<0>(ip) == std::get<0>(bytes));
        }
        else if constexpr (filteringBytesCount == 2)
        {
            match = (std::get<0>(ip) == std::get<0>(bytes) &&
                     std::get<1>(ip) == std::get<1>(bytes));
        }
        else if constexpr (filteringBytesCount == 3)
        {
            match = (std::get<0>(ip) == std::get<0>(bytes) &&
                     std::get<1>(ip) == std::get<1>(bytes) &&
                     std::get<2>(ip) == std::get<2>(bytes));
        }
        else if constexpr (filteringBytesCount == 4)
        {
            match = (std::get<0>(ip) == std::get<0>(bytes) &&
                     std::get<1>(ip) == std::get<1>(bytes) &&
                     std::get<2>(ip) == std::get<2>(bytes) &&
                     std::get<3>(ip) == std::get<3>(bytes));
        }
        else
            continue;

        if (match)
            outputIpAddress(ip);
    }
}

auto filter_any(const IpsList& ips, uint16_t byte)
{
    for (const auto& ip: ips)
    {
        if (std::get<0>(ip) == byte ||
            std::get<1>(ip) == byte ||
            std::get<2>(ip) == byte ||
            std::get<3>(ip) == byte)
            outputIpAddress(ip);
    }
}

int main(int, char **)
{
    try
    {
        std::vector<IpAddress> pool;

        for (std::string line; std::getline(std::cin, line);)
        {
            std::string ip = line.substr(0, line.find_first_of('\t'));
            pool.push_back(stringToTuple(ip));
        }

        std::sort(pool.begin(), pool.end(), [](const auto& lhs, const auto& rhs){return lhs > rhs;});

        for (const auto& ip: pool)
            outputIpAddress(ip);

        filter(pool, 1);
        filter(pool, 46, 70);
        filter_any(pool, 46);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}