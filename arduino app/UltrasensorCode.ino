
const int trigPin = 12;
const int echoPin = 13;

long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// the speed of the sound is 0.034 cm/us so to calculate the distance to the object we maltuplay the duration by 0.034 divided by 2 because the sound travles 2 times this distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
if (distance <= 5){
  Serial.print("Distance: ");  
  Serial.println(distance);
}
}
