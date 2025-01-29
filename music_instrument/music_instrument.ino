// Combines projects 06 and 07 of the starter kit projects book

int notes[] = {262, 294, 330, 349};

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13; // on-board LED

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // turn the LED on to signal calibration start

  while (millis() < 5000) { // calibrates the phototransistor in the first 5 seconds of operation
    sensorValue = analogRead(A2);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin, LOW); // turn the LED off to signal calibration end
}

void loop() {
  int keyVal = analogRead(A0); // get key press value
  sensorValue = analogRead(A2); // get phototransistor value

  int thereminPitch = map(sensorValue, sensorLow, sensorHigh, 50, 500); // bind theremin pitch within certain range

  int finalFrequency = thereminPitch;

  // combine theremin and key press frequencies
  if (keyVal == 1023) {
    finalFrequency = (thereminPitch + notes[0]) / 2;
  }
  else if (keyVal >= 990 && keyVal <= 1010) {
    finalFrequency = (thereminPitch + notes[1]) / 2;
  }
  else if (keyVal >= 505 && keyVal <= 515) {
    finalFrequency = (thereminPitch + notes[2]) / 2;
  }
  else if (keyVal >= 5 && keyVal <= 10) {
    finalFrequency = (thereminPitch + notes[3]) / 2;
  }

  tone(8, finalFrequency); // play the frequency. piezo is on pin 8
  delay(10);
}
