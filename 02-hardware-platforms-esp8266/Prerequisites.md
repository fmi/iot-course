1. Install Arduino IDE: https://www.arduino.cc/en/Main/Software - за опреационната система която използвате
2. Install ESP8266 Development Kit: https://github.com/esp8266/Arduino#installing-with-boards-manager
   * !!! Use version 2.3.0 which shall be more stable than 2.4.0
3. Install drivers (Windows & Mac) for the CH340G Usb2Serial chip: http://vair-monitor.com/drivers/
4. Plug your board and select it from the Tools > Board menu


# Drivers
За Черните и Дългите платки - не би трябвало да има нужда от драйвер (квадратния USB2Serial чип)
За Жълтите и Сините - трябва драйвера

# Blink Example
Load from File -> Examples -> ESP8266 -> Blink

* За Жълтите платки - Да се избере тип платка (Node MCU 0.9)заменете LED_BUILTIN с 1
* За Черните платки - Да се избере тип платка (Node MCU 1.0) - нищо не се заменя
* За Сините  платки - Да се избере тип платка (Wemos D1 R2 & Mini), да се свали upload speed на 115200 - нищо не се заменя в кода
* За Дългите платки с Батерия - Тип тип платка може да се избере - Node MCU 1.0, или да се смени LED_BUILTIN на 16
