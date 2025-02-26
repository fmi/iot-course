# Exercises
Connect the board to the PC and do the exercises, listed in the `src` folder. Start with `HelloWorld`.

# Optional exercises
## Dual core
The `07_DUALCORE` exercise touches some advanced features. The ESP32 has two available cores that share the heap (~290KB). By default, the `loop()` function runs on core 1. Using some built-in functions, we can set as many as we want tasks on any core. Most notably, we can run a high-memory high-performance task on core 0, and run our networking/error-handling code on core 1 to avoid bottlenecks.

- https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html
- https://www.freertos.org/a00113.html
- https://www.freertos.org/RTOS_Task_Notification_As_Counting_Semaphore.html

## Serial comm
The `08_SerialTest` exercise demonstrates incoming serial communication. You have to write commands in the serial monitor and they will be executed by the board.
