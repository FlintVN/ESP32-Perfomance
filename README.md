### ESP32 Performance Benchmark
This project benchmarks the performance of different programming languages and frameworks on the ESP32, focusing on:
- Execution time of 10 million iterations using `for` and `while` loops.
- Maximum toggling frequency of GPIO when driven by the CPU.

### Benchmark Results
| Platform                  | `for` loop (10M) | `while` loop (10M) | GPIO toggle frequency |
| ------------------------- | ---------------- | ------------------ | --------------------- |
| **C-IDF v5.5.0**          | 375 ms           | 375 ms             | 2.2 MHz               |
| **FlintESPJVM v0.0.11**   | 9254 ms          | 9254 ms            | 295 KHz               |
| **MicroPython v1.26.0**   | 43677 ms         | 79582 ms           | 107 KHz               |
| **NanoFramework v1.12.4** | 77656 ms         | 77660 ms           | 2.4 KHz               |
