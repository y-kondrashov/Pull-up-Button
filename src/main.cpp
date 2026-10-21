#include <Arduino.h>

#define ledPin_red 15
#define ledPin_blue 16
#define buttonPin 14
#define buttonBoot 0

void setup() {
    // Ініціалізація послідовного інтерфейсу для відладки
    Serial.begin(115200);
    delay(1000); // Очікування стабілізації Serial

    pinMode(ledPin_red, OUTPUT);
    pinMode(ledPin_blue, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(buttonBoot, INPUT);
    Serial.println("GPIO система ініціалізована");
}

void loop() {
    // Зчитування стану кнопки
    int buttonState = digitalRead(buttonPin);
    int bootButtonState = digitalRead(buttonBoot);

    // Логіка керування
    if (buttonState == LOW)
    { // Кнопка натиснута
        digitalWrite(ledPin_red, HIGH);
        digitalWrite(ledPin_blue, HIGH);
        delay(200);
        digitalWrite(ledPin_red, LOW);
        digitalWrite(ledPin_blue, LOW);
        delay(200);
        printf("Зовнішня кнопка натиснута - LED увімкнені\n");
    }
    else if (bootButtonState == LOW)
    {
        digitalWrite(ledPin_red, HIGH);
        digitalWrite(ledPin_blue, LOW);
        delay(1000);
        digitalWrite(ledPin_red, LOW);
        digitalWrite(ledPin_blue, HIGH);
        delay(1000);
        printf("Boot кнопка натиснута - LED увімкнені\n");
    }
    else
    { // Кнопка не натиснута
        digitalWrite(ledPin_red, LOW);
        digitalWrite(ledPin_blue, LOW);
        printf("Кнопка звільнена - LED вимкнені\n");
    }

    // Затримка 50 мс
    delay(50);
}