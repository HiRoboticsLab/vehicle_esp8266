#include <Arduino.h>
#include <SoftwareSerial.h>
#include <painlessMesh.h>

#define MESH_PREFIX "whateverYouLike"
#define MESH_PASSWORD "somethingSneaky"
#define MESH_PORT 5555

Scheduler userScheduler;
painlessMesh mesh;

SoftwareSerial softSerial(5, 4);

void setup() {
  Serial.begin(115200);
  softSerial.begin(115200);

  // 开启wifimesh
  mesh.setDebugMsgTypes(ERROR | STARTUP | MESH_STATUS);
  mesh.init(MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT);

  pinMode(2, OUTPUT);
}

String cmd = "";
unsigned long lastTime = 0;

void loop() {
  mesh.update();

  if (millis() - lastTime >= 100) {
    digitalWrite(2, !digitalRead(2));
    lastTime = millis();
  }

  if (softSerial.available()) {
    char temp = char(softSerial.read());
    cmd += temp;
    if (temp == '\n') {
      mesh.sendBroadcast(cmd);
      Serial.write(softSerial.read());
      cmd = "";
    }
  }
}
