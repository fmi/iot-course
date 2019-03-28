// A modified exampleof https://github.com/matthijskooijman/arduino-lmic

#include <lmic.h>
#include <hal/hal.h>

// TTN supplied credentials
static const PROGMEM u1_t NWKSKEY[16] = { 0x1C, 0x6D, 0x4B, 0x07, 0x2A, 0x99, 0x36, 0x11, 0x61, 0x22, 0xF2, 0x50, 0xA8, 0xDF, 0x99, 0x29 };
static const PROGMEM u1_t APPSKEY[16] = { 0x8C, 0x14, 0x7A, 0x5D, 0xA6, 0x9D, 0x89, 0xC3, 0x01, 0xF3, 0xE0, 0x7C, 0xE8, 0x3D, 0xDD, 0xE5 };
static const u4_t DEVADDR = 0x26011E17; 

// Void callbacks
void os_getArtEui (u1_t* buf) { }
void os_getDevEui (u1_t* buf) { }
void os_getDevKey (u1_t* buf) { }

                                   
//static uint8_t mydata[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
static uint8_t mydata[] = {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01};
static osjob_t sendjob;

const lmic_pinmap lmic_pins = {
    .nss = 8,                      // Digital pin connected to SS
    .rxtx = LMIC_UNUSED_PIN,       // we do not use these
    .rst = 4,                      // Digital pin connected to RST
    .dio = {7, 1, 2},              // Digital pin connected to 00,01,02 
};

void onEvent (ev_t ev) {
  
    switch(ev) {
        case EV_SCAN_TIMEOUT:
            Serial.println(F("EV_SCAN_TIMEOUT"));
            break;
        case EV_BEACON_FOUND:
            Serial.println(F("EV_BEACON_FOUND"));
            break;
        case EV_BEACON_MISSED:
            Serial.println(F("EV_BEACON_MISSED"));
            break;
        case EV_BEACON_TRACKED:
            Serial.println(F("EV_BEACON_TRACKED"));
            break;
        case EV_JOINING:
            Serial.println(F("EV_JOINING"));
            break;
        case EV_JOINED:
            Serial.println(F("EV_JOINED"));
            break;
        case EV_RFU1:
            Serial.println(F("EV_RFU1"));
            break;
        case EV_JOIN_FAILED:
            Serial.println(F("EV_JOIN_FAILED"));
            break;
        case EV_REJOIN_FAILED:
            Serial.println(F("EV_REJOIN_FAILED"));
            break;
            break;
        case EV_TXCOMPLETE:
            Serial.println(F("EV_TXCOMPLETE"));
            if (LMIC.txrxFlags & TXRX_ACK)
                Serial.println(F("Received ack"));
            if(LMIC.dataLen) {
                // data received in rx slot after tx
                Serial.print(F("Data Received: "));
                Serial.write(LMIC.frame+LMIC.dataBeg, LMIC.dataLen);
                Serial.println();
            }
            delay(10000);
            do_send(&sendjob); // data must be prepared in the loop function 
            break;
        case EV_LOST_TSYNC:
            Serial.println(F("EV_LOST_TSYNC"));
            break;
        case EV_RESET:
            Serial.println(F("EV_RESET"));
            break;
        case EV_RXCOMPLETE:
            // data received in ping slot
            Serial.println(F("EV_RXCOMPLETE"));
            break;
        case EV_LINK_DEAD:
            Serial.println(F("EV_LINK_DEAD"));
            break;
        case EV_LINK_ALIVE:
            Serial.println(F("EV_LINK_ALIVE"));
            break;
         default:
            Serial.println(F("Unknown event"));
            break;
    }
}

void do_send(osjob_t* j){
    
    if (LMIC.opmode & OP_TXRXPEND) {
        Serial.println(F("OP_TXRXPEND not ready!"));
    } else {
        LMIC_setTxData2(1, mydata, sizeof(mydata), 0);
        Serial.println(F("Packet queued"));
    }
}

void setup() {
    delay(3000);
    Serial.begin(9600);
    Serial.println(F("Starting"));
    
    os_init();
    LMIC_reset();
    #ifdef PROGMEM
      uint8_t appskey[sizeof(APPSKEY)];
      uint8_t nwkskey[sizeof(NWKSKEY)];
      memcpy_P(appskey, APPSKEY, sizeof(APPSKEY));
      memcpy_P(nwkskey, NWKSKEY, sizeof(NWKSKEY));
      LMIC_setSession (0x1, DEVADDR, nwkskey, appskey);
    #else
      LMIC_setSession (0x1, DEVADDR, NWKSKEY, APPSKEY);
    #endif
    LMIC_setupChannel(0, 868100000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(1, 868300000, DR_RANGE_MAP(DR_SF12, DR_SF7B), BAND_CENTI);      // g-band
    LMIC_setupChannel(2, 868500000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(3, 867100000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(4, 867300000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(5, 867500000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(6, 867700000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(7, 867900000, DR_RANGE_MAP(DR_SF12, DR_SF7),  BAND_CENTI);      // g-band
    LMIC_setupChannel(8, 868800000, DR_RANGE_MAP(DR_FSK,  DR_FSK),  BAND_MILLI);      // g2-band
    LMIC_setLinkCheckMode(0);
    LMIC_setDrTxpow(DR_SF7, 14);    // SF7 and max power from module = 14
    LMIC_setClockError(MAX_CLOCK_ERROR * 1 / 100);
    LMIC.dn2Dr = DR_SF9;
    do_send(&sendjob);
}

void loop() {

    os_runloop_once(); //LoRa statemachine

    // here you are supposed to read sensors and update your data
    //uint8_t tmp = mydata[0];
    //mydata[0]= mydata[1];
    //mydata[1]= tmp;
}
