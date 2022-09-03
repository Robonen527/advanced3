#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Generals/FilesFunc.hpp"
#include "Generals/Iris.hpp"
using namespace std;

void run(int sock);

string read(int sock);

void send(int sock);