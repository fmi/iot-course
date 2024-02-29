void loop2(void* param);

/* Semaphores can be set up with xSemaphore... functions, too. */
struct shared_data
{
    constexpr static uint8_t capacity = 64;
    char str[capacity];
    int locked = 0;
    
    void lock() { ++locked; }
    void unlock() { locked = (locked == 0) ? 0 : locked - 1; }
    void clearbuff() { memset(str, 0, shared_data::capacity); }
} sd;

void setup()
{
    Serial.begin(115200);
    xTaskCreatePinnedToCore(loop2, "loop2", 4096, nullptr, 2, nullptr, 0);
}

void loop()
{
    while (sd.locked)
    {
        ;
    }
    sd.lock();
    /* If result isn't empty, display it. */
    if(*sd.str != '\0')
    {
        Serial.printf("%s\n", sd.str);
        /* Reset the buffer (not necessary, just to avoid spam). */
        sd.clearbuff();
    }
    sd.unlock();

    /* 
        While the other core works, we can probe for new results rapidly,
        and run networking/bookkeeping without interrupting it.
        The semaphore covers the *unlikely* case of simultaneous access.
    */
    delay(50);
}

void loop2(void* param)
{
    while (true)
    {
        /* Simulate our computation that takes some time. */
        delay(1800);

        /* Write results. */
        while (sd.locked)
        {
            ;
        }
        sd.lock();

        const char* msg = "Hello World!";
        strcpy(sd.str, msg);
        

        sd.unlock();
    }
}
