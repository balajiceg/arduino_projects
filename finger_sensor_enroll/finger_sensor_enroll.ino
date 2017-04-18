/* 
 	FPS_Enroll.ino - Library example for controlling the GT-511C3 Finger Print Scanner (FPS)
 	Created by Josh Hawley, July 23rd 2013
 	Licensed for non-commercial use, must include this license message
 	basically, Feel free to hack away at it, but just give me credit for my work =)
 	TLDR; Wil Wheaton's Law
 */


#include "FPS_GT511C3.h"
#include <LiquidCrystal.h>
#include "SoftwareSerial.h"

// Hardware setup - FPS connected to:
//	  digital pin 10(arduino rx, fps tx)
//	  digital pin 11(arduino tx - 560ohm resistor fps tx - 1000ohm resistor - ground)
//		this brings the 5v tx line down to about 3.2v so we dont fry our fps

FPS_GT511C3 fps(2, 11);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup(){

    lcd.begin(16, 2);   
  Serial.begin(9600);
  delay(100);
  fps.Open();
  fps.SetLED(true);
  
 // Enroll();

// Enroll test
  // find open enroll id
  int enrollid = 0;
  fps.EnrollStart(enrollid);

  // enroll
 lcd.setCursor(0,0);
   lcd.print("Press finger to");
   lcd.setCursor(0,1);
 
   lcd.print("Enroll id:0");

    
  Serial.print("Press finger to Enroll #");
  Serial.println(enrollid);
  while(fps.IsPressFinger() == false) delay(100);
  bool bret = fps.CaptureFinger(true);
  int iret = 0;
  if (bret != false)
  {
    Serial.println("Remove finger");
    lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Remove finger");
    fps.Enroll1(); 
    while(fps.IsPressFinger() == true) delay(100);
   Serial.println("Press same finger again");
   lcd.setCursor(0,0);
   lcd.print("Press again...");
   
    while(fps.IsPressFinger() == false) delay(100);
    bret = fps.CaptureFinger(true);
    if (bret != false)
    {
      Serial.println("Remove finger");
      lcd.clear();
    lcd.setCursor(0,0);
   lcd.print("Remove finger...");
  
      fps.Enroll2();
      while(fps.IsPressFinger() == true) delay(100);
      Serial.println("Press same finger yet again");
      lcd.clear();
    lcd.setCursor(0,0);
   lcd.print("Press yet again...");
   
      while(fps.IsPressFinger() == false) delay(100);
      bret = fps.CaptureFinger(true);
      if (bret != false)
      {
        Serial.println("Remove finger");
        lcd.clear();
        lcd.setCursor(0,0);
   lcd.print("Remove finger...");
        iret = fps.Enroll3();
        if (iret == 0)
        {
          Serial.println("Enrolling Successfull");
          lcd.clear();
          lcd.setCursor(0,0);
   lcd.print("Enrolling Successfull");
        }
        else
        {
          Serial.print("Enrolling Failed with error code:");
          Serial.println(iret);
          lcd.clear();
                    lcd.setCursor(0,0);
   lcd.print("Enrolling failed");
        }
      }
      else 
     {Serial.println("Failed to capture third finger");
     lcd.clear();
        lcd.setCursor(0,0);
   lcd.print("Failed 2 Capture");
    lcd.setCursor(0,1);
    lcd.print("third finger");}
    
    }
    else
    {Serial.println("Failed to capture second finger"); 
    lcd.clear();
       lcd.setCursor(0,0);
   lcd.print("Failed 2 Capture");
    lcd.setCursor(0,1);
    lcd.print("second finger");}
    }
  
  else{
   Serial.println("Failed to capture first finger");
   lcd.clear();
      lcd.print("Failed 2 Capture");
    lcd.setCursor(0,1);
    lcd.print("first finger");}




}

void Enroll(){
  
  }



void loop(){
  delay(100000);
}

