# Utility Program (C)

A terminal-based multi-tool program written in C.

This project combines multiple interactive utilities into a single menu-driven application.

---

## Features

### 🔢 Basic Calculator
Supports:

- One-input operations
  - Square root
  - Absolute value
- Two-input operations
  - Addition
  - Subtraction
  - Multiplication
  - Division
  - Power

Includes validation for invalid inputs (like division by zero).

---

### 🔍 Number Analyzer
Analyze an integer for:

- Prime status
- Parity (even / odd)
- Polarity (positive / negative)
- Factors

Handles special cases such as negative numbers and zero.

---

### 🌡️ Temperature Converter
Convert between:

- Celsius
- Fahrenheit
- Kelvin

Includes validation against impossible temperatures (below absolute zero).

---

## Key Concepts Used

- Menu-driven program structure
- Input validation using `fgets`, `strtol`, and `strtod`
- Modular functions
- Loops and control flow
- Defensive programming against invalid input

---

## How to Run

Compile:

```bash
gcc main.c -o utility
