### ESP32 Performance Benchmark

This project benchmarks the performance of different programming languages and frameworks on the ESP32, focusing on:

- Execution time of 10 million iterations using `for` and `while` loops.
- Maximum toggling frequency of GPIO when driven by the CPU.

### Benchmark Results

| Language    | Platform              | `for` loop (10M) | `while` loop (10M) | GPIO toggle frequency |
| ----------- | --------------------- | ------------------ | -------------------- | --------------------- |
| C           | IDF v5.5.0            | 375 ms             | 375 ms               | 2.2 MHz               |
| Java        | FlintJVM v2.6.0       | 5937 ms            | 5937 ms              | 341 KHz               |
| MicroPython | MicroPython v1.26.0   | 43677 ms           | 79582 ms             | 107 KHz               |
| C#          | NanoFramework v1.12.4 | 77656 ms           | 77660 ms             | 2.4 KHz               |
