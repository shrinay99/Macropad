#define COPY_BTN 5
#define PASTE_BTN 4
#define UNDO_BTN 14
#define REDO_BTN 12
#define PRINT_BTN 13
#define SS_BTN 0

#define ENC_CLK 2
#define ENC_DT 3  // RX (GPIO3)

int lastClk = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(COPY_BTN, INPUT_PULLUP);
  pinMode(PASTE_BTN, INPUT_PULLUP);
  pinMode(UNDO_BTN, INPUT_PULLUP);
  pinMode(REDO_BTN, INPUT_PULLUP);
  pinMode(PRINT_BTN, INPUT_PULLUP);
  pinMode(SS_BTN, INPUT_PULLUP);

  pinMode(ENC_CLK, INPUT_PULLUP);
  pinMode(ENC_DT, INPUT_PULLUP);
  
  lastClk = digitalRead(ENC_CLK);
}

void loop() {
  if (digitalRead(COPY_BTN) == LOW) {
    Serial.println("COPY_ACTION");
    delay(300);
  }
  if (digitalRead(PASTE_BTN) == LOW) {
    Serial.println("PASTE_ACTION");
    delay(300);
  }
  if (digitalRead(UNDO_BTN) == LOW) {
    Serial.println("UNDO_ACTION");
    delay(300);
  }
  if (digitalRead(REDO_BTN) == LOW) {
    Serial.println("REDO_ACTION");
    delay(300);
  }
  if (digitalRead(PRINT_BTN) == LOW) {
    Serial.println("PRINT_ACTION");
    delay(300);
  }
  if (digitalRead(SS_BTN) == LOW) {
    Serial.println("SS_ACTION");
    delay(300);
  }

  int currentClk = digitalRead(ENC_CLK);
  if (currentClk != lastClk && currentClk == LOW) {
    if (digitalRead(ENC_DT) != currentClk) {
      Serial.println("VOLUME_UP");
    } else {
      Serial.println("VOLUME_DOWN");
    }
    delay(100);
  }
  lastClk = currentClk;
}
