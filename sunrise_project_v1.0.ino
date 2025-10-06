const int sensorPin = 13;
const int calibrateModeButton = 14;
const int calibrateModeLED = 15;
float sensorValue = 0;
float computePercentage = 0;
float calibratedValue = 275;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //declaring the pins of the 10 segment LED Bar Graph Display
  for(int i = 1; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }

  //calibrate button definition
  pinMode(calibrateModeButton, INPUT);
  pinMode(calibrateModeLED, OUTPUT);

}

void calibrateLight() {

  while(true) {
    digitalWrite(calibrateModeLED, HIGH);
    delay(500);
    digitalWrite(calibrateModeLED, LOW);
    delay(500);

    if(digitalRead(calibrateModeButton) == HIGH) {
      digitalWrite(calibrateModeLED, LOW);
      break;
    }

  }
  
  float calibrated = analogRead(sensorPin);
  calibratedValue = calibrated;
  
}


void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  computePercentage = (sensorValue / calibratedValue) * 100;

  if(digitalRead(calibrateModeButton) == HIGH) {
    calibrateLight();
  }

  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  Serial.print("Percentage: ");
  Serial.print(computePercentage);
  Serial.println("%");

  Serial.print("Calibrated value: ");
  Serial.print(calibratedValue);
  Serial.println("\n\n");

  if(computePercentage <= 10.0) {
    for(int i = 1; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 20.0 && computePercentage > 10.0) {
    digitalWrite(1, HIGH);
    for(int i = 2; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 30.0 && computePercentage > 20.0) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    for(int i = 3; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 40.0 && computePercentage > 30.0) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    for(int i = 4; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 50.0 && computePercentage > 40.0) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    for(int i = 5; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 60.0 && computePercentage > 50.0) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    for(int i = 6; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 70.0 && computePercentage > 60.0) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    for(int i = 6; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 80.0 && computePercentage > 70.0) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    for(int i = 8; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  }

  else if(computePercentage <= 90.0 && computePercentage > 80.0) {
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    for(int i = 9; i <= 10; i++) {
      digitalWrite(i , LOW);
    }
  } 

  else {
    for(int i = 1; i <= 10; i++) {
      digitalWrite(i , HIGH);
    }
  }
  delay(750);
}
