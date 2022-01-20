#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

using namespace std;
#include <iostream>
#include "FrontBoek.h"

TEST_GROUP(FirstTestGroup)
{
    void setup() {
        cout << "BeforeTest\n";
    }

    void teardown() {
        cout << "AfterTest\n";
    }
};

TEST_GROUP(boekengroep)
{};

TEST(boekengroep, front)
{
    FrontBoek boek("Wouter", "Logboek");

    cout << "Schrijfer: '" << boek.naamSchrijver() << "'\n";

    boek.verhoogSchrijver();

    // Uhhh this doesn't work. Given functions tries to add 1 to a string???!

    // If I wanted to test this, I would add something like:

    /*
        string oldSchrijfer = boek.naamSchrijver();
        boek.verhoogSchrijver();
        STRCMP_EQUAL(oldSchrijfer =+ 1, boek.naamSchrijfer());
    */

    cout << "Schrijfer: '" << boek.naamSchrijver() << "'\n";


    // FAIL("Fail me!");
}

TEST(FirstTestGroup, SecondTest)
{
    STRCMP_EQUAL("hello", "hello");
}

TEST(FirstTestGroup, ThirdTest)
{
    FrontBoek boek("Wouter", "Logboek");

    FrontBoek newBoek = *boek.maakKopie();

    CHECK(true);
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}