# GPA Calculator

A simple GPA calculator written in C.

This program calculates your GPA (in the 4.0 scale) using one of two modes:

- **Input Mode** – Enter each class individually by specifying:
  - Course level (AP, Honors, or Standard)
  - Letter grade (A, B, C, D, or F)

  The program automatically converts your inputs into weighted GPA values.

- **Average Mode** – Enter previously calculated semester GPA values, and the program will compute the overall average GPA.

## Features

- Weighted GPA calculation
- Supports AP, Honors, and Standard courses
- Handles invalid input with sensible defaults
- Calculates GPA for up to 20 classes
- Repeat calculations without restarting the program

## Building

Compile using GCC:

```bash
gcc main.c -o GPA-Calculator
```

or with optimizations:

```bash
gcc main.c -O2 -o GPA-Calculator
```

## Running

Windows:

```bash
GPA-Calculator.exe
```

Linux/macOS:

```bash
./GPA-Calculator
```

## Usage

1. Enter the number of classes (maximum 20).
2. Choose one of the available modes:
   - **Input Mode (I)** – Enter course level and letter grade for each class.
   - **Average Mode (A)** – Enter previously calculated GPA values.
3. View your calculated GPA.
4. Choose whether to perform another calculation or exit.

## License

This project is released under the MIT License.