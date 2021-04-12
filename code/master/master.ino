int pot_value = 0;
#define pot_pin A0
// TODO find and replace correct code for master


void setup() {

  Serial.begin(9600);

}

void loop() {
  pot_value = analogRead(pot_pin);
  Serial.println(pot_value);
  delay(1);
}