#include <iostream>

#include <VersionChecker/VersionChecker.h>


int main(int, char **)
{
	std::cout << "Version: " << VersionChecker::version() << std::endl;
	std::cout << "Hello, world!" << std::endl;
	return 0;
}
