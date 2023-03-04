#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include "Utils.h"

TinyGPS gps;
SoftwareSerial gpsSerial(5,4); // RX-> D2, TX-> D3

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  connectWiFi(); 
}

void loop() {
  getGPSData();
}

void getGPSData() {
  bool newData = false;
  
    while (gpsSerial.available()) {
      char gpsData = gpsSerial.read();
      if (gps.encode(gpsData)) {
        newData = true;
      }
    }

  if(newData) {
    float fLat, fLong;
    unsigned long age;
    gps.f_get_position(&fLat, &fLong, &age);
    Serial.println(fLat);
    Firebase.setFloat("lat", fLat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : fLat);
    Firebase.setFloat("long", fLong == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : fLong);
  }
}

void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Baglaniyor");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Baglandi: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
