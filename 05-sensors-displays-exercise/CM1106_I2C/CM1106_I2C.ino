#include <cm1106_i2c.h>

CM1106_I2C cm1106_i2c;

// #define CM1107

void setup() {
  Serial.begin(115200);
  while(!Serial);

  Wire.begin(21, 22); // SDA, SCL

  cm1106_i2c.begin();
  
  delay(1000);
  cm1106_i2c.read_serial_number();
  delay(1000);
  cm1106_i2c.check_sw_version();
  delay(1000);
}

void loop() {
  uint8_t ret = cm1106_i2c.measure_result();

  if (ret == 0) {
    Serial.print("Co2 : ");
    Serial.println(cm1106_i2c.co2);
    Serial.println("Status >>");


#if defined(CM1107)
    if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_PREHEATING)) {
      Serial.println("Preheating");
    } else {
      Serial.println("Preheat complete");
    }

    if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_OPERATING_NORMAL)) {
      Serial.println("Sensor Error");
    } else {
      Serial.println("Operating normal");
    }

    if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_OVER_MEASUREMENT_RANGE)) {
      Serial.println("Over Measurement Range");
    } else {
      Serial.println("Normal Measurement Range");
    }

    if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_LESS_THAN_MEASUREMENT_RANGE)) {
      Serial.println("Less than Measurement Range");
    } else {
      Serial.println("Normal Measurement Range");
    }

    if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_CALIBRATED)) {
      Serial.println("Non-calibrated");
    } else {
      Serial.println("Calibrated");
    }

    if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_LIGHT_AGING)) {
      Serial.println("Light Aging");
    } else {
      Serial.println("Light Normal");
    }

    if (cm1106_i2c.status & (1 << CM1106_I2C_STATUS_CM1107_DRIFT)) {
      Serial.println("Drift");
    } else {
      Serial.println("Non-Drift");
    }

    
#else
    switch (cm1106_i2c.status) {
      case CM1106_I2C_STATUS_PREHEATING: {
          Serial.println("Preheating");
          break;
        }
      case CM1106_I2C_STATUS_NORMAL_OPERATION: {
          Serial.println("Normal operation");
          break;
        }
      case CM1106_I2C_STATUS_OPERATING_TROUBLE: {
          Serial.println("Operating trouble");
          break;
        }
      case CM1106_I2C_STATUS_OUT_OF_FS: {
          Serial.println("Out of FS");
          break;
        }
      case CM1106_I2C_STATUS_NON_CALIBRATED: {
          Serial.println("Non calibrated");
          break;
        }
    }
#endif
    


    
  }
  delay(1000);
}