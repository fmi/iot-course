void loop2(void* param);

void setup()
{
    Serial.begin(115200);
    
    /* xTaskCreatePinnedToCore(
        function address, 
        task name, 
        stack size (allocated on heap, 1024/2048/4096 is OK), 
        function argument pointer, 
        priority (loop() has 1 by default), 
        task handle (not necessary), 
        core number (loop() runs on 1 generally));
        
        NB: We can put multiple tasks on any core. */
    xTaskCreatePinnedToCore(loop2, "loop2", 1024, nullptr, 0, nullptr, 0);
}

void loop()
{
    /* Core 1 code. */
}

void loop2(void* param)
{
    /* 
        loop() also runs in a loop behind the scenes.
        Make loop2() run indefinitely as well.
     */
    while (true)
    {
        /* loop2 code. */
    }
}
