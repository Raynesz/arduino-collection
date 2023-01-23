int switch1 = 0;
int switch2 = 0;

void setup() {  
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch1 = digitalRead(2);
  switch2 = digitalRead(4);

  if (switch1 == switch2) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  if (switch1) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }

  if (switch2) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }  
}
