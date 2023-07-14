const int buzzerPin = 4;         // Buzzer pin
const int potentiometerPin = A0; // Potentiometer pin
const int trigPin = 2;
const int echoPin = 3;
int freq = 500;

long duration;
int distance;
int distanceThreshold;           // Threshold distance read from the potentiometer

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration;

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);  
 
  // Reading the potentiometer value
  int potValue = analogRead(potentiometerPin);
 
  // Mapping the potentiometer value to the desired distance range (10cm - 100cm)
  freq = map(distance, 0, 100, 1, 500);
  tone(buzzerPin,880,80);
  delay(freq);
 /*
  // Controlling the buzzer based on the distance
  if (distance > 50) {
    // If the distance is less than the threshold, set the buzzer to a high frequency and play it for 200ms
    tone(buzzerPin, 440, 200);
    delay(200);
  } else if (distance < 50) {
    tone(buzzerPin, 440, 200);
    delay(200);
  }
  else {
    // If the distance is greater than or equal to the threshold, turn off the buzzer
    noTone(buzzerPin);
    delay(200);
  }
 
  delay(500); // Delay between measurements*/
}