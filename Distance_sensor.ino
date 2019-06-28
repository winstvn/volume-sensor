#include <NewPing.h>

#define TRIGGER_PIN  9
#define ECHO_PIN     8
#define MAX_DISTANCE 200

int range = 60;
int extent = range - 5;
int dist = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(200);
  Ping();
  Serial.print("Dist: ");
  Serial.println (dist);

  if (dist > 0 && dist <= 5) {
    delay (700);
    Ping();
    if (dist > 0 && dist <= 5) {
      Serial.println("NextSong");
      delay (2000);
    }
    else {
      Serial.println("Play/Pause");
      delay (2000);
    }
  }

  if (dist >= extent / 2 - 5 && dist <= extent / 2 + 5) {
    delay(200);
    if (dist >= extent / 2 - 5 && dist <= extent / 2 + 5) {
      Serial.println("Adj Vol");
      Ping();
      while (dist <= extent + 2) {
        Ping();
        if (dist > 0 && dist < extent / 2 - 5) {
          Serial.println ("Vup");
          delay(200);
        }
        else if (dist > extent / 2 + 5 && dist < extent + 2) {
          Serial.println ("Vdown");
          delay(200);
        }
        else if (dist >= extent / 2 - 5 && dist <= extent / 2 + 5) {
          Serial.println("Adj Vol");
          delay(200);
        }
      }
    }
  }
}

void Ping() {
  dist = sonar.ping_cm();
}
