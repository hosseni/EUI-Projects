# Periodic Timer Tasks

This project demonstrates how to use periodic timer interrupts to manage tasks on a microcontroller. Two tasks are implemented using different timers: blinking an LED every 0.30 seconds and blinking an LED every 2 seconds.

## Overview

This project utilizes this feature to perform tasks at precise intervals. Timer interrupts are used to trigger specific functions, ensuring efficient and accurate task execution.

## Features

- Task 1: Blink an LED1 every 0.30 seconds.
- Task 2: Blink an LED2 every 2  seconds.

## Timer Configuration

Two timers are utilized for this project:

1. Timer 1 (30 seconds interval):
   - Initialize the timer with a 30-second duration.
   - Configure the timer interrupt to trigger Task 1 (LED1 blinking).
   - Start the timer.

2. Timer 2 (2 seconds interval):
   - Initialize the timer with a 2-second duration.
   - Configure the timer interrupt to trigger Task 2 (LED2 blinking).
   - Start the timer.

## Task Implementation

1. Task 1: Blink LED every 0.30 seconds.
   - Toggle the state of the LED1 pin within the timer interrupt handler.

2. Task 2: Execute another task every 2 seconds.
   - Toggle the state of the LED2 pin within the timer interrupt handler.


## Contributing

Contributions are welcome! If you find any issues or improvements, feel free to create an issue or pull request in this repository.

