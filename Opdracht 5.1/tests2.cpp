#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

using namespace std;

#include "LogLed.h"
#include "Platform.h"

#include <unistd.h>

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, checkSeconds)
{
    Platform platform(23, 20180225);
    LogLed logLed("Wouter", &platform, 25);

    CHECK_EQUAL(25, logLed.hoeveelTijdTeGaan());
}

TEST(FirstTestGroup, checkRun)
{
    Platform platform(23, 20180225);
    LogLed logLed("Wouter", &platform, 25);

    logLed.zetAan();

    sleep(5);

    logLed.zetUit();

    CHECK_EQUAL(20, logLed.hoeveelTijdTeGaan());
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}