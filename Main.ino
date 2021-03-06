#include "Firebase_Arduino_WiFiNINA.h"
#include "NetworkClient.h"
#include "FirebaseClient.h"

#define DATABASE_URL "burgertracker-default-rtdb.firebaseio.com" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
#define DATABASE_SECRET "BFWuZmPccMH74FuU3Zw59znF7rzv3KWV7dhy3ut4"
char ssid[] = "HOTBOX 4-5B08";
char pass[] = "0544227393";
int status = -1;
FirebaseData data; 
void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }
  
  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.println("Setup connect");
    scanNetworks();
    delay(10000);
  }
  Firebase.begin(DATABASE_URL, DATABASE_SECRET, ssid, pass);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // scan for existing networks:
  if(status != WL_CONNECTED) {
  Serial.println("Not Connected");
  scanNetworks();
  }
  else{
    Serial.println("Connected!");
    Serial.println("Connection data:");
    printCurrentNet();
    Serial.println("Updating Database...");
    updateDatabase(data);
  }
  delay(6000);
}