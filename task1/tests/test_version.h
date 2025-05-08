#pragma once

#include <gtest/gtest.h>
#include <VersionChecker/VersionChecker.h>


TEST(test_version, test_valid_version)
{
    ASSERT_TRUE(VersionChecker::version() > 0);
}