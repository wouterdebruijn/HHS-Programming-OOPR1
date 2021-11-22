// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#define PORT 8080
   
int connect(const char* host, char* msg);

class Component {
	private:
		const char* hostname;
		const char* id;
		int value;
	public:
        Component(const char* hostname, const char* id): hostname(hostname), id(id) {};
		const char* getHostname() const;
		const char* getId() const;
		int getValue();
		int get();
        int post(int value);
};

const char* Component::getHostname() const {
	return this->hostname;
}

const char* Component::getId() const {
	return this->id;
}

int Component::getValue() {
	return this->value;
}

int Component::get() {
    char buffer[32] = {};

    // We fetch the value, so we provide the default value of zero. Just to match the syntax.
    strcat(buffer, this->getId());
    strcat(buffer, ":0");

    int value = connect(this->hostname, buffer);
    this->value = value;
    return 1;
}

int Component::post(int value) {
    // Add a semicolon to the end of the id;
    char buffer[32] = {};
    strcat(buffer, this->getId());
    strcat(buffer, ":");

    char numBuffer[8];
    std::sprintf(numBuffer, "%d", value);
    
    strcat(buffer, numBuffer);
    int returnValue = connect(this->hostname, buffer);
    this->value = returnValue;
    return 1;
}

int main(int argc, char const *argv[])
{
    Component button1("172.16.99.100", "3");

    Component led1("172.16.99.101", "0");
    Component led2("172.16.99.101", "1");

    while(1) {
        printf("Reading values from component\n");
        button1.get();

        int buttonValue = button1.getValue();

        printf("Value: %d \n", buttonValue);

        printf("Sending values to the components\n\n");
        led1.post(1);
        led2.post(buttonValue);

        sleep(1);
    }
}

int connect(const char* host, char* msg) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, host, &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    char sendBuffer[32] = {};

    strcat(sendBuffer, msg);
    strcat(sendBuffer, "\n");

    send(sock , sendBuffer , strlen(sendBuffer), 0);
    valread = read(sock, buffer, 1024);

    int returnNumber = std::stoi(buffer);
    return returnNumber;
}
