#ifndef NetworkClient_H
#define NEtworkClient_H

void scanNetworks(int status, char ssid[], char pass[]);
void printEncryptionType(int thisType);
void printCurrentNet();
void printMacAddress(byte mac[]) ;

#endif