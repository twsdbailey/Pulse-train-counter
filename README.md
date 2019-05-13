# Pulse-train-counter
Basic pulse train rate counter that can be adapted and scaled for a tachometer, or low speed frequency counter

This is a general purpose pulse train rate counter that can be used count pulse rates up to 3.6kHz. The example code is a frequency counter that counts pulses in a square wave pulse train, and displays the frequency in Hertz in the serial monitor.  This code can also be scaled to read pulses per minute, which is useful for creating a tachometer used to measure the rotational speed of a shaft.

There is a library called averager.h that needs to be included.  The averager library provides smoothing for the pulse rate counts.
