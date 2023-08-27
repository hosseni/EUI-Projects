# Periodic Timer Tasks

This project demonstrates how to use periodic timer interrupts to manage tasks on a microcontroller. Two tasks are implemented using different timers: blinking an LED every 30 seconds and executing another task every 2 seconds.

## Overview

Modern microcontrollers provide timers that can generate periodic interrupts. This project utilizes this feature to perform tasks at precise intervals. Timer interrupts are used to trigger specific functions, ensuring efficient and accurate task execution.

## Features

- Task 1: Blink an LED every 30 seconds.
- Task 2: Execute a task every 2 seconds.

## Getting Started

1. Clone or download the repository to your development environment.

2. Configure your microcontroller and peripherals according to your hardware setup.

3. Compile the code using the specified IDE or compiler.

4. Flash the compiled binary onto the microcontroller.

## Timer Configuration

Two timers are utilized for this project:

1. Timer 1 (30 seconds interval):
   - Initialize the timer with a 30-second duration.
   - Configure the timer interrupt to trigger Task 1 (LED blinking).
   - Start the timer.

2. Timer 2 (2 seconds interval):
   - Initialize the timer with a 2-second duration.
   - Configure the timer interrupt to trigger Task 2 (other task).
   - Start the timer.

## Task Implementation

1. Task 1: Blink LED every 30 seconds.
   - Toggle the state of the LED pin within the timer interrupt handler.

2. Task 2: Execute another task every 2 seconds.
   - Implement the task logic within the timer interrupt handler.

## Usage

1. Compile and flash the code onto your microcontroller.

2. Observe the LED blinking every 30 seconds.

3. The other task will execute every 2 seconds, which can be verified through another output, log, or debugging mechanism.

## Contributing

Contributions are welcome! If you find any issues or improvements, feel free to create an issue or pull request in this repository.

## License

This project is licensed under the [Specify License Name and URL] License - see the [LICENSE](LICENSE) file for details.
