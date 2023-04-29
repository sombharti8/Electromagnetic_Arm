
# 3-link robot arm with an electro-magnet end-effector

The project is focused on designing and implementing a 3-link robot arm with an electro-magnet end effector. The robot arm will be controlled by an arduino and will have the capability to move the end effector in three-dimensional space with high precision and accuracy. The electro-magnet end effector will be able to pick up and move metallic objects.
The rotations of the link and the end-effector will be controlled through an app via WIFI and Bluetooth.





## Motivation

The main objective of this project is to develop a robotic arm that can perform tasks that are difficult or dangerous for humans to do. This robot arm can be used in industrial automation, manufacturing, and other applications where repetitive tasks are required. The electro-magnet end effector provides the capability to handle metallic objects with ease, making it suitable for applications where objects need to be picked up and moved with precision.For example, it cam be used while mining iron ore or the shipping industry where cargo needs to picked and placed.
## Tech/ Framework used

For the micro-controller we used 2 Arduino uno wifi module. This helped us control the robot through wifi (and bluetooth). Additionally, it powered the arm better than the regular Arduino.

We wrote all our code in Arduino IDE. The base language that we used was C.

We created an app on MIT app inventor to control our servo rotations and pick and place of our electro-magnet. We have provided the aia file. To access our you have to upload that aia file in you MIT app inventor and open it in your MIT AI app inventor.

## Code example

Bluetooth.ino

This is an Arduino program written in C++ that controls four servo motors and reads commands from a Bluetooth module. The program listens to incoming messages through the Bluetooth module and controls the position and speed of the servos accordingly. The program also has the ability to store and run predefined sequences of servo movements.

The program starts by including the Servo and SoftwareSerial libraries. It then creates an instance of the SoftwareSerial library for communication with the Bluetooth module, and instances of the Servo library for controlling the servo motors.

The servo motors are connected to pins 5, 6, 7, and 11 of the Arduino board. The initial positions of the servos are set to 90 degrees for servo1, 100 degrees for servo2, 80 degrees for servo3, and 115 degrees for servo4.

In the main loop, the program checks for incoming messages through the Bluetooth module. If a message is available, it reads the message and processes it according to its content. The program recognizes different types of messages and responds accordingly:

Messages starting with "s1" followed by a number represent the desired position of servo1. The program moves servo1 to the desired position by incrementally changing its position using a for loop, with a delay between each increment to control the speed of the movement. The program also saves the current position of servo1 to an array for later use.
Messages equal to "1" or "0" represent digital signals to turn on or off the built-in LED of the Arduino board, respectively.
Messages starting with "s2" followed by a number represent the desired position of servo2. The program moves servo2 to the desired position by incrementally changing its position using a for loop, with a delay between each increment to control the speed of the movement. The program also moves servo3 in the opposite direction of servo2 to make sure the end effector of the robot arm moves vertically. The program saves the current position of servo2 and servo3 to arrays for later use.
Messages starting with "s4" followed by a number represent the desired position of servo4. The program moves servo4 to the desired position by incrementally changing its position using a for loop, with a delay between each increment to control the speed of the movement. The program also saves the current position of servo4 to an array for later use.
Messages starting with "SAVE" save the current positions of servo1, servo2, and servo4 to arrays for later use.
Messages starting with "RESET" reset the arrays that store the positions of servo1, servo2, and servo4.
Messages starting with "RUN" execute the sequence of servo movements stored in the arrays. The program moves the servos incrementally from one position to another, with a delay between each increment to control the speed of the movement. The program also checks for incoming messages while executing the sequence and responds to messages starting with "PAUSE" or "RESET" accordingly.
Overall, this program controls a robot arm with four servo motors using a Bluetooth module and allows for the creation and execution of predefined sequences of servo movements.

Wifi.ino

This code is designed to run on an Arduino board with a WiFiNINA shield and a servo motor connected to pin 10. It creates a server on port 80 and listens for incoming client requests. When a client connects, it waits for the client to send a request and then sends a response back to the client.

The code provides three functionalities: turning a Electromagnet on and off, moving a servo motor, and displaying a webpage with links for controlling the Electromagnet and servo motor. The Electromagnet is connected to pin 13 and can be turned on and off by sending the commands "ON" and "OFF" through the webpage. The servo motor can be moved by sending the command "servo" through the webpage.

To use this code, the user must first modify the ssid and userid variables to match their WiFi network credentials. Once the board is connected to the network, it will start listening for incoming client requests on port 80.

When a client connects, it will be sent a webpage with links for controlling the Electromagnet and servo motor. Clicking on these links will send commands to the board to turn the Electromagnet on and off and move the servo motor.

Note: The servo motor movement is limited to 180 degrees and is controlled by adding or subtracting 10 from its current position.
## Acknowledgements

 - [Arduino documentation ](https://www.arduino.cc/)
 - [The Enineering Mindset](https://www.youtube.com/watch?v=QbgTl6VSA9Y)
 - [Maker 101](https://www.youtube.com/watch?v=TkA2LJctU1c)
 - [BINARY UPDATES](https://www.youtube.com/watch?v=aQcJ4uHdQEA)


