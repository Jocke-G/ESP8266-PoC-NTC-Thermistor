# ESP8266 - Proof of Concept - NTC Thermistor

A proof of Concept for connecting a NTC thermistor to a ESP8266.

## How to connect

Simple voltage divider

    +--- 3v3
    |
    $ R1
    |
    +--- A0
    |
    $ Thermistor
    |
    +--- GND

## NTC 150

|  °C   |  Ω     |
|-------|--------|
|  -30  |  1884  |
|  -25  |  1443  |
|  -20  |  1115  |
|  -15  |   868  |
|  -10  |   681  |
|   -5  |   538  |
|   ±0  |   428  |
|    5  |   343  |
|   10  |   276  |
|   15  |   224  |
|   20  |   183  |
|   25  |   150  |
|   30  |   124  |
|   35  |   103  |
|   40  |    86  |

https://www.thinksrs.com/downloads/programs/therm%20calc/ntccalibrator/ntccalculator.html

β coefficient: 3335.46K

A: 0.001951203678

B: 0.0002747041896

C: 0.0000002096215130

## Wemos D1

Pinout:
https://www.wemos.cc/en/latest/d1/d1_mini.html#pin

## References

https://en.wikipedia.org/wiki/Thermistor

https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation

https://learn.adafruit.com/thermistor/using-a-thermistor

https://blog.meteodrenthe.nl/2022/08/07/getting-accurate-ntc-thermistor-readings-with-a-wemos-d1-mini/

https://blog.meteodrenthe.nl/2022/09/07/the-b-parameter-vs-steinhart-hart-equation/

https://www.daycounter.com/Calculators/Steinhart-Hart-Thermistor-Calculator.phtml

https://forum.arduino.cc/t/steinhart-hart-reverse-equation/396226/34
