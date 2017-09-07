int red = 10;
int yellow = 9;
int green = 8;
int button = 12;

int greenPed = 6;
int redPed = 7;

int greenPedSide = 5;
int redPedSide = 4;
int redSide = 3;
int yellowSide = 2;
int greenSide = 1;
int buttonSide = 13;
int buttonCarSide = 11;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
  pinMode(redPed, OUTPUT);
  pinMode(greenPed, OUTPUT);
  pinMode(redSide, OUTPUT);
  pinMode(yellowSide, OUTPUT);
  pinMode(greenSide, OUTPUT);
  pinMode(redPedSide, OUTPUT);
  pinMode(greenPedSide, OUTPUT);
  pinMode(buttonSide, INPUT);
  pinMode(buttonCarSide, INPUT);
  digitalWrite(green, HIGH);
  digitalWrite(redPed, HIGH);
  digitalWrite(redPedSide, HIGH);
  digitalWrite(greenSide, HIGH);
}

void loop() {
  if (digitalRead(button) == HIGH) {
    delay(15); // software debounce
    if (digitalRead(button) == HIGH) {
      // if the switch is HIGH, ie. pushed down - change the lights!
      changeLightsToRed();
      changeLightsToRedSide();
      changeLightsToGreenPedestrian();
      changeLightsToRedPedestrian();
      changeLightsToGreen();
      changeLightsToGreenSide();
      delay(3000); // wait for 15 seconds
    }
  }

  //Button for the side street
  if (digitalRead(buttonSide) == HIGH) {
    delay(15); // software debounce
    if (digitalRead(buttonSide) == HIGH) {
      // if the switch is HIGH, ie. pushed down - change the lights!
      changeLightsToRedSide();
      changeLightsToGreenPedestrianSide();
      changeLightsToRedPedestrianSide();
      changeLightsToGreenSide();
      delay(10000); // wait for 15 seconds
    }
  }

  //Button if car is detected for to long on the side street
  if (digitalRead(buttonCarSide) == HIGH) {
    delay(15); // software debounce
    if (digitalRead(buttonCarSide) == HIGH) {
      // if the switch is HIGH, ie. pushed down - change the lights!
      changeLightsToRed();
      delay(5000);
      changeLightsToRedSide();
      delay(5000);
      changeLightsToGreenSide();
      changeLightsToGreen();
      delay(3000);
    }
  }
}

void changeLightsToRed() {
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(3000);

  //turn off yellow, then turn red on for 5 seconds
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
}

void changeLightsToGreen() {
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}

void changeLightsToGreenPedestrian() {
  delay(2000);
  digitalWrite(redPed, LOW);
  digitalWrite(greenPed, HIGH);
  delay(5000);
}

void changeLightsToRedPedestrian() {
  digitalWrite(greenPed, LOW);
  digitalWrite(redPed, HIGH);
  delay(2000);
}

void changeLightsToRedPedestrianSide() {
  digitalWrite(greenPedSide, LOW);
  digitalWrite(redPedSide, HIGH);
  delay(2000);
}

void changeLightsToGreenPedestrianSide() {
  delay(2000);
  digitalWrite(redPedSide, LOW);
  digitalWrite(greenPedSide, HIGH);
  delay(5000);
}

void changeLightsToRedSide() {
  digitalWrite(greenSide, LOW);
  digitalWrite(yellowSide, HIGH);
  delay(3000);

  //turn off yellow, then turn red on for 5 seconds
  digitalWrite(yellowSide, LOW);
  digitalWrite(redSide, HIGH);
}

void changeLightsToGreenSide() {
  digitalWrite(yellowSide, LOW);
  digitalWrite(redSide, LOW);
  digitalWrite(greenSide, HIGH);
}

