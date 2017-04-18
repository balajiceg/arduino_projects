

#include "LiquidCrystal.h" //for the screen
#include "FPS_GT511C3.h" //the fps (fingerprint scanner) library
#include "SoftwareSerial.h" //used by fps library
#include <Servo.h>
//Setting up the pins for the LCD and the fps
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //pinouts for LCD
FPS_GT511C3 fps(2, 11); //RX, TX
Servo servo; 

int i=0;
boolean isFinger = false; //true if the fps detects a finger on the scanner

//output pins


const int attinyPin = 13;
const String idNames[] = 
{
  "Aman","Bro", "Ryan", "Mom", "Dad", "Auntie", "Grandma", "Zeide", "person", "person", "Thumb"};

void setup(){
  //set outputs
  

  pinMode(attinyPin, OUTPUT);
 servo.attach(3);
  //for debugging
  Serial.begin(9600);
  fps.UseSerialDebug = false; //set to true for fps debugging through serial

  //initializing the libraries
  lcd.begin(16,2);
  
  fps.Open();
  fps.SetLED(true); //the fps LED
  //boot up sound
 
  //print starting message
  lcd.print("Put your finger "); //the command to print to the LCD
  lcd.setCursor(0, 1); //sets the cursor to the 0th column in the 1st row
  lcd.print(" on the scanner ");
  delay(150);
 

}
void loop(){
  //scan and identify the finger when one is put on it
  waitForFinger();

  lcd.clear(); //clears the screen and sets the cursor to 0,0
  fps.CaptureFinger(false); //captures the finger for identification
  int id = fps.Identify1_N(); //identifies print and stores the id

  if(id <= 10){
    lcd.print(" Access granted "); //success message
    lcd.setCursor(0,1);

  if(i==0){
    //prints name when the garage is opening 
    String message = "  Hey " + idNames[id] + "!";
    lcd.print(message);

    digitalWrite(13,HIGH);
    servo.write(90);
    i=1;
    delay(2000);
  }
  else
  {
     String message = "  Bye " + idNames[id] + "!";
    lcd.print(message);

    digitalWrite(13,LOW);
    servo.write(0);
    i=0;
    delay(2000);
  }
    

  }

  else{
    lcd.print("Fingerprint is"); //if print isn't recognized
    lcd.setCursor(0,1);
    lcd.print("   unverified   ");
    delay(2000);
    lcd.clear();
    lcd.print("Please try again");
    lcd.setCursor(0,1);
    lcd.print("Use your pointer"); //I scanned everyone's pointer finger
    delay(500);
  }
  delay(250);
}



void waitForFinger(){
  static int timer; //contains timeout counter
  timer = 0; //resets the timer everytime this function starts
  while(!fps.IsPressFinger()){ //timeout of eight seconds
    timer++;
    delay(100); 
    if (timer>=80 && !fps.IsPressFinger()){
     
    }
  } 
  timer = 0; //resets the timer everytime this function ends
}

String centerText(String s) { //centers text on the LCD to look better
  while(16-s.length()>1){ //if the text needs to be centered
    s = " " + s + " "; //creates space on both sides evenly
  }
  return s;
}





