int incomingByte = 0;   // for incoming serial data
int flushMessageIndex = 0;
int flushMessage = -128;

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.write(incomingByte);
  }
  /*
   * once in a while send a -128 ->
   * to prevent listening program being stuck at read
   */
  flushMessageIndex++;
  if(flushMessageIndex == 100000) {
   flushMessageIndex = 0;
   Serial.write(flushMessage);
  }

}
