//ESP32 S3 Code for Plant Pod Project
//Sam Baker - 2026

#define LED_PIN 9
#define INPUT_PIN 7

#define USE_ANALOG 0
#define ANALOG_THRESHOLD 1024

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  int read = -1;
  read = USE_ANALOG ? analogRead(INPUT_PIN) : digitalRead(INPUT_PIN);
  if (read != -1) handle_read(read);

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
  if ((read_value < ANALOG_THRESHOLD && USE_ANALOG) || (read_value == 0))
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}
