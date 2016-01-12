 int SwitchControl1 = 2; //Define each relay switch with its corresponding digital output from arduino
 int SwitchControl2 = 3; 
 int SwitchControl3 = 4; 
 int SwitchControl4 = 5; 
 int SwitchControl5 = 6; 
 int SwitchControl6 = 7;
 int SwitchControl7 = 8;
 int SwitchControl8 = 9;
 int sensorValue1; //Declaration of each sensor value for arduino voltmeter
 int sensorValue2;
 int sensorValue3;
 int sensorValue4;
 int BattA = 4; //BattA: +12 either 3 or 4
 int BattB = 1; //BattB: -12 either 1 or 2
 
void setup() //setup for void loop
{
  Serial.begin(9600);
  pinMode(SwitchControl1, OUTPUT); //Declare each ardunio digital out an output to apply 5v to switch each relay
  pinMode(SwitchControl2, OUTPUT);
  pinMode(SwitchControl3, OUTPUT);
  pinMode(SwitchControl4, OUTPUT);
  pinMode(SwitchControl5, OUTPUT); 
  pinMode(SwitchControl6, OUTPUT);
  pinMode(SwitchControl7, OUTPUT);
  pinMode(SwitchControl8, OUTPUT);
} //END void setup()

void loop() //Main loop starts here (will run forever)
{
  float voltage1 = 0; //Set each voltage to start at zero (Not necessary)
  float voltage2 = 0;
  float voltage3 = 0;
  float voltage4 = 0;
  
  //Initial switch configuration before any voltages are measured.
  
  digitalWrite(SwitchControl1, LOW); //discharge v4
  //delay(1000); //pause for 1 second (1000 miliseconds)
  digitalWrite(SwitchControl2, LOW); //discharge v4
  //delay(1000);
  digitalWrite(SwitchControl3, HIGH); //charge v3
  //delay(1000);
  digitalWrite(SwitchControl4, HIGH); //charge v3
  //delay(1000);
  digitalWrite(SwitchControl6, HIGH); //charge v2
  //delay(1000);
  digitalWrite(SwitchControl5, HIGH); //charge v2
  //delay(1000);
  digitalWrite(SwitchControl7, LOW); //discharge v1
  //delay(1000);
  digitalWrite(SwitchControl8, LOW); //discharge v1
  
  //Battery 1 = v1, Battery 2 = v2,...
  //First two sub-loops control -12v output side of power supply.
  //Second two sub-loops control 12v output side of power supply.

while(1){  
  sensorValue1 = analogRead(A0); //Read the voltage accross arduino analog A0
  voltage1 = (sensorValue1 * (308.47 / 1023.0))-14.754; //Scale the reading of voltage1 according to voltage divider circuit on arduino.
  Serial.println("Battery -"); 
  Serial.println(voltage1);
  
if(voltage1 < -12.5){
  //Do nothing
} //END if
  else {
  if(BattB == 1){ 
     BattB = 2;
     digitalWrite(SwitchControl8, HIGH); //charge v1
     //delay(1000);
     digitalWrite(SwitchControl7, HIGH); //charge v1
     //delay(1000);
     digitalWrite(SwitchControl5, LOW); //discharge v2
     //delay(1000);
     digitalWrite(SwitchControl6, LOW); //discharge v2
     Serial.println("BattB = 2");
  } //END if
     else{
     if(BattB == 2){
       BattB = 1;    
       digitalWrite(SwitchControl6, HIGH);//charge v2
       //delay(1000);
       digitalWrite(SwitchControl5, HIGH); //charge v2
       //delay(1000);
       digitalWrite(SwitchControl7, LOW); //discharge v1
       //delay(1000);
       digitalWrite(SwitchControl8, LOW); //discharge v1
       Serial.println("BattB = 1");
     } //END if
     } //END else
  } //END if
  
  sensorValue4 = analogRead(A3); //Read the voltage accross arduino analog A3
  voltage4 = sensorValue4 * (55.545/ 1023.0); //Scale the reading of voltage4 according to voltage divider circuit on arduino.
  Serial.println("Battery +");
  Serial.println(voltage4);

if(voltage4 > 12.5){
  //Do nothing
} //END if
  else {
  if(BattA == 4){ 
     BattA = 3;
     digitalWrite(SwitchControl2, HIGH); //charge v4
     //delay(1000);
     digitalWrite(SwitchControl1, HIGH); //charge v4
     //delay(1000);
     digitalWrite(SwitchControl4, LOW); //discharge v3
     //delay(1000);
     digitalWrite(SwitchControl3, LOW); //discharge v3 
     Serial.println("BattB = 3");
  } //END if 
     else{
     if(BattA == 3){
       BattA = 4;    
        digitalWrite(SwitchControl1, LOW); //discharge v4
        //delay(1000);
        digitalWrite(SwitchControl2, LOW); //discharge v4
        //delay(1000);
        digitalWrite(SwitchControl3, HIGH); //charge v3
        //delay(1000);
        digitalWrite(SwitchControl4, HIGH); //charge v3
        Serial.println("BattB = 4");
     } //END if
     } //END else
  } //END if
 
delay(5000); //Delay for 5 sec (1 hr = 3600000 millisec)
} //END while loop
} //END void loop
 
 
 
 