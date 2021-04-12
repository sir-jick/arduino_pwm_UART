// turning on a 12v DC motor using : arduino uno , L298 , pwm wave
// owner : Abolfazl Safaiy pour
// student number : 95211030
// master : eng, Aeen mehr
// date of construction : 1400 / 01 / 03  == Tuesday March 23, 2021
// This code is to control the speed of a DC motor by a potentiometer using l298n driver
// TODO find and replace correct code for slave

int input_1 = 4;
int input_2 = 5;
int Enable_channel_A = 6;
int speed_of_channel_A = 0;
int pot_read = 0;
int pot_min = 0;
int pot_max = 1023
int pwm_min = 0;
int pwm_max = 255;

void setup() {
  pinMode(input_1, OUTPUT);
  pinMode(input_2, OUTPUT);  
  pinMode(Enable_channel_A, OUTPUT); // this pin had to be pwm pin
}

void loop() {

  digitalWrite(input_1, LOW); // Switch between this input_1 and input_2 ; HIGH and LOW to change direction
  digitalWrite(input_2, HIGH);// these two pin contorls input pins of our motor
  pot_read = analogRead(A0); // reads the pot value and saves it
  speed_of_channel_A = map(pot_read, pot_min, pot_max, pwm_min, pwm_max); // convert pot value from 1023 bits to 255 bits
  analogWrite(Enable_channel_A,speed_of_channel_A);// Then send it to our motor

}