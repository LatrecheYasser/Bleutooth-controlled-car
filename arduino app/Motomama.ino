#include // import the serial library

SoftwareSerial SerialPort(0, 1); // RX, TX

// Pin 13 has an LED connected on most Arduino boards.

// give it a name:

int BluetoothData; // the data given from Computer

int EnableA = 10;

int InA1 = 8;

int InA2 = 9;

int EnableB = 11;

int InB1 = 12;

int InB2 = 13;

void setup() {


// put your setup code here, to run once:

// Inicializa los pines del motor como salidas

pinMode(EnableA, OUTPUT); // sets the pin as output

pinMode(InA1, OUTPUT); // sets the pin as output

pinMode(InA2, OUTPUT); // sets the pin as output

pinMode(EnableB, OUTPUT); // sets the pin as output

pinMode(InB1, OUTPUT); // sets the pin as output

pinMode(InB2, OUTPUT); // sets the pin as output

digitalWrite(EnableA, LOW);

digitalWrite(InA1, LOW);

digitalWrite(InA2, LOW);

digitalWrite(EnableB, LOW);

digitalWrite(InB1, LOW);

digitalWrite(InB2, LOW);

SerialPort.begin(9600);
SerialPort.println("Bluetooth On: 0 = Parar, 1 >> Adelante, 2 << Atras");

void loop() {

// put your main code here, to run repeatedly:

if (SerialPort.available()){

BluetoothData = SerialPort.read();

if(BluetoothData=='0'){ //if number 0 pressed ....

digitalWrite(EnableA, LOW);

digitalWrite(InA1, LOW);

digitalWrite(InA2, LOW);

SerialPort.println("Motor A Detenido");
}

if(BluetoothData=='1'){ // if number 1 pressed ....

digitalWrite(EnableA, HIGH);

digitalWrite(InA1, HIGH);

digitalWrite(InA2, LOW);

SerialPort.println("Motor A Adelante");

}

if (BluetoothData=='2'){// if number 2 pressed ....

digitalWrite(EnableA, HIGH);

digitalWrite(InA1, LOW);

digitalWrite(InA2, HIGH);

SerialPort.println("Motor A Atras");

}

if(BluetoothData=='3'){ // if number 0 pressed ....

digitalWrite(EnableB, LOW);

digitalWrite(InB1, LOW);

digitalWrite(InB2, LOW);

SerialPort.println("Motor B Detenido");

}

if(BluetoothData=='4'){ // if number 1 pressed ....

digitalWrite(EnableB, HIGH);

digitalWrite(InB1, HIGH);

digitalWrite(InB2, LOW);

SerialPort.println("Motor B Adelante");

}

if (BluetoothData=='5'){// if number 2 pressed ....

digitalWrite(EnableB, HIGH);

digitalWrite(InB1, LOW);

digitalWrite(InB2, HIGH);

SerialPort.println("Motor B Atras");

}

//SerialPort.println(BluetoothData);
}

delay(100);// prepare for next data ...

}