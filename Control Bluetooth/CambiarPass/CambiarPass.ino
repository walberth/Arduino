#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); // RX | TX

char c = ' ';
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR in the serial monitor");
 
    BTserial.begin(38400);  
}
 
void loop()
{
 
    if (BTserial.available())
    {  
        c = BTserial.read();
        Serial.write(c);
    }
 
   if (Serial.available())
    {
        c =  Serial.read();
        BTserial.write(c);  
    }
 
}
