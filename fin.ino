#include <Ultrasonic.h>
#include <Servo.h>
Ultrasonic ultrasonic(8, 9);
Servo myservo;
 int mini;
 int uzaklik;
 int enkucukderece;
 int enkucuk;
 int pos = 0;
 void setup() {
  Serial.begin(9600);
   myservo.attach(7);
}

void loop() {
  enkucuk = 200;
  for (int pos = 0; pos <= 180; pos +=5) { // goes from 0 degrees to 180 degrees
    
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(75);   
 uzaklik=ultrasonic.distanceRead();
  if(uzaklik < enkucuk){
    enkucuk= uzaklik;
    enkucukderece=pos;
  }
  }
  myservo.write(enkucukderece);
  delay(1400);
  }

 
  

   // variable to store the servo position
