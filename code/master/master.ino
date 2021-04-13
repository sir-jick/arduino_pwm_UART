// turning on a 12v DC motor via SERIAL COMMUNICATION using : arduino uno , L298 , pwm wave
// owner : Abolfazl Safaiy pour
// student number : 95211030
// master : eng, Aeen mehr
// date of construction : 1400 / 01 / 23  == Monday April 12, 2021
// This code is to control the speed of a DC motor by a potentiometer using l298n driver
// over serial communication


int pot_value = 0;
#define pot_pin A0

int pot_read_serial_min = 0;
int pot_read_serial_max = 1023;
int pwm_min = 0;
int pwm_max = 255;
int pwm = 0;


void setup() {

  Serial.begin(9600); // Begin the Serial at 9600 Baud

}

void loop() {
  pot_value = analogRead(pot_pin);
  pwm = map(pot_value, pot_read_serial_min, pot_read_serial_max, pwm_min, pwm_max);
  // convert 1023 bits to 255 because serial can not handle 1023 
  Serial.write(pwm); // Write the serial data
  delay(10); // every 10 miliseconds repeat the program
}