1. Install Arduino IDE: https://www.arduino.cc/en/Main/Software - за опреационната система която използвате
2. Install ESP8266 Development Kit: https://github.com/esp8266/Arduino#installing-with-boards-manager
   * !!! Use version 2.3.0 which shall be more stable than 2.4.0
3. Install drivers (Windows & Mac) for the CH340G Usb2Serial chip: http://vair-monitor.com/drivers/
4. Plug your board and select it from the Tools > Board menu


Познания, които биха ви били в полза
* Програмиране на С
* Базови познания за микро контролери - GPIO, ADC, Захранване
* Познания по HTTP - ще правим HTTP Server и ще ползваме HTTP Client
* Познания по WiFi - Какво е Access Point

В края на тази лекция ще можете:

* да програмирате един ESP8266 модул (Wemos D1 Mini) 
* да четете неговия бутон
* да управлявате светодиода му 
* да се връзва към външен HTTP Server
* да има върху него Web Server към който да пращате HTTP Request-и
* да стартира Access Point

А също така и малко базова информация:

* какво е МикроКонтролер
* защо ESP8266
* анатомия на скеч на Ардуино

# Drivers
За Черните и Дългите платки - не би трябвало да има нужда от драйвер (квадратния USB2Serial чип)
За Жълтите и Сините - трябва драйвера

# Blink Example
Load from File -> Examples -> ESP8266 -> Blink

* За Жълтите платки - Да се избере тип платка (Node MCU 0.9)заменете LED_BUILTIN с 1
* За Черните платки - Да се избере тип платка (Node MCU 1.0) - нищо не се заменя
* За Сините  платки - Да се избере тип платка (Wemos D1 R2 & Mini), да се свали upload speed на 115200 - нищо не се заменя в кода
* За Дългите платки с Батерия - Тип тип платка може да се избере - Node MCU 1.0, или да се смени LED_BUILTIN на 16