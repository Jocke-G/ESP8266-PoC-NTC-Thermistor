// Arduino board
#define ADC_BITS 10
#define THERMISTORPIN A0
#define VOLTAGE 3.3
#define SERIAL_BAUDRATE 115200
#define SERIESRESISTOR 9800 // My 10K resistor seems to be not 10K.

// Thermistor characteristics
#define THERMISTORNOMINAL 150
#define TEMPERATURENOMINAL 25
#define BCOEFFICIENT 3335.46

// Steinhart–Hart coefficients
#define A 1.951203678e-3
#define B 2.747041896e-4
#define C 2.096215130e-7

// Science
#define KELVIN_FREEZING 273.15

#define ADC_MAX float(pow(2,ADC_BITS)-1)

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println("");
  Serial.println("Setup...");

  Serial.println("Setup Completed");
}

void loop(void) {
  float reading = analogRead(THERMISTORPIN);

  Serial.print("Analog reading: ");
  Serial.println(reading);

  float voltage = reading * (VOLTAGE / ADC_MAX);
  Serial.print("Voltage: ");
  Serial.println(voltage);

  float resistance = SERIESRESISTOR/(ADC_MAX/reading-1);  // 10K / (1023/ADC - 1)
  Serial.print("Thermistor resistance: ");
  Serial.println(resistance);

  float bCoefficientTemperature = bCoefficient(resistance);
  Serial.print("B Coefficient Temperature: ");
  Serial.println(bCoefficientTemperature);

  float steinhartTemperature = steinhart(resistance);
  Serial.print("Steinhart Temperature: ");
  Serial.println(steinhartTemperature);

  float reverseSteinhartResistance = reverseSteinhart(steinhartTemperature);
  Serial.print("Reverse Steinhart Resistence: ");
  Serial.println(reverseSteinhartResistance);

  delay(1000);
}


float bCoefficient(float resistance) {
  return 1.0 /((log(resistance / THERMISTORNOMINAL) / BCOEFFICIENT) + 1.0 / (TEMPERATURENOMINAL + KELVIN_FREEZING)) - KELVIN_FREEZING;
}

float steinhart(float resistance){
  return 1 / (A + B * log(resistance) + C * pow(log(resistance), 3)) - KELVIN_FREEZING;     
}

float reverseSteinhart(double temp) {
  float x = (A - 1/(temp + KELVIN_FREEZING))/C;
  float B_C = B/C;
  float y = sqrt(B_C*B_C*B_C/27 + x*x/4);

  return exp(pow(y - x/2,1/3.) - pow(y + x/2,1/3.));
}
