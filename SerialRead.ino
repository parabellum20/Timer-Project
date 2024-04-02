#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX (pin 2) and TX (pin 3) on Arduino (adjust pins as needed)

void setup() {
  Serial.begin(9600); // Initialize hardware serial for communication with the computer
  mySerial.begin(9600); // Initialize software serial for communication with the ATtiny
}

void loop() {
  // Read data from ATtiny and send it to the computer
  while (mySerial.available()) {
    char data = mySerial.read();
    Serial.print(data); // Send data to the computer
  }
}