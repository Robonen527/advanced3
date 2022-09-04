#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
using namespace std;

/**
 * @brief This func is responssible for the running ofthe client side.
 * 
 * @param sock 
 */
void run(int sock);

/**
 * @brief this func reads fromthe server and returns the massage/
 * 
 * @param sock the socket.
 * @return string (the massage from the server).
 */
string read(int sock);

/**
 * @brief This func receives massage from the cin and sendsit to the server.
 * 
 * @param sock (the socket).
 */
void send(int sock);