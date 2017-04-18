

int s=0; //motor default speed
int t=0; //delaf before turn
int left_pos=5;
int left_neg=3;
int right_pos=6;
int right_neg=11;
int s0,s1,s2,s3,s4,s5,s6;
void check()
{

   s5=(digitalRead(7)==HIGH)?LOW:HIGH;Serial.print(s5);
  s0=digitalRead(A0); Serial.print(s0);
// s1=digitalRead(A1);Serial.print(s1);
 s2=digitalRead(A2);Serial.print(s2);
 //s3=digitalRead(A3);Serial.print();
 s4=digitalRead(A4);Serial.print(s4);

 s6=(digitalRead(8)==HIGH)?LOW:HIGH;Serial.print(s6);
 Serial.println();
}


void reverse(int Speed=s)
{
  analogWrite(left_pos,LOW);
  digitalWrite(left_neg,Speed);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,Speed);
   
}

void reverse_left(int Speed=s)
{
  analogWrite(left_pos,LOW);
  digitalWrite(left_neg,Speed);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
   
}

void reverse_right(int Speed=s)
{
  analogWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,Speed);
   
}
void forward(int Speed=s)
{
  analogWrite(left_pos,Speed);
  digitalWrite(left_neg,LOW);
  analogWrite(right_pos,Speed);
  digitalWrite(right_neg,LOW);
  Serial.println("forward...");
}

void Stop()
{
  digitalWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
 digitalWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
    
}
void right(int Speed=s)
{
   analogWrite(left_pos,Speed);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,LOW);
  analogWrite(right_neg,Speed);
  Serial.println("right...");
}
void left(int Speed=s)
{
  digitalWrite(left_pos,LOW);
  analogWrite(left_neg,Speed);
  analogWrite(right_pos,Speed);
  digitalWrite(right_neg,LOW);
  Serial.println("left...");
  
}

void d_left(int Speed=s)
{
   analogWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,Speed);
  analogWrite(right_neg,LOW);
  
}
void d_right(int Speed=s)
{
  digitalWrite(left_pos,Speed);
  analogWrite(left_neg,LOW);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
  
}



void setup() {
  // put your setup code here, to run once:


pinMode(left_pos,OUTPUT);
pinMode(left_neg,OUTPUT);
pinMode(right_pos,OUTPUT);
pinMode(right_neg,OUTPUT);

  pinMode(A0,INPUT);
 // pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
 // pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);
}


void loop()

{
  s=analogRead(A5);
  s = map(s, 0, 1023, 0, 255); 
  
  check();
  
  if(s0==0 && s2==1 && s4==0)
  {
    forward();
  }

 else if(s5==1&&s2==1&&s6==0)
  {
   left();
   delay(1000);
  }
  else if(s5==0&&s2==1&&s6==1)
  {
   right();
   delay(1000);
  }
 
  
  else if(s0==1 && s2==0 && s4==0)
  {delay(t);
    left();
   
  }
  
  else if(s0==0 && s2==0 && s4==1)
  {delay(t);
    right();
   
  }

//
//  else if(s0==1 && s2==1 && s4==0)
//  {delay(t);
//    left();
//  
//  }
//  
//  else if(s0==0 && s2==1 && s4==1)
//  {delay(t);
//    right();
//   
//  }


  
  
  
 


 }
 
 


