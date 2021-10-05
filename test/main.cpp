// #include <Arduino.h>
// #include "painlessMesh.h"

// #define MESH_PREFIX "whateverYouLike"
// #define MESH_PASSWORD "somethingSneaky"
// #define MESH_PORT 5555

// Scheduler userScheduler;  // to control your personal task
// painlessMesh mesh;

// // User stub
// void sendMessage();  // Prototype so PlatformIO doesn't complain

// Task taskSendMessage(TASK_SECOND * 1, TASK_FOREVER, &sendMessage);

// void sendMessage() {
//   String msg = "Hello from node ";
//   msg += mesh.getNodeId();
//   mesh.sendBroadcast(msg);
//   taskSendMessage.setInterval(random(TASK_SECOND * 1, TASK_SECOND * 5));
// }

// // Needed for painless library
// void receivedCallback(uint32_t from, String &msg) {
//   Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
// }

// void newConnectionCallback(uint32_t nodeId) {
//   Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
// }

// void changedConnectionCallback() { Serial.printf("Changed connections\n"); }

// void nodeTimeAdjustedCallback(int32_t offset) {
//   Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),
//   offset);
// }

// void setup() {
//   Serial.begin(115200);

//   // mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC |
//   // COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
//   mesh.setDebugMsgTypes(
//       ERROR |
//       STARTUP);  // set before init() so that you can see startup messages

//   mesh.init(MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT);
//   mesh.onReceive(&receivedCallback);
//   mesh.onNewConnection(&newConnectionCallback);
//   mesh.onChangedConnections(&changedConnectionCallback);
//   mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

//   userScheduler.addTask(taskSendMessage);
//   taskSendMessage.enable();
// }

// void loop() {
//   // it will run the user scheduler as well
//   mesh.update();
// }

#include <Arduino.h>
#include <SoftwareSerial.h>

#include "painlessMesh.h"

SoftwareSerial softSerial(5, 4);

void setup() {
  Serial.begin(115200);
  softSerial.begin(115200);

  Serial.println("ok");

  pinMode(2, OUTPUT);
  // softSerial.println("0.0");
}

unsigned long lastTime = 0;

void loop() {
  // if (Serial.available()) {
  //   Serial.write(Serial.read());
  // }

  if (millis() - lastTime >= 100) {
    digitalWrite(2, !digitalRead(2));
    lastTime = millis();
  }

  // if (Serial.available()) {
  //   softSerial.write(Serial.read());
  // }
  // if (softSerial.available()) {
  //   Serial.write(softSerial.read());
  // }
}