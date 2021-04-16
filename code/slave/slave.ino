// turning on a 12v DC motor via SERIAL COMMUNICATION using : arduino uno , L298 , pwm wave
// owner : Sir_Jick
// student number : 95211030
// master : eng, Aeen mehr
// date of construction : 1400 / 01 / 23  == Monday April 12, 2021
// This code is to control the speed of a DC motor by a potentiometer using l298n driver
// over serial communication


int input_1 = 4;
int input_2 = 5;
int Enable_channel_A = 6;
int speed_of_channel_A = 0;

void setup() {
  pinMode(input_1, OUTPUT);
  pinMode(input_2, OUTPUT);  
  pinMode(Enable_channel_A, OUTPUT); // this pin had to be pwm pin
  Serial.begin(9600);// Begin the Serial at 9600 Baud
}

void loop() {
 
  while (Serial.available() > 0) {

    digitalWrite(input_1, LOW); // Switch between this input_1 and input_2 ; HIGH and LOW to change direction
    digitalWrite(input_2, HIGH);// these two pin controls input pins of our motor
    // read the incoming byte:
    speed_of_channel_A = Serial.read();
    // save the serial value
    analogWrite(Enable_channel_A,speed_of_channel_A);
    // Then send pwm bits from serial to our motor
    Serial.println("received pwm bits form serial: ");
    Serial.println(speed_of_channel_A);
    
  }

}
