
#include "averager.h";
int scaledToHertz = 0;
byte interruptPin = 2;// can be pin 2 or 3
unsigned long lasttime;
unsigned long timesincelast = 0;
averager cycleTime; //creates instance of the averager class where running average of "cycleTime" is stored

void getCycleTime()
{
  detachInterrupt(digitalPinToInterrupt(interruptPin));//detach interrupt temporarily to complete tasks below without being interrupted
  unsigned long current = micros();
  timesincelast = current - lasttime;
  lasttime = current;
  cycleTime.idle(timesincelast); //add the elapsed cycle time to the running average
  attachInterrupt(digitalPinToInterrupt(interruptPin), getCycleTime, FALLING);
}

void setup() {
  pinMode(interruptPin, INPUT_PULLUP); //sets internal pull-up resistor for interrupt pin
  attachInterrupt(digitalPinToInterrupt(interruptPin), getCycleTime, FALLING); //Interrupts are called on falling edge of input
  Serial.begin(9600);
}

void loop() {
  scaledToHertz = (60 * 1000000 / cycleTime()) / 60; //scaled to output cycles per second, or Hz
  Serial.print(scaledToHertz);
  Serial.println(" Hz");
}



