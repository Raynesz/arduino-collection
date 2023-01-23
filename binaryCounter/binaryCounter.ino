int switchUp = 0;
int switchDown= 0;
int number = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchUp = digitalRead(13);
  switchDown = digitalRead(12);

  if (switchUp != switchDown) {
    if (switchUp) number++;
    if (switchDown) number--;
  }

  if (number < 0) number = 0;
  if (number > 15) number = 15;

  output(number);
  delay(100);
}

void output(int number) {
  int bit0 = number & 1;
  int bit1 = (number >> 1) & 1;
  int bit2 = (number >> 2) & 1;
  int bit3 = (number >> 3) & 1;

  digitalWrite(8, bit0);
  digitalWrite(7, bit1);
  digitalWrite(3, bit2);
  digitalWrite(2, bit3);
}
