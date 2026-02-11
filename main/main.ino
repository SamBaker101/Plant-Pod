#define LED_PIN 9

int count = 0;
int input = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  input = -1;
  int digit = 0;
  while (Serial.available() > 0){
    if (input != -1) input = input*10;
    else input = 0;
    
    input += Serial.readString().toInt();
  }
  if (input != -1) handle_read(input);
  delay(500);
}

void handle_read(int read_value){
  Serial.println(read_value);
  digitalWrite(LED_PIN, HIGH);
  delay(read_value);
  digitalWrite(LED_PIN, LOW);

}
