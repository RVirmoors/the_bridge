#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

#include "ipconfig.h"
// https://forum.arduino.cc/t/finding-the-mac-address-from-ethernet-shield-w5100/203506
byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // you can find this written on the board of some Arduino Ethernets or shields

#define TRIG_PIN 2
#define ECHO_PIN 3

long duration;
int distance;

EthernetUDP Udp;
//the Arduino's IP
IPAddress ip(SELF_IP);
//destination IP
IPAddress outIp(HOST_IP);
const unsigned int outPort = HOST_PORT;


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  
  Ethernet.begin(mac,ip);
  Udp.begin(8888);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.017;
  Serial.println(distance);
  
  OSCMessage msg("/distance");
  msg.add(distance);

  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message

  delay(20);
}
