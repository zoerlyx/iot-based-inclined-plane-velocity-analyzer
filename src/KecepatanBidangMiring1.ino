#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// PINS
#define TRIG_PIN 8
#define ECHO_PIN 9
#define IR_PIN 4
#define LED_PIN 7

// LCD
LiquidCrystal_I2C lcd(0x27,16,2);

// TIMERS
unsigned long lastLCDUpdate = 0;
const unsigned long LCD_INTERVAL = 5000; // 5 detik

// STATE
float prevPos_m = 0.0;     // posisi sebelumnya (m)
float prevVel = 0.0;       // kecepatan sebelumnya (m/s)

const float MAX_RANGE_CM = 75.0;  // batas lintasan baru

// helper baca ultrasonic (cm)
float readUltrasonicCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long dur = pulseIn(ECHO_PIN, HIGH, 30000UL); // timeout 30ms
  if (dur == 0) return -1.0; // timeout
  return (dur * 0.0343) / 2.0;
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Ready mengukur");
  delay(1000);
  lcd.clear();

  // inisialisasi posisi awal aman
  float d = readUltrasonicCm();
  if (d > 0 && d <= MAX_RANGE_CM) {
    prevPos_m = d / 100.0;
  }
}

// main loop
void loop() {
  // IR indicator
  int irState = digitalRead(IR_PIN);
  digitalWrite(LED_PIN, irState == LOW ? HIGH : LOW);

  unsigned long now = millis();
  float d_cm = readUltrasonicCm(); // bisa -1 jika timeout
  bool inRange = (d_cm >= 0.0 && d_cm <= MAX_RANGE_CM);

  // waktu sampling
  static unsigned long lastSampleTime = 0;
  unsigned long currentSampleTime = now;

  float dt = 0.1; // default dt jika belum ada data
  if (lastSampleTime != 0) dt = (currentSampleTime - lastSampleTime) / 1000.0;
  if (dt <= 0) dt = 0.1;

  float pos_m = prevPos_m;

  if (inRange) {
    pos_m = d_cm / 100.0;
  }

  // ========== HITUNG KECEPATAN (m/s) ==========
  float vel = prevVel;
  if (inRange) {
    float rawVel = (prevPos_m - pos_m) / dt; // arah negatif = menjauh
    // smoothing velocity
    static float vel_f = 0;
    const float alpha = 0.3;
    vel_f = alpha * rawVel + (1 - alpha) * vel_f;
    vel = vel_f;
  }

  // ========== HITUNG PERCEPATAN (m/s^2) ==========
  float acc = (vel - prevVel) / dt;

  // update nilai sebelumnya hanya jika valid
  lastSampleTime = currentSampleTime;
  if (inRange) {
    prevPos_m = pos_m;
    prevVel = vel;
  }

  // UPDATE LCD tiap 5 detik
  if (now - lastLCDUpdate >= LCD_INTERVAL) {
    lastLCDUpdate = now;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("v:"); lcd.print(vel, 2);
    lcd.print(" s:");
    if (d_cm < 0) lcd.print("---");
    else {
      if (d_cm > MAX_RANGE_CM) lcd.print("OUT");
      else lcd.print(d_cm, 0);
    }

    lcd.setCursor(0,1);
    lcd.print("a:");
    lcd.print(acc, 2);

    // Serial log
    Serial.print("d_cm: ");
    if (d_cm < 0) Serial.print("TIMEOUT");
    else Serial.print(d_cm,1);
    Serial.print(" | v: "); Serial.print(vel,3);
    Serial.print(" | a: "); Serial.println(acc,3);
  }

  delay(100);
}
