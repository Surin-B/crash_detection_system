// Example By ArduinoAll www.arduinoall.com
// VCC - 3.3-5V
// GND - GND
// OUT - A0
void setup() {
Serial.begin(9600);
Serial.println("Start Sound Detect");
}
 
void loop() {
int mic = analogRead(A0);
//Serial.println(mic); // แสดงระดับความดัง
if (mic > 750) { // ถ้าดังเกินกว่า 750 ให้แสดงข้อความ
Serial.println("ArduinoAll Click");
Serial.println(mic); // แสดงระดับความดัง
delay(50);
}
}
