#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define GPIO_NUMBER_A "19"
#define GPIO_NUMBER_B "26"

#define GPIO4_PATH_A "/sys/class/gpio/gpio19/"
#define GPIO4_PATH_B "/sys/class/gpio/gpio26/"
#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(const char filename[], const char value[])
{
    FILE *fp;                  // create a file pointer fp
    fp = fopen(filename, "w"); // open file for writing
    fprintf(fp, "%s", value);  // send the value to the file
    fclose(fp);                // close the file using fp
}

int main()
{
    printf("Starting the makeLED program\n");
    printf("Setting up the LED on the GPIO 2\n");
    writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER_A);
    writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER_B);
    usleep(100000); // sleep for 100ms
    printf("Setting up the LED on the GPIO\n");
    writeGPIO(GPIO4_PATH_A "direction", "out");
    writeGPIO(GPIO4_PATH_B "direction", "out");
    printf("Turning the LED of GPIO %s on\n", GPIO_NUMBER_A);
    writeGPIO(GPIO4_PATH_A "value", "1");
    printf("Turning the LED of GPIO %s on\n", GPIO_NUMBER_B);
    writeGPIO(GPIO4_PATH_B "value", "1");
    usleep(1000000);
    printf("Turning the LED of GPIO %s off\n", GPIO_NUMBER_A);
    writeGPIO(GPIO4_PATH_A "value", "0");
    printf("Turning the LED of GPIO %s off\n", GPIO_NUMBER_B);
    writeGPIO(GPIO4_PATH_B "value", "0");
    writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER_A);
    writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER_B);
    printf("Finished the makeLED Program\n");
    return 0;
}