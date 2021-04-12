// turning on a 12v DC motor via SERIAL COMMUNICATION using : arduino uno , L298 , pwm wave
// owner : Abolfazl Safaiy pour
// student number : 95211030
// master : eng, Aeen mehr
// date of construction : 1400 / 01 / 23  == Monday April 12, 2021
// This code is to control the speed of a DC motor by a potentiometer using l298n driver
// over serial communication


int pot_value = 0;
#define pot_pin A0

void setup() {

  Serial.begin(9600); // Begin the Serial at 9600 Baud

}

void loop() {
  pot_value = analogRead(pot_pin);
  Serial.println(pot_value);// print the value of pot reading to serial print terminal
  Serial.write(pot_value); // Write the serial data
  delay(10); // every 10 miliseconds repeat the program
}