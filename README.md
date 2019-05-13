# Pulse-train-rate-counter
Basic pulse train rate counter that can be adapted and scaled for use as a tachometer, or low speed frequency counter

This is a general purpose pulse train rate counter that can be used count pulse rates up to 6kHz on an interrupt pin using a an Arduino UNO. The example code measures the time between pulses in a square-wave pulse train, and calculates the average pulse rate. The averaged pulse rate is scaled to Hertz and displayed in the serial monitor.  This code can also be scaled to read pulses per minute, which is useful for creating a tachometer to measure the rotational speed of a shaft.

There is a library called averager.h that needs to be included.  The averager library provides smoothing by creating a running average of the time between pulses.  The number of samples to average over can be set within the averager.h code.
