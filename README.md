# Bleutooth-controlled-car

This project is developed for the users to control a Car through
Bluetooth. The user can control different movements like
forward, backward, left and right plus to enable/disable the
auto-control mode. The Bluetooth receiver is connected with a
phone. An application is used to operate the transmission.
First the transmitter and the receiver are synchronized. When
the user presses a specific button on the application interface,
the Bluetooth receiver implemented on the motor shield
receives the signal and accordingly send the information to the
Arduino UNO microcontroller which sends back the order to the
motor shield.
The motor shield controls the operation of the Car through
external electronic circuit. The circuit is used as a switch to
operate the particular motor in the Car. By this way the user
can control any of the operations of the Car.
In the auto-control mode the Car uses an Ultra-Sensor to detect
obstacles and moves left or right to avoid them.