#include <SPI.h>
#include <WiFiNINA.h>
#include "Firebase_Arduino_WiFiNINA.h"
#include <Arduino.h>

extern char ssid[];
extern char pass[];
extern int status;


void connectToWifi(char ssid[]){
  Serial.print("Connecting to network");
  Serial.println(ssid);
  WiFi.begin(ssid);
}

void connectToWifi(char ssid[], char pass[]){
    Serial.print("Connecting to network");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
}

void scanNetworks() {
  // scan for nearby networks:
  Serial.println("** Scanning Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("Couldn't get a WiFi connection");
    scanNetworks();
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);
  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
      Serial.print("Found Network: ");
      Serial.println(WiFi.SSID(thisNet));
      if(strcmp(WiFi.SSID(thisNet),ssid)) {
        if(pass == NULL){
          connectToWifi(ssid);
        }
        else {
          connectToWifi(ssid,pass);
        }
        status = WL_CONNECTED;
        break;
    }
  }
}

void printEncryptionType(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.println("WEP");
      break;
    case ENC_TYPE_TKIP:
      Serial.println("WPA");
      break;
    case ENC_TYPE_CCMP:
      Serial.println("WPA2");
      break;
    case ENC_TYPE_NONE:
      Serial.println("None");
      break;
    case ENC_TYPE_AUTO:
      Serial.println("Auto");
      break;
    case ENC_TYPE_UNKNOWN:
    default:
      Serial.println("Unknown");
      break;
  }
}

void printMacAddress(byte mac[]) {
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0) {
      Serial.print(":");
    }
  }
  Serial.println();
}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to:
  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("BSSID: ");
  printMacAddress(bssid);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("Signal Strength (RSSI):");
  Serial.println(rssi);

  // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption, HEX);
  Serial.println();
}