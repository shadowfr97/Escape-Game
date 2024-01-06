int Solenoid = 3;    //define digital port3
 void setup()  
 {        
  pinMode(Solenoid, OUTPUT);  //set Solenoid as OUTPUT
}
 void loop()                     
{
  analogWrite(Solenoid, 250);
  

  
}
