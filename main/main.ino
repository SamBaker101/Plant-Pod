//ESP32 S3 Code for Plant Pod Project
//Sam Baker - 2026

#define LED_PIN 9
#define ANALOG_PIN 7

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(ANALOG_PIN, INPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  int analog_read = -1;
  analog_read = analogRead(ANALOG_PIN);
  if (analog_read != -1) handle_read(analog_read);

  delay(100);
}

int get_read(){
  int input = -1;
  while (Serial.available() > 0){
    if (input != -1) input = input*10;
    else input = 0;
    
    input += Serial.readString().toInt();
  }
  return input;
}

void handle_read(int read_value){
  Serial.println(read_value);
  if (read_value < 1024)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}
