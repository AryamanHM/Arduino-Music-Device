#include <CapacitiveSensor.h>
#define buzzer 11
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);         
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);     
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);     
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);      
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);         
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);  
CapacitiveSensor   cs_2_10 = CapacitiveSensor(2,10);     
void setup()                    
{
  cs_2_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}
void loop()                    
{
  long s = millis();
  long t1 =  cs_2_3.capacitiveSensor(30);
  long t2 =  cs_2_4.capacitiveSensor(30);
  long t3 =  cs_2_5.capacitiveSensor(30);
  long t4 =  cs_2_6.capacitiveSensor(30);
  long t5 =  cs_2_7.capacitiveSensor(30);
  long t6 =  cs_2_8.capacitiveSensor(30);
  long t7 =  cs_2_9.capacitiveSensor(30);
  long t8 =  cs_2_10.capacitiveSensor(30);
  Serial.print(millis() - s);      
  Serial.print("\t");                   
  Serial.print(t1);                 
  Serial.print("\t");                    
  Serial.print(t2);                  
  Serial.print("\t");                    
  Serial.print(t3);                  
  Serial.print("\t");                    
  Serial.print(t4);                  
  Serial.print("\t");                    
  Serial.print(t5);                 
  Serial.print("\t");                    
  Serial.print(t6);                  
  Serial.print("\t");                    
  Serial.print(t7);                   
  Serial.print("\t");
  Serial.println(t8);                 
  if (t1 > 500) tone(buzzer,131);   
  if (t2 > 500) tone(buzzer,147);  
  if (t3 > 500) tone(buzzer,165);
  if (t4 > 500) tone(buzzer,175);
  if (t5 > 500) tone(buzzer,196);
  if (t6 > 500) tone(buzzer,220);
  if (t7 > 500) tone(buzzer,247);
  if (t8 > 500) tone(buzzer,262);
  if (t1<=500  &  t2<=500  &  t3<=500 & t4<=500  &  t5<=500  &  t6<=500 &  t7<=500 &  t8<=500)
    noTone(buzzer);
delay(10);                            
}
