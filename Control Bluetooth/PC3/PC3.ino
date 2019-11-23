#include <Servo.h>
Servo myservo;
int x;
int cantidad = 0;
void setup()
{
 Serial.begin(9600);
 myservo.attach(9);
  myservo.write(0);
}
void loop()
{
  
 x = Serial.read();
 if(x=='A') 
      {
          if(cantidad==0) 
          {
              cantidad= cantidad+45;
              myservo.write(cantidad);
          }
          else if(cantidad<136)
          {
             cantidad= cantidad+45;
             myservo.write(cantidad);
          }
          else
          {
            myservo.write(cantidad);  
          }
            
      }
 if(x=='B')
 {
           if(cantidad<44) 
          {
              myservo.write(cantidad);
          }
          else if(cantidad<181)
          {
             cantidad = cantidad-45;
             myservo.write(cantidad);
          }
          else
          {
            myservo.write(cantidad);  
          } 
 }


 
         /*if(x=='c') myservo.write(60);
         if(x=='d') myservo.write(90);
         if(x=='e') myservo.write(120);
         if(x=='f') myservo.write(150);
         if(x=='g') myservo.write(180);*/
}
