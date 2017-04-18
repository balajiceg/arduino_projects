#include<SoftwareSerial.h>
SoftwareSerial GPRS(2, 3);

int inputPinTempSensor = 0;
float tempCelsius = 0 ;
float thresholdTemp = 45;
String inString = "";    
int i=0;
void setup()
{
  GPRS.begin(9600);               // the GPRS baud rate
  Serial.begin(9600);             // the Serial port of Arduino baud rate.
  delay(500);
}

void loop() {


   while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      i=inString.toInt();
      Serial.println(i);
      inString = "";
    
    switch(i){
      case 1: Serial.println("start call");
               call();
                Serial.println("call requested");
                 delay(10000000000);break;

        case 2: Serial.println("sending sms...");
               sendSMS();
                Serial.println("Sent SMS!");
                 delay(10000000000);break;
    }
    
   }
   }
}



void call() {
//  GPRS.println("AT+CMGF=1");    // Set modem to text mode
//  delay(2000);
//  GPRS.write("AT+CMGS=");      // Start composing message
//  GPRS.write(0x22);            // hex equivalent of double-quote '"'
//  GPRS.write("+918807270640"); // the number to send the SMS to
//  GPRS.write(0x22);
//  GPRS.write(0x0D);            // hex equivalent of Carraige return    
//  GPRS.write(0x0A);            // hex equivalent of newline
//  delay(2000);
//  GPRS.print("I am an idiot");  // Send the text message to the GSM module
//  GPRS.write(0x0D);            // hex equivalent of Carraige return    
//  GPRS.write(0x0A);            // hex equivalent of newline  
//  delay(1000);
//  GPRS.write(26);              // equivalent of CTRL-Z
GPRS.println("ATD+919629116037;"); 
  delay(2000);

}

void sendSMS() {
  GPRS.println("AT+CMGF=1");    // Set modem to text mode
  delay(2000);
  GPRS.write("AT+CMGS=");      // Start composing message
  GPRS.write(0x22);            // hex equivalent of double-quote '"'
  GPRS.write("+919629116037"); // the number to send the SMS to
  GPRS.write(0x22);
  GPRS.write(0x0D);            // hex equivalent of Carraige return    
  GPRS.write(0x0A);            // hex equivalent of newline
  delay(2000);
  GPRS.print("I am an idiot");  // Send the text message to the GSM module
  GPRS.write(0x0D);            // hex equivalent of Carraige return    
  GPRS.write(0x0A);            // hex equivalent of newline  
  delay(1000);
  GPRS.write(26);              // equivalent of CTRL-Z

}
