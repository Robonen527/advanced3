#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Generals/FilesFunc.hpp"
#include "Generals/Iris.hpp"
#include "IOs/SocketIO.hpp"
#include "Commands/CLI.hpp"
#include <thread>
#include <unistd.h>

/**
 * @brief This func runs the cli of the client.
 * 
 * @param client (the CLI of the client).
 */
void runClient(CLI client);

/**
 * @brief This func accepts client.
 * 
 * @param sock (the socket).
 * @param client (a refference to put the client).
 * @param accepted (a refference to tell if the client accepted).
 */
void acceptClient(int sock, int& client, bool& accepted);