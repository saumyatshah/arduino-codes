
#include <math.h>
//#define PI 3.141592654
 
const int triggerpin1 = 11;     
const int echopin1 = 10; 
const int triggerpin2 = 9;     
const int echopin2 = 8;        
long time1,time2;
const int mot11 = 6;
const int mot12 = 7;

const int mot21 = 5;
const int mot22 = 4;

const int mot31 = 3;
const int mot32 = 2;

int pos;//servo motor position(dustbin lid)
int len_dustbin=30;//120 cm length of dustbin

//Servo servo_1;
void open()
{
  digitalWrite(mot11,HIGH);
  digitalWrite(mot12,LOW);
  delay(1000);
}
void close()
{
  digitalWrite(mot12,HIGH);
  digitalWrite(mot11,LOW);
}

void forward()
{
  digitalWrite(mot22,HIGH);
  digitalWrite(mot21,LOW);

  digitalWrite(mot32,HIGH);
  digitalWrite(mot31,LOW);
}


void backward()
{
  digitalWrite(mot21,HIGH);
  digitalWrite(mot22,LOW);

  digitalWrite(mot31,HIGH);
  digitalWrite(mot32,LOW);
}

void right()
{
  digitalWrite(mot21,HIGH);
  digitalWrite(mot22,LOW);

  digitalWrite(mot31,HIGH);
  digitalWrite(mot32,LOW);
}

void left()
{
  digitalWrite(mot21,HIGH);
  digitalWrite(mot22,LOW);

  digitalWrite(mot31,HIGH);
  digitalWrite(mot32,LOW);
}

void stop()
{
  digitalWrite(mot21,HIGH);
  digitalWrite(mot22,LOW);

  digitalWrite(mot31,HIGH);
  digitalWrite(mot32,LOW);
}

void setup() 
{  

pinMode(triggerpin1, OUTPUT);  
pinMode(echopin1, INPUT);
pinMode(triggerpin2, OUTPUT);  
pinMode(echopin2, INPUT);  
pinMode(mot11, OUTPUT);
pinMode(mot12, OUTPUT);
pinMode(mot21, OUTPUT);
pinMode(mot22, OUTPUT);
pinMode(mot31, OUTPUT);
pinMode(mot32, OUTPUT);

Serial.begin(115200); 
//servo_1.attach(8);   
//servo_1.write(0);
close();
}

void loop() 
{
digitalWrite(triggerpin1, LOW);  
delayMicroseconds(2);
digitalWrite(triggerpin1, HIGH); 
delayMicroseconds(10);
digitalWrite(triggerpin1, LOW);
time1 = pulseIn(echopin1, HIGH); 
digitalWrite(triggerpin2, LOW);  
delayMicroseconds(2);
digitalWrite(triggerpin2, HIGH); 
delayMicroseconds(10);
digitalWrite(triggerpin2, LOW);
time2 = pulseIn(echopin2, HIGH);
  
int distance = time1*0.034/2;//object distance from dustbin             
float waste_height = (time2*0.034/2);//height of waste from ground
//int waste_percentage = (waste_height/len_dustbin)*100;//waste percentage according to height in dustbin 
Serial.println(distance);
//Serial.println(waste_height);

 if(distance<=50){
    open();
    
    delay(3000);
  }
  else if(distance>=50){
    close();
    delay(500);
  }
  if(waste_height<30)
  {
    //Serial.println("Please empty the bin");
    Serial.write((int)waste_height);
  }
Serial.println(Serial.read());
  if(Serial.read()==2)
  {
    
    forward();
  }
  else if(Serial.read()==1)
  {
    backward();
  }
  else if (Serial.read()==4)
  {
    right();
  }
  else if (Serial.read()==3)
  {
    left();
  }
  else if(Serial.read()==0)
  {
    stop();
  }
}
