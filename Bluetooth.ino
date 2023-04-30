#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(3, 4);  // RX, TX


Servo servo1;
Servo servo2;

int s1Vel = 15;
int s2Vel = 25;

int index = 0;
int velG = 25;
int s1Act, s2Act;
int s1Ant, s2Ant;
int s1[50], s2[50];


String btS,bt ;
void setup() {
  Serial.begin(115200);
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(10);
  servo1.attach(5, 510, 1200);
  servo2.attach(11, 650, 1400);

  pinMode(13, OUTPUT);


  s1Ant = 90;

  servo1.write(s1Ant);
  s2Ant = 100;
  
  delay(50);
}

void loop() {

  if (Bluetooth.available() > 0) {
    Serial.println("Connected");
    bt = Bluetooth.readString();
    Serial.println(bt);
    Serial.println(bt);
    if (bt.startsWith("s1")) {
      btS = bt.substring(2, bt.length());
      s1Act = btS.toInt();

      if (s1Ant > s1Act) {
        for (int j = s1Ant; j >= s1Act; j--) {
          servo1.write(j);
          delay(s1Vel);
        }
      } else {
        for (int j = s1Ant; j <= s1Act; j++) {
          servo1.write(j);
          delay(s1Vel);
        }
      }

      s1Ant = s1Act;
    }

    if (bt == '1') {
      digitalWrite(13, HIGH);
      delay(1);
    } else if (bt == '0') {
      digitalWrite(13, LOW);
      delay(1);
    }

    if (bt.startsWith("s2")) {
      btS = bt.substring(2, bt.length());
      s2Act = btS.toInt();
      Serial.println(s2Act);
      if (s2Ant > s2Act) {
        for (int j = s2Ant; j >= s2Act; j--) {
          servo2.write(j);
          servo3.write(180 - j);
          delay(s2Vel);
        }
      } else {
        for (int j = s2Ant; j <= s2Act; j++) {
          servo2.write(j);
          servo3.write(180 - j);
          delay(s2Vel);
        }
      }

      s2Ant = s2Act;
    }


    if (bt.startsWith("SAVE")) {
      s1[index] = s1Ant;
      s2[index] = s2Ant;
      index++;
    }

    if (bt.startsWith("RESET")) {

      memset(s1, 0, sizeof(s1));
      memset(s2, 0, sizeof(s2));
      index = 0;
    }

    if (bt.startsWith("RUN")) {

      while (bt.startsWith("RESET") != true) {
        for (int i = 0; i <= index - 2; i++) {
          if (Bluetooth.available() > 0) {
            bt = Bluetooth.readString();
            if (bt.startsWith("PAUSE") == true) {

              while (bt.startsWith("RUN") != true) {
                if (Bluetooth.available() > 0) {
                  bt = Bluetooth.readString();
                  if (bt.startsWith("RESET") == true) {
                    break;
                  }
                }
              }
            }
            if (bt.startsWith("ss")) {
              btS = bt.substring(2, bt.length());
              velG = btS.toInt();
            }
          }

          if (s1[i] == s1[i + 1]) {}

          if (s1[i] > s1[i + 1]) {
            for (int j = s1[i]; j >= s1[i + 1]; j--) {
              servo1.write(j);
              delay(velG);
            }
          }

          if (s1[i] < s1[i + 1]) {
            for (int j = s1[i]; j <= s1[i + 1]; j++) {
              servo1.write(j);
              delay(velG);
            }
          }

          if (s2[i] == s2[i + 1]) {}

          if (s2[i] > s2[i + 1]) {
            for (int j = s2[i]; j >= s2[i + 1]; j--) {
              servo2.write(j);
              delay(velG);
            }
          }

          if (s2[i] < s2[i + 1]) {
            for (int j = s2[i]; j <= s2[i + 1]; j++) {
              servo2.write(j);
              delay(velG);
            }
          }
        }
      }
    }
  }
}
