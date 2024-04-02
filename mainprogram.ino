#include <TinyWireM.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(1, 3);  // RX (pin 1) and TX (pin 3) for software serial


void setup() {
  pinMode(4, OUTPUT);
  TinyWireM.begin();     // Initialize I2C communication
  mySerial.begin(9600);  // Initialize software serial for communication

  // Set the DS3231 to start the timekeeping (if necessary)
  // Uncomment the next three lines if your DS3231 is not already running
  // TinyWireM.beginTransmission(0x68);
  // TinyWireM.send(0x00);  // Control register address
  // TinyWireM.send(0x00);  // Start the DS3231
  // TinyWireM.endTransmission();

  // setDS3231Time();
  


}

void loop() {
  // Read time data from DS3231
  TinyWireM.beginTransmission(0x68);
  TinyWireM.send(0x00);  // Point to the seconds register
  TinyWireM.endTransmission();

  TinyWireM.requestFrom(0x68, 7);  // Request 7 bytes (seconds, minutes, hours, day, date, month, year)

  if (TinyWireM.available() >= 7) {
    seconds = bcdToDec(TinyWireM.receive() & 0x7F);  // Remove the CH bit (Clock Halt) if set
    minutes = bcdToDec(TinyWireM.receive());
    hours = bcdToDec(TinyWireM.receive());
    dayOfWeek = bcdToDec(TinyWireM.receive());
    dayOfMonth = bcdToDec(TinyWireM.receive());
    month = bcdToDec(TinyWireM.receive());
    year = bcdToDec(TinyWireM.receive());
  }
  mySerial.println(int(minutes));
  mySerial.println(int(hours));

  if (int(hours) >= 18 || int(hours) <= 5) {
    digitalWrite(4, HIGH);

  } else {
    digitalWrite(4, LOW);
  }
}

byte bcdToDec(byte value) {
  // Convert binary-coded decimal (BCD) to decimal
  return ((value / 16) * 10 + (value % 16));
}

byte decToBcd(byte value) {
  // Convert decimal to binary-coded decimal (BCD)
  return ((value / 10 * 16) + (value % 10));
}