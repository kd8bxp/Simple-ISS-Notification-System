/* Copyright (c) 2018 LeRoy Miller
 *  
 *  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson
#include <Adafruit_NeoPixel.h> //https://github.com/adafruit/Adafruit_NeoPixel
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

//Find your Latitude and Longitude here
//https://www.latlong.net/
float mylat = 39.360095;
float mylon = -84.58558;
float isslat, isslon;
int distance;
String payload;

const String iss = "http://api.open-notify.org/iss-now.json"; 
int brightness = 150;
int p = 20; //p = neopixel delay

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, D2, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
   WiFiManager wifiManager;
    wifiManager.autoConnect("AutoConnectAP");
  strip.begin();
  strip.show();
  strip.setBrightness(brightness);
}

void loop() {
 
 getLocation();
  //Serial.println(payload);   //Print the response payload
 decodeJson();
 getDistance();
 issLocSerialDisplay();
 setColor();
 delay(5000);    //Send a request every 30 seconds
 
}

void issLocSerialDisplay() {
  Serial.print("The ISS is currently at ");
  Serial.print(isslat, 4); Serial.print(","); Serial.println(isslon,4);
  Serial.print("The ISS is about "); Serial.print(distance); Serial.println(" miles from you now.\nAnd moving fast!");
    
}

void getLocation() {
  
   if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
     HTTPClient http;  //Declare an object of class HTTPClient
     http.begin(iss);  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
     if (httpCode > 0) { //Check the returning code
       payload = http.getString();   //Get the request response payload
     
    }
 
    http.end();   //Close connection
 
  }
}

void decodeJson() {
  StaticJsonBuffer<512> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(payload);
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }
  isslat=root["iss_position"]["latitude"];
  isslon=root["iss_position"]["longitude"];
}

void getDistance() {
  float theta, dist, miles;
  theta = mylon - isslon;
  dist = sin(deg2rad(mylat)) * sin(deg2rad(isslat)) + cos(deg2rad(mylat)) * cos(deg2rad(isslat)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  miles = dist * 60 * 1.1515;
  distance = miles;
}

float deg2rad(float n) {
  float radian = (n * 71)/4068;
  return radian;
}

float rad2deg(float n) {
  float degree = (n*4068)/71;
  return degree;
}

void setColor() {
  if (distance <= 1350 && distance >=1201) {colorDisplay(strip.Color(255,0,0),p);}
  if (distance <=1200 && distance >=1151) {colorDisplay(strip.Color(255,153,0),p);} //looks more yellow to me
  if (distance <=1150 && distance >= 951) {colorDisplay(strip.Color(255,255,0),p);} //looks green/yellow to me
  if (distance <=950) {colorDisplay(strip.Color(0, 255, 0), p);}
  if (distance >= 1351) {colorDisplay(strip.Color(0,0,0),p);}
}

void colorDisplay(uint32_t c, uint8_t wait) {

for (int i=0;i<strip.numPixels(); i++) { 
strip.setPixelColor(i, c);

strip.show();
delay(wait);
}
}

