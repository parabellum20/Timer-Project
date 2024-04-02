Timer Project 

Issues with schematic :
The gnd is on top end and MISO is next to VCC.

*Connections* :
For time set and Program :

1. Connect MOSI to pin11
2. Connect SCK to pin13
3. Connect MISO to pin 12
4. Connect Reset to pin 10
5. Connect VCC to 5v
6. Connect gnd to gnd of arduino

Final :
1. Connect  MOSI and SDA 
2. Connect SCK and SCL

For Serial Read  :
Same connections as final along with TX connected to RX of arduino







*Program uploading* :
First change the time in timeset program with 2 minutes buffer to account for uplaoding time delays.
Connect according the timeset and program connections.
1. File<Examples<ArduinoISP<ArduinoISP  Now run the program choosing arduino uno as the connected device.
2. Now Open the Timeset program, Tools<Board<attiny/attiny25/45/85 
3. First check if the program compiles
4. Now sketch<upload using programmer . 

Once done ,
Open the main program and do the same steps as above . Once uploading is done , connect SDA and MOSI with one jumper, then SCL and SCK with another jumper.


Serial Read (Checking time) :
Now change Board to arduino Uno , and upload serial read program .
To check the time , connect Rx and Tx to Tx and Rx of RTC according to whatsapp image.(Connect only after uploading the code). Then Open the serial monitor to check the time . 


