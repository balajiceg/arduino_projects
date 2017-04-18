
int Speed=HIGH;

int left_pos=3;
int left_neg=5;
int right_pos=6;
int right_neg=11;

int turn;
void setup() {
  // put your setup code here, to run once:
Serial.begin(250000);
Serial.write('1'); 
pinMode(left_pos,OUTPUT);
pinMode(left_neg,OUTPUT);
pinMode(right_pos,OUTPUT);
pinMode(right_neg,OUTPUT);

digitalWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
}
void forward()
{
  digitalWrite(left_pos,Speed);
  digitalWrite(left_neg,LOW);
  analogWrite(right_pos,Speed);
  digitalWrite(right_neg,LOW);
}

void reverse()
{
  analogWrite(left_pos,LOW);
  digitalWrite(left_neg,Speed);
  analogWrite(right_pos,LOW);
  digitalWrite(right_neg,Speed);
}

void Stop()
{
  digitalWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
 digitalWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
}
void left()
{
   analogWrite(left_pos,Speed);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,LOW);
  analogWrite(right_neg,Speed);
}
void right()
{
  digitalWrite(left_pos,LOW);
  analogWrite(left_neg,Speed);
  analogWrite(right_pos,Speed);
  digitalWrite(right_neg,LOW);
}
String a;int i;
void loop() {
  // put your main code here, to run repeatedly:
  String inString;
 while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar))inString += (char)inChar;
    if (inChar == ' ') 
      {
        Serial.println(inString.toInt());
    i=inString.toInt();
      inString = "";}
    
switch(i)
{
  case 0:Stop();break;
  case 1:forward();break;
  case 2:reverse();break;
  case 3:left();break;
  case 4:right();break;
  default:Speed=i;
}
 }
}
 
 
 


