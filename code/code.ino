#define ena 9
#define in1 6
#define in2 7
#define enb 10
#define in3 5
#define in4 2
#define button 4
int RotDirec = 0;
int pressed = false;
void setup() {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(button, INPUT);
  //initial direction of rotation//
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void loop() {
  int potmeter = analogRead(A0);    // potentiometer value
  int pwmout = map(potmeter, 0, 1023, 0 , 255);     // potentiometer value from 0 to 255
  analogWrite(ena, pwmout);     //PWM signal to L298N Enable pin
  // button //
  if (digitalRead(button) == true) {
    pressed = !pressed;
  }
  while (digitalRead(button) == true);
  delay(20);
  // Sit1 If button is pressed - change rotation direction//
  if (pressed == true  & RotDirec == 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    RotDirec = 1;
    delay(20);
  }
  // Sit2 If button is pressed - change rotation direction//
  if (pressed == false & RotDirec == 1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    RotDirec = 0;
    delay(20);
  }
}
