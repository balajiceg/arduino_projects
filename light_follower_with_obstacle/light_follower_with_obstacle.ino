#include <Servo.h>

const int trigPin = 4;
const int echoPin =2;

int s=255; //motor default speed
int l_ldr;
int r_ldr;
long duration, inches, cm;
int Distance=20;
int left_pos=3;
int left_neg=5;
int right_pos=6;
int right_neg=11;
int servo_turn_time=1000;

int turn=225;    //turn speed in light searching 
Servo myservo;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(left_pos,OUTPUT);
pinMode(left_neg,OUTPUT);
pinMode(right_pos,OUTPUT);
pinMode(right_neg,OUTPUT);
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  myservo.attach(9);
  myservo.write(90);
  delay(500);
 // chk_dis();
 // chk_dis();
  pinMode(7,INPUT);

}
void reverse(int Speed=s)
{
  analogWrite(left_pos,LOW);
  digitalWrite(left_neg,Speed);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,Speed);
   Serial.println("reverse");
}

void reverse_left(int Speed=s)
{
  analogWrite(left_pos,LOW);
  digitalWrite(left_neg,Speed);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
   Serial.println("reverse_left");
}

void reverse_right(int Speed=s)
{
  analogWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,Speed);
   Serial.println("reverse_right");
}
void forward(int Speed=s)
{
  analogWrite(left_pos,Speed);
  digitalWrite(left_neg,LOW);
  analogWrite(right_pos,Speed);
  digitalWrite(right_neg,LOW);
  Serial.println("forward");
}

void Stop()
{
  digitalWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
 digitalWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
   Serial.println("stop");
  
}
void right(int Speed=s)
{
   analogWrite(left_pos,Speed);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,LOW);
  analogWrite(right_neg,Speed);
   Serial.println("right");
}
void left(int Speed=s)
{
  digitalWrite(left_pos,LOW);
  analogWrite(left_neg,Speed);
  analogWrite(right_pos,Speed);
  digitalWrite(right_neg,LOW);
   Serial.println("left");
}

void d_left(int Speed=s)
{
   analogWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,Speed);
  analogWrite(right_neg,LOW);
  Serial.println("left");
}
void d_right(int Speed=s)
{
  digitalWrite(left_pos,Speed);
  analogWrite(left_neg,LOW);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
   Serial.println("right");
}
long dis()
{
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
 
  duration = pulseIn(echoPin, HIGH);

  cm = duration / 29 / 2;

 Serial.print(cm);
  Serial.print("cm");
 Serial.println();
  return cm;
}

 int Delay(int a,int i)
 {
  while(check()&&a!=0)
  {
    delay(i);
    a-=i;
  }
 }

float chk_dis()
{
  const int x=3;
   float arr[x];
  float tot=0;
  for(int i=0;i<x;i++)
  {
    arr[i]=dis();
    tot+=arr[i];
  }
  int avg=tot/x;
  for(int i=0;i<x;i++)
  {
    if((arr[i]-avg)>2||(arr[i]-avg)<-2)
    return chk_dis();
  } 

  if(arr[0]==0)
  {
    Serial.println("abrupt:");
    Stop();
    return chk_dis();
  }
  Serial.print("verified_dis:");
  Serial.println(arr[0]);
  return arr[0];
}


int check()
 {
  int l_ldr=(analogRead(A0)>analogRead(A1))?HIGH:LOW;
 int r_ldr=(analogRead(A2)>analogRead(A3))?HIGH:LOW;
  if(l_ldr==LOW && r_ldr==LOW)
  return 1;
  else
  return 0;
 }


void loop() {


if(digitalRead(7)==HIGH)
{
//*
float distance=chk_dis();  
if(distance<Distance/4)
{
  reverse();
}
if(distance<Distance/2)
  {int eo=0;
    while(chk_dis()<Distance*3/2)
    {eo++;
      if(eo%2==0)
      {
        reverse_left();delay(100);
      }
      else
      {
         reverse_right();delay(100);
      }
    }
  }
   else if(distance<Distance)
    {
      Serial.println("less distance");
      Stop();
      myservo.write(0);
      delay(servo_turn_time);
      if(chk_dis()>Distance)
      {Serial.println("right clear");
         myservo.write(90);delay(servo_turn_time);
        while(chk_dis()<Distance)
        {
          right(turn);delay(500);
        }
      }
      else
        {
           myservo.write(180);delay(servo_turn_time);
           if(chk_dis()>Distance)
            {Serial.println("left clear");
               myservo.write(90);delay(servo_turn_time);
                while(chk_dis()<Distance)
                {
                  left(turn);
                  delay(500);
                }
            }
            else
            {myservo.write(90);delay(servo_turn_time);
                 while(chk_dis()<Distance)
                {
                  left(150);
                  delay(500);
                }
            }
        }
    }
    
//  else 
//    forward(255);
//   }


else
{
  l_ldr=(analogRead(A0)>analogRead(A1))?HIGH:LOW;
  r_ldr=(analogRead(A2)>analogRead(A3))?HIGH:LOW;
  Serial.print("l:");Serial.print(l_ldr);
  Serial.print("  r:");Serial.println(r_ldr);
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  if(l_ldr==HIGH&&r_ldr==HIGH)forward();
  else if(l_ldr==LOW&&r_ldr==HIGH)d_right();
  else if(l_ldr==HIGH&&r_ldr==LOW)d_left();
    /*else  if(l_ldr==LOW && r_ldr==LOW)     //search
     {int a=0;int i=200;
      while(check())
      {
       left();
       Delay(a,i); 
       if(!check())break;
       a+=i;
       right();
       Delay(a,i);
       a+=i;
      }
    
     }*/    //search
  else Stop();
}//  comment

}
 }
 
 


