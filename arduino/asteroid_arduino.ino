//  From the Open Sound Control (OSC) library for the ESP8266/ESP32
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

#include "Wire.h"
#include <MPU6050_tockn.h>
TwoWire i2c;
MPU6050 mpu6050(i2c);


////////////////////////////////////////////////////////////////////////////////
char ssid[] = "PetitPoney";                
char pass[] = "banane123";            
const IPAddress outIp(192,168,43,80); 
////////////////////////////////////////////////////////////////////////////////


const unsigned int localPort = 8888;  // local port to listen for OSC packets (not used for sending)
const unsigned int outPort = 4559;    // remote port to receive OSC
WiFiUDP Udp;                          // A UDP instance to let us send and receive packets over UDP


void setup() {
    Serial.begin(115200);
    Serial.println("Hello!");

    i2c.begin(D3, D4);
    mpu6050.begin();

    // Connect to WiFi network
    Serial.print("\nConnecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected - IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    Udp.begin(localPort);

    Serial.print("Local port: ");
    Serial.println(Udp.localPort());
    pinMode(D5, INPUT_PULLUP);
}

void loop() {
    // handle IMU
    mpu6050.update();
    Serial.print(mpu6050.getAccX()); Serial.print('\t');
    Serial.print(mpu6050.getAccY()); Serial.print('\t');
    Serial.print(mpu6050.getAccZ()); Serial.print('\t');

    boolean btnPressed = !digitalRead(D5);
    float pressed = btnPressed ? 1 : 0;
    Serial.print(btnPressed); Serial.print('\n');

    // handle OSC
    OSCMessage msg("/IMU");
    msg.add(mpu6050.getAccX());
    msg.add(mpu6050.getAccZ());
    msg.add(pressed);
    Udp.beginPacket(outIp, outPort);
    msg.send(Udp);
    Udp.endPacket();
    msg.empty();
    delay(30);
}
