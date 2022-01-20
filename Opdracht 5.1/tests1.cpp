#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

using namespace std;

#include "Tijdsduur.h"

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, checkSeconds)
{
    Tijdsduur tijdsduur(10, 1);
    CHECK_EQUAL(1, tijdsduur.getSeconds());
}

TEST(FirstTestGroup, checkMinutes)
{
    Tijdsduur tijdsduur(10, 1);
    CHECK_EQUAL(10, tijdsduur.getMinutes());
}

TEST(FirstTestGroup, checkThird)
{
    Tijdsduur tijdsduur(10, 1);
    Tijdsduur remove(10, 0);
    tijdsduur.eraf(remove);
    CHECK_EQUAL(1, tijdsduur.getSeconds());
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}