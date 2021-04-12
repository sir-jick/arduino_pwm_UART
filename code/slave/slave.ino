// turning on a 12v DC motor via SERIAL COMMUNICATION using : arduino uno , L298 , pwm wave
// owner : Abolfazl Safaiy pour
// student number : 95211030
// master : eng, Aeen mehr
// date of construction : 1400 / 01 / 23  == Monday April 12, 2021
// This code is to control the speed of a DC motor by a potentiometer using l298n driver
// over serial communication

// TODO find and replace correct code for slave

int input_1 = 4;
int input_2 = 5;
int Enable_channel_A = 6;
int speed_of_channel_A = 0;
int pot_read_serial_min = 0;
int pot_read_serial_max = 1023;
int pwm_min = 0;
int pwm_max = 255;

void setup() {
  pinMode(input_1, OUTPUT);
  pinMode(input_2, OUTPUT);  
  pinMode(Enable_channel_A, OUTPUT); // this pin had to be pwm pin
  Serial.begin(9600);// Begin the Serial at 9600 Baud
}

void loop() {

  digitalWrite(input_1, LOW); // Switch between this input_1 and input_2 ; HIGH and LOW to change direction
  digitalWrite(input_2, HIGH);// these two pin contorls input pins of our motor
 
  speed_of_channel_A = map(*****, pot_read_serial_min, pot_read_serial_max, pwm_min, pwm_max); // convert pot serial value from 1023 bits to 255 bits
  analogWrite(Enable_channel_A,speed_of_channel_A);// Then send it to our motor

}