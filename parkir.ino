/* Saklar Ultrasonic
 *  Dalam percobaan ini kita belajar membuat saklar dengan
 *  Ultrasonic HCR04
 */

#include <NewPing.h> // diperlukan Library Ping Ultrasonic Sensor
 
#define trigger 3 // HCR04 Trigger di pin PB3
#define echo 2 // HCR04 Echo di Pin PB2
#define LedRed 0// Output di Pin PB0
#define LedBlue 1// Output di Pin PB1
#define LedGreen 4// Output di Pin PB1 
#define distance_max 30 /* Menentukan kemampuan Ultra sonic
                             dalam satuan Cm 
                             */
NewPing sonar(trigger, echo, distance_max); 
 
void setup() {
  pinMode(LedRed, OUTPUT);
  pinMode(LedBlue, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  digitalWrite(LedBlue, HIGH);
  digitalWrite(LedRed, HIGH);
  digitalWrite(LedGreen, HIGH);
}
void loop() {
  uint8_t distance = sonar.ping_cm();
 
  if (distance) {
    digitalWrite(LedBlue, HIGH); //PB1 Aktif
    delay(200);
  } else {
    digitalWrite(LedBlue, LOW); //PB1 Off
  }
  delay(1000);
}
