int left_in=12;
int right_in=4;
int Speed=128;

int left_pos=3;
int left_neg=5;
int right_pos=11;
int right_neg=6;
int left_sen;
int right_sen;

void setup() {
  // put your setup code here, to run once:
pinMode(left_pos,OUTPUT);
pinMode(left_neg,OUTPUT);
pinMode(right_pos,OUTPUT);
pinMode(right_neg,OUTPUT);
pinMode(A0,INPUT);
Serial.begin(9600);
}


int check()
 {
int   l_ldr=(analogRead(A0)>analogRead(A1))?HIGH:LOW;
 int r_ldr=(analogRead(A2)>analogRead(A3))?HIGH:LOW;
  if(l_ldr==LOW && r_ldr==LOW)
  return 1;
  else
  return 0;
 }

 int Delay(int a,int i)
 {
  while(check()&&a!=0)
  {
    delay(i);
    a-=i;
  }
 }


void loop() {
   Speed=map(analogRead(A0),0,1023,0,255);
   Serial.print("speed:");
  Serial.println(Speed);
  left_sen=digitalRead(left_in);
  right_sen=digitalRead(right_in);
  Serial.print("left:");
  Serial.println(left_sen);
  Serial.print("right:");
  Serial.println(right_sen);

  // put your main code here, to run repeatedly:
  if(right_sen==HIGH)
  {
    analogWrite(left_pos,Speed);
    digitalWrite(left_neg,LOW);
  }
  else
  {
    digitalWrite(left_pos,LOW);
    digitalWrite(left_neg,LOW);
  }

if(left_sen==HIGH)
  {
    analogWrite(right_pos,Speed);
    digitalWrite(right_neg,LOW);
  }
  else
  {
    digitalWrite(right_pos,LOW);
    digitalWrite(right_neg,LOW);
  }
  /*
 if(left_sen==LOW && right_sen==LOW)
 {int a=0;int i=200;
  while(check())
  {
 analogWrite(left_pos,Speed);
 digitalWrite(left_neg,LOW);
 digitalWrite(right_pos,LOW);
 analogWrite(right_neg,Speed);
 Delay(a,i); 
 if(!check())break;
 a+=i;
 digitalWrite(left_pos,LOW);
 analogWrite(left_neg,Speed);
 analogWrite(right_pos,Speed);
 digitalWrite(right_neg,LOW);
 Delay(a,i);
 a+=i;
  }

 }
 */

  
  
}
