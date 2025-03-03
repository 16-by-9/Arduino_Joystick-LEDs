const int Xpin = A0;
const int Ypin = A1;
const int SWpin = 2;

const int R_pin = 11;  // Red (Down)
const int Y_pin = 10;  // Yellow (Left)
const int G_pin = 6;   // Green (Right)
const int B_pin = 9;   // Blue (Up)
const int W_pin = 3;   // White (Switch Pressed)

const int deadzone = 10;

int Xaxis_neutral, Yaxis_neutral;

void setup() {
  Serial.begin(9600);

  Xaxis_neutral = analogRead(Xpin);
  Yaxis_neutral = analogRead(Ypin);

  pinMode(SWpin, INPUT_PULLUP);
  pinMode(R_pin, OUTPUT);
  pinMode(Y_pin, OUTPUT);
  pinMode(G_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  pinMode(W_pin, OUTPUT);
}

void loop() {
  int Xaxis = analogRead(Xpin);
  int Yaxis = analogRead(Ypin);
  
  // Turn off all LEDs by default
  analogWrite(R_pin, 0);
  analogWrite(Y_pin, 0);
  analogWrite(G_pin, 0);
  analogWrite(B_pin, 0);

  // UP = BLUE
  if (Yaxis <= Yaxis_neutral - deadzone) {
    int intensity = map(Yaxis, Yaxis_neutral - deadzone, 0, 0, 255);
    analogWrite(B_pin, intensity);
  }

  // DOWN = RED
  else if (Yaxis >= Yaxis_neutral + deadzone) {
    int intensity = map(Yaxis, Yaxis_neutral + deadzone, 1023, 0, 255);
    analogWrite(R_pin, intensity);
  }

  // LEFT = YELLOW
  if (Xaxis <= Xaxis_neutral - deadzone) {
    int intensity = map(Xaxis, Xaxis_neutral - deadzone, 0, 0, 255);
    analogWrite(Y_pin, intensity);
  }

  // RIGHT = GREEN
  else if (Xaxis >= Xaxis_neutral + deadzone) {
    int intensity = map(Xaxis, Xaxis_neutral + deadzone, 1023, 0, 255);
    analogWrite(G_pin, intensity);
  }

  // Switch Pressed = WHITE
  if (digitalRead(SWpin) == LOW) {
    digitalWrite(W_pin, HIGH);
  } else {
    digitalWrite(W_pin, LOW);
  }

  // Debug (optional, for sanity check)
  Serial.print("X: "); Serial.print(Xaxis);
  Serial.print(" | Y: "); Serial.print(Yaxis);
  Serial.print(" | SW: "); Serial.println(digitalRead(SWpin) == LOW ? "PRESSED" : "RELEASED");
}