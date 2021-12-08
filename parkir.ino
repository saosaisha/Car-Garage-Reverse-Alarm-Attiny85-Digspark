/* Saklar Ultrasonic
    Dalam percobaan ini kita belajar membuat saklar dengan
    Ultrasonic HCR04
   Bila terjadi Hang, biarkan selama 1 menit
   https://www.youtube.com/c/Radal05
   8 Desember 2021
*/

#include <NewPing.h> // diperlukan Library Ping Ultrasonic Sensor

#define trigger 3  // HCR04 Trigger di pin PB3
#define echo 2     // HCR04 Echo di Pin PB2

#define buzzer 4 // Output di Pin PB0
#define ledBlue 0  // Output di Pin PB1
#define ledRed 1   // Output di Pin PB4 
#define distance_max 20 /* Menentukan kemampuan Ultra sonic
                             dalam satuan Cm 
                             maksimim 4,5 M
*/

NewPing sonar(trigger, echo, distance_max);

void setup() {
  
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  analogWrite(buzzer, LOW);
  analogWrite(trigger, LOW);
  
}

void loop() {
  uint8_t distance = sonar.ping_cm();// Membaca jarak pantulan

  if (distance) {
    if (distance < 5) { // Bila mencapai jarak Minimum 5Cm
      digitalWrite(ledBlue, LOW);
      digitalWrite(ledRed, LOW);
    } else
      digitalWrite(ledBlue, HIGH);// Mulai pembacaan ada benda pada jarak mak
    digitalWrite(ledRed, LOW);
    analogWrite(buzzer, 500); // Nyalakan Buzzer
    delay(distance * 10);

  } else {
    digitalWrite(ledRed, HIGH);//Keadaan normal, tidak ada benda penghalang
    digitalWrite(ledBlue, LOW);

  }
  analogWrite(buzzer, LOW);//Matikan Buzzer
  delay(distance * 10);
}
