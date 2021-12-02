#ifndef NetworkClient_H
#define NEtworkClient_H

void scanNetworks();
void printEncryptionType(int thisType);
void printCurrentNet();
void printMacAddress(byte mac[]) ;
void connectToWifi(char ssid[]);
void connectToWifi(char ssid[], char pass[]);

#endif