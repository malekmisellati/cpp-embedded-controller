# C++ Embedded LED Controller

## Overview

A C++ embedded systems project built using an Arduino Uno-compatible microcontroller. The application controls five LEDs through GPIO outputs and uses a push button to switch between three operating modes.

The project demonstrates fundamental embedded programming concepts, including digital input/output, non-blocking timing, button debouncing, and object-oriented programming in C++.

## Features

- Controls five independently connected LEDs.
- Implements three operating modes:
  - **LED Chase:** LEDs illuminate sequentially.
  - **All LEDs Blink:** All five LEDs blink together.
  - **Alternating LEDs:** Two groups of LEDs alternate.
- Uses a push button to switch between operating modes.
- Implements non-blocking timing using `millis()`.
- Uses button debouncing to prevent unintended multiple inputs.
- Organizes LED functionality using a C++ class.

## Hardware

- OSEPP ARD-01 Arduino-compatible board
- Breadboard
- Five LEDs:
  - Red
  - White
  - Green
  - Yellow
  - Blue
- Five 330Ω resistors
- One momentary push button
- Jumper wires
- USB cable

## Pin Configuration

### LED Connections

| LED | Arduino Digital Pin |
|---|---:|
| Red | 5 |
| White | 2 |
| Green | 4 |
| Yellow | 3 |
| Blue | 6 |

Each LED uses a 330Ω current-limiting resistor.

### Push Button

| Connection | Arduino Pin |
|---|---|
| Button signal | Digital Pin 7 |
| Ground | GND |

The button uses the Arduino's internal pull-up resistor through `INPUT_PULLUP`, eliminating the need for an external pull-up resistor.

## Operating Modes

### Mode 1: LED Chase

The five LEDs illuminate one at a time in sequence. The sequence continuously repeats.

### Mode 2: All LEDs Blink

All five LEDs turn on and off together at regular intervals.

### Mode 3: Alternating LEDs

Two groups of LEDs alternate between illuminated and off states.

The push button cycles through all three modes and returns to the first mode after the third.

## Technologies and Concepts

- C++
- Arduino
- Arduino IDE
- ATmega328P-compatible microcontroller
- GPIO digital input and output
- Object-oriented programming
- C++ classes and encapsulation
- Arrays
- Non-blocking timing with `millis()`
- Button input and debouncing
- Serial communication for operating-mode messages

## Project Structure

```text
cpp-embedded-controller/
│
├── led_controller/
│   └── led_controller.ino
│
├── README.md
└── .gitignore
```

## Setup and Execution

1. Connect the Arduino board to your computer using USB.
2. Open `led_controller/led_controller.ino` in Arduino IDE.
3. Select the appropriate Arduino Uno-compatible board.
4. Select the connected serial port.
5. Verify the sketch to compile the program.
6. Upload the sketch to the board.
7. Press the push button to cycle through the three LED operating modes.

## Learning Objectives

This project explores practical embedded systems programming by combining software logic with physical hardware.

Key concepts demonstrated include:

- Configuring and controlling GPIO pins.
- Reading digital input signals.
- Managing multiple hardware outputs.
- Implementing non-blocking timing without pausing program execution.
- Handling mechanical button input and signal debouncing.
- Organizing embedded functionality using C++ classes.
- Interacting with a microcontroller through Arduino IDE and serial communication.
