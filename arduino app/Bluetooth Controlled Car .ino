
int BluetoothData; 
int Run = 0;
int Goingup = -1;
int Auto = 0;

// MOTO MAMA pins

int InA1 = 8;

int InA2 = 9;

int EnableA = 10;

int EnableB = 11;

int InB1 = 12;

int InB2 = 13;

// Ultra sensor Pin

const int Trig = 6;
const int Echo = 7;



void setup() {




pinMode(EnableA, OUTPUT);

pinMode(InA1, OUTPUT);

pinMode(InA2, OUTPUT); 

pinMode(EnableB, OUTPUT); 

pinMode(InB1, OUTPUT); 

pinMode(InB2, OUTPUT); 

digitalWrite(EnableA, LOW);

digitalWrite(InA1, LOW);

digitalWrite(InA2, LOW);

digitalWrite(EnableB, LOW);

digitalWrite(InB1, LOW);

digitalWrite(InB2, LOW);
 
Serial.begin(115200);
Serial.println("Bluetooth on");

}

void loop() {


if(Serial.available() > 0){ // Checks whether data is comming from the serial port
 BluetoothData = Serial.read(); // Reads the data from the serial port

 Serial.println(BluetoothData);

if(BluetoothData == 1) Run = 1;

else if (BluetoothData == 0){
Run = 0;
digitalWrite(EnableA, LOW);

digitalWrite(InA1, LOW);

digitalWrite(InA2, LOW);

digitalWrite(EnableB, LOW);

digitalWrite(InB1, LOW);

digitalWrite(InB2, LOW);

}

if (BluetoothData == 7) {
  Auto = 1; 

}
else if (BluetoothData == 8){
  Auto = 0;
  
}

if(Run == 1){
if (Auto == 0){
   // if the Up button pessed
if(BluetoothData == 3){
  Serial.println("go up");
Up();
Goingup = 1;
}

 // if the left button pressed
if(BluetoothData == 4) Left(Goingup);

  // if the right button pressed
if(BluetoothData == 5) Right(Goingup);

  // if the Down button pressed
if(BluetoothData == 6) {
  Serial.println("go down");
  Down();
  Goingup = 0;
}
}else if (Auto == 1 ){
RunAuto();
}

}
}
}


void Up(){
  
  digitalWrite(EnableA, HIGH);
  
  digitalWrite(InA1, HIGH);
  
  digitalWrite(InA2, LOW);
  
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InB1, HIGH);
  
  digitalWrite(InB2, LOW);
}

void Right(int where){
  if(where == 1){ // is UP
  digitalWrite(EnableA, HIGH);
  
  digitalWrite(InA1, LOW);
  
  digitalWrite(InA2, LOW);
  
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InB1, HIGH);
  
  digitalWrite(InB2, LOW);
}else{ //is Down 
  digitalWrite(EnableA, HIGH);
  
  digitalWrite(InA1, LOW);
  
  digitalWrite(InA2, LOW);
  
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InB1, LOW);
  
  digitalWrite(InB2, HIGH);

}


}

void Left(int where){
  if(where == 1){//going up
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InA1, HIGH);
  
  digitalWrite(InA2, LOW);
  
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InB1, LOW);
  
  digitalWrite(InB2, LOW);
}else { // going down
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InA1, LOW);
  
  digitalWrite(InA2, HIGH);
  
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InB1, LOW);
  
  digitalWrite(InB2, LOW);
}
   
}
  
void Down(){
   digitalWrite(EnableA, HIGH);
  
  digitalWrite(InA1, LOW);
  
  digitalWrite(InA2, HIGH);
  
  digitalWrite(EnableB, HIGH);
  
  digitalWrite(InB1, LOW);
  
  digitalWrite(InB2, HIGH);
}

int sensor(){

long duration;
int distance;
  
digitalWrite(Trig, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(Trig, HIGH);
delayMicroseconds(5);
digitalWrite(Trig, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(Echo, HIGH);

// the speed of the sound is 0.034 cm/us so to calculate the distance to the object we maltuplay the duration by 0.034 divided by 2 because the sound travles 2 times this distance
distance= duration*0.034/2;
return distance;
}

int RunAuto(){
  long r = random(0,2); 
  Up();
  int distance = sensor();
  if(distance < 10){
    Down();
    delay(1500);
    Up();
    if(r == 0) { 
    Left(1);
    Serial.println("Auto left");
    } 
    else {
      Right(1);
    Serial.println("Auto Right");  
  }
    
   delay(2000);
   Up();
  }
}

