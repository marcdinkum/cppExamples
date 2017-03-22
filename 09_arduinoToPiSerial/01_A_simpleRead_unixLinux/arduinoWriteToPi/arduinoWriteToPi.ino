char value;

void setup() {
  ampValue = 0;
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  writeSerial();
}

//WriteSerial//-------------------------------------------------
//function for sending serial data
void writeSerial()
{  
  for(int i = -128; i <= 127; i++) {
    Serial.write(i);    
    delay(1);            
  }
}
