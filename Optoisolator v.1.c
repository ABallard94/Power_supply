int SwitchControl1 = 2; //Controls Switch one (D0)
int SwitchControl2 = 3; //(D1)
int SwitchControl3 = 4; //(D2)
int SwitchControl4 = 5; //(D3)
int SwitchControl5 = 13; //(LED)

void setup()
{
  Serial.begin(9600);
  pinMode(SwitchControl1, OUTPUT); //Declare Dig pin as a voltage output
  pinMode(SwitchControl2, OUTPUT);
  pinMode(SwitchControl3, OUTPUT);
  pinMode(SwitchControl4, OUTPUT);
  pinMode(SwitchControl5, OUTPUT);
} //End void setup 

void loop(){
digitalWrite(SwitchControl1, LOW); 
digitalWrite(SwitchControl2, HIGH);
digitalWrite(SwitchControl5, HIGH); 

delay(5000);

digitalWrite(SwitchControl1, LOW); 
digitalWrite(SwitchControl2, LOW);
digitalWrite(SwitchControl5, LOW);

delay(5000);

digitalWrite(SwitchControl1, HIGH); 
digitalWrite(SwitchControl2, LOW);
digitalWrite(SwitchControl5, HIGH);

delay(5000);

digitalWrite(SwitchControl1, LOW); 
digitalWrite(SwitchControl2, LOW);
digitalWrite(SwitchControl5, LOW);

delay(5000);

} //End void loop