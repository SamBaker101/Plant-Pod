#define LED_PIN 9

//ESP32 S3 Code for Plant Pod Project
//Sam Baker - 2026

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  int read_data = get_read();
  if (read_data != -1) handle_read(read_data);
  delay(50);
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
  digitalWrite(LED_PIN, HIGH);
  delay(read_value);
  digitalWrite(LED_PIN, LOW);

}
