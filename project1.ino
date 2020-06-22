#include <SoftwareSerial.h> // This library allows for seial communication on other digital
                            // pins of the Arduino (rather than just using pins 0 and 1)
                            // note: Arduino UART has a 64 byte serial buffer!
#define DEBUG true
 
SoftwareSerial esp(9,10);    // Arduino Rx is now pin #, Tx, is now pin # 

void setup(){
  Serial.begin(9600);      // Set baud rate of serial data transmission
  esp.begin(9600);         // This baud rate should match the ESP8266 module (may differ)

  ; // Reset module
  transmit("AT+RST\r\n",2000,DEBUG); // Configure ESP8266 as an AP (access point)
  transmit("AT+CWMODE=2\r\n",1000,DEBUG); // Get IP address
  transmit("AT+CIFSR\r\n",1000,DEBUG);
  transmit("AT+CIPMUX=1\r\n",1000,DEBUG); // Configure ESP8266 for multiple connections
  transmit("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // Turn on server on port 80
}

void loop(){
  if(esp.available()){ // Ensure data transmission
    if(esp.find("+IPD,")){
      delay(1000);
      int id = esp.read()-48; // Read() returns ASCII decimal value, 0 starts at 48
      
      // This is what will display on the created webpage (written in HTML)
      // Note: your webpage format should look exactly like the class example
      
      String webpage = "<h1 style=background-color:yellow;>EGCP 565 PROJECT1</h1>";

      // This creates the command that communicates how many bytes are going to be sent over
      String cipsend = "AT+CIPSEND=";
      cipsend += id;
      cipsend += ",";
      cipsend += webpage.length();
      cipsend += "\r\n";

      // Send the command then send webpage display
      transmit(cipsend,1000,DEBUG);
      transmit(webpage,1000,DEBUG);


      // Repeat to display the rest of the webpage output
      webpage =  "<h2>team members</h2>";
      cipsend =  "AT+CIPSEND=";
      cipsend +=id;
      cipsend += ",";
      cipsend += webpage.length();
      cipsend += "\r\n";
      
      transmit(cipsend,1000,DEBUG);
      transmit(webpage,1000,DEBUG);

      webpage =  "<p>NAVYA N <br></p>";
      cipsend =  "AT+CIPSEND=";
      cipsend +=id;
      cipsend += ",";
      cipsend += webpage.length();
      cipsend += "\r\n";
      
      transmit(cipsend,1000,DEBUG);
      transmit(webpage,1000,DEBUG);
      
      webpage =  "<p>Manjushree S <br></p>";
      cipsend =  "AT+CIPSEND=";
      cipsend +=id;
      cipsend += ",";
      cipsend += webpage.length();
      cipsend += "\r\n";
      
      transmit(cipsend,1000,DEBUG);
      transmit(webpage,1000,DEBUG);
      
       webpage =  "<p>Aishwarya K<br></p>";
      cipsend =  "AT+CIPSEND=";
      cipsend +=id;
      cipsend += ",";
      cipsend += webpage.length();
      cipsend += "\r\n";
      
      transmit(cipsend,1000,DEBUG);
      transmit(webpage,1000,DEBUG);

      webpage =  "<p>Vinay TP <br></p>";
      cipsend =  "AT+CIPSEND=";
      cipsend +=id;
      cipsend += ",";
      cipsend += webpage.length();
      cipsend += "\r\n";
      
      transmit(cipsend,1000,DEBUG);
      transmit(webpage,1000,DEBUG);
      

      // Append the connection (you did it right if the browser finishes loading the page)
      String cipclose = "AT+CIPCLOSE="; 
      cipclose += id;
      cipclose += "\r\n";

      transmit(cipclose,3000,DEBUG);
    }
  }
}

// This function will be used to send the appropriate commands to the ESP module
// automatically, rather than manulally inputing them in the serial monitor
String transmit(String esp_command, const int timeout, bool debug)
{
  // declare a string and char variable that will be used to recieve each byte of data
  String response;
  char c;
  esp.print(esp_command); 
  
  long int time = millis();

  while((time+timeout) > millis()){
    while(esp.available()){
      c =esp.read(); 
       response+=c;
    }
   
  }
 
  // Error check
  if(debug){
    Serial.print(response);
  }
  
  return response; 
}
