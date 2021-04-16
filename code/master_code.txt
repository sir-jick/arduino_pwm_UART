// turning on a 12v DC motor via SERIAL COMMUNICATION using : arduino uno , L298 , pwm wave
// owner : Sir_Jick
// date of construction : 1400 / 01 / 23  == Monday April 12, 2021
// This code is to control the speed of a DC motor by a potentiometer using l298n driver
// over serial communication



int pwm = 0;
int pot_value = 0;
int pot_read_serial_min = 0;
int pot_read_serial_max = 1023;
#define pot_pin A0
int pwm_min = 0;
int pwm_max = 255;
int start_button_pin = 5;
bool start_button = 1;

void setup()
  {
    Serial.begin(9600);// Begin the Serial at 9600 Baud
    pinMode(start_button_pin, INPUT_PULLUP);
    
  }

void loop ()
  {
    if (digitalRead(start_button_pin) == 0)
    {
      start_button = !start_button;
      delay(10);
      while (digitalRead(start_button_pin) == 0){};//free wheel loop
      }
    if (start_button == 1 )
    {
      pot_value = analogRead(pot_pin);
      pwm = map(pot_value, pot_read_serial_min, pot_read_serial_max, pwm_min, pwm_max);
      // convert 1023 bits to 255 because serial can not handle 1023
      Serial.write(pwm);// Write the pwm serial data
    }
    if(start_button == 0)
    {
     Serial.write(0);// Write the stop code serial data
    }
    
  }

