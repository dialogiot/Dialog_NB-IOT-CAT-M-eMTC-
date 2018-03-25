
//After uploading this code to ideamart devBoard, set the baudrate of serial monitor to 4800 & 'No line ending' to 'Both NL & CR'

#include <SoftwareSerial.h>

// ideaBoard pin configuration
#define ideaBoard_PWRKEY 13
#define ideaBoard_RX 8
#define ideaBoard_TX 7
#define ideaBoard_RST 11

SoftwareSerial ideaSerial(7,8); // RX, TX

void setup() {
    pinMode(ideaBoard_RST, OUTPUT);
  digitalWrite(ideaBoard_RST,LOW); // Default state
    pinMode(ideaBoard_PWRKEY, OUTPUT);
  digitalWrite(ideaBoard_PWRKEY, LOW);
    delay(200);
  digitalWrite(ideaBoard_PWRKEY, HIGH);
    delay(180);
  digitalWrite(ideaBoard_PWRKEY, LOW);
  // Open serial communications and wait for port to open:
  Serial.begin(4800);
  while (!Serial) {
  }
  Serial.println("Hi Developer..! Please type your AT commands");
  ideaSerial.begin(4800);
}

void loop() { // run over and over
  while (ideaSerial.available()) {
    Serial.write(ideaSerial.read());
  }
  while (Serial.available()) {
    ideaSerial.write(Serial.read()); 
  }
 Serial.flush();
}

