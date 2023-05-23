#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>
#include <OSCMessage.h>

#include "ipconfig.h"
// https://forum.arduino.cc/t/finding-the-mac-address-from-ethernet-shield-w5100/203506
byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // you can find this written on the board of some Arduino Ethernets or shields

EthernetUDP udp;
OSCMessage oscMessage;
//the Arduino's IP
IPAddress ip(SELF_IP);

// port number
const unsigned int inPort = IN_PORT;


void setup() {
  Serial.begin(9600);
  
  Ethernet.begin(mac,ip);
  udp.begin(IN_PORT);
}

void loop() {
  if (udp.parsePacket()) {
    while (udp.available()) {
      // Read the incoming OSC message
      char c = udp.read();
      oscMessage.fill(c);
    }

    // Check if the OSC message is on the "/pwm" address
    if (oscMessage.hasError()) {
      // Invalid or unexpected OSC message
      Serial.println("Invalid or unexpected OSC message");
    } else if (oscMessage.isFloat(0)) {
      // Get the float value from the OSC message
      float value = oscMessage.getFloat(0);

      // Print the received PWM value to the serial monitor
      Serial.print("Received PWM value: ");
      Serial.println(value, 4);  // Print with 4 decimal places
    } else {
      // Invalid data type for the value
      Serial.println("Invalid data type for the PWM value");
    }

    // Clear the OSC message for the next iteration
    oscMessage.empty();
  }
}