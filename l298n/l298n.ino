
int left_pos=3;
int left_neg=5;
int right_pos=6;
int right_neg=11;

int turn;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.write("ready"); 
pinMode(left_pos,OUTPUT);
pinMode(left_neg,OUTPUT);
pinMode(right_pos,OUTPUT);
pinMode(right_neg,OUTPUT);

}
void forward()
{
  digitalWrite(left_pos,HIGH);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,HIGH);
  digitalWrite(right_neg,LOW);
}

void reverse()
{
  digitalWrite(left_pos,LOW);
  digitalWrite(left_neg,HIGH);
  digitalWrite(right_pos,LOW);
  digitalWrite(right_neg,HIGH);
}

void Stop()
{
  digitalWrite(left_pos,LOW);
  digitalWrite(left_neg,LOW);
 digitalWrite(right_pos,LOW);
  digitalWrite(right_neg,LOW);
}
void left()
{Serial.println("left");
   digitalWrite(left_pos,HIGH);
  digitalWrite(left_neg,LOW);
  digitalWrite(right_pos,LOW);
  digitalWrite(right_neg,HIGH);
}
void right()
{
  digitalWrite(left_pos,LOW);
  digitalWrite(left_neg,HIGH);
  digitalWrite(right_pos,HIGH);
  digitalWrite(right_neg,LOW);
}
String a;int i; String inString;
void loop() {
  // put your main code here, to run repeatedly:
 


  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == ' ') {
    
      Serial.println(inString.toInt());
  i=inString.toInt();
      // clear the string for new input:
      inString = "";
    }
    
switch(i)
{
  case 0:Stop();break;
  case 1:forward();break;
  case 2:reverse();break;
  case 3:left();break;
  case 4:right();break;

}
 }
}
 
 
 


