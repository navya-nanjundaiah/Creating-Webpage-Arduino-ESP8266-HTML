# Creating-Webpage-With-Arduino-ESP8266-HTML
As an Assignment project we had to create a Webpage using HTML , Arduino, ESP8266 (WI-FI module)
## Components Required
- Arduino Microcontroller
- Type-B USB cable
- ESP8266 Wi-Fi Module
- Breadboard
- Breadboard Power Supply Module
- Jumper Wires
- Wall Wart Power Supply (9v, 1A)
## Steps involved 
- Place breadboard power supply module onto breadboard a small yellow jumper is connecting the "off" and "3.3v" pins. 
- Connect the VCC pin and GND pin of the ESP module to the "+" and "-" rail of the bread board
- Connect the TX of the ESP module to the TX of the Arduino and the RX of the ESP module to the RX of the Arduino. 
- In the Arduino IDE, open the serial monitor andtype in the "AT" command. 
- If everything is working correctly you should have a response of "OK". 
- Once this is done, find out what your SSID is and change the name if you want.
- Connect the TX and RX to the appropriate ports on the Arduino 
- Connect the ground pin of the Arduino to the "-" rail of the breadboard.
- Load the code onto the Arduino using the Type-B USB cable
- Connect a jumper wire between the Vin pin of the Arduino and the "+" rail of the breadboard
- Open the serial monitor on the Arduino IDE. 
- Copy the IP address that is displayed on the serial monitor
- Connect laptop to the Wi-Fi network that the ESP module is broadcasting
- Open internet browser and paste the IP address in the search bar
- Hit enter and the web page created should appear
