#include <LiquidCrystal_IC2.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x23, 20, 2); // set the LCD address to 0x23 for a 16 chars and 2 line display
const int max_length = 100; //maximul sequence length
int sequence[max_length]; //random no. sequence
int current_sequence[max_length]; //current sequence of the game
int current_length = 1; //current length of the game
int score = 0; //a variable to count your score
int variabilaLoc = 0; //ca sa avem continuitate cu secv anterioara
int velocity = 1000; //the default velocity between two consecutive activations of the LEDs

void setup()
{
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(2, INPUT);
    pinMode(3, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    lcd.init(); //lcd initialisation
    lcd.backlight();
    Serial.begin(9600);
}

void loop()
{
    while (digitalRead(2) == HIGH && current_length == 1) //if the start button
//hasn't been pressed and the level is 1 we can set the difficulty
    {
        digitalWrite(3, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Set difficulty");
        lcd.setCursor(0, 1);
        lcd.print("Lvl of dif: ");
        lcd.setCursor(12, 1);
        if (velocity == 100)
            lcd.print("MAX");
        else
            lcd.print(10 - velocity / 100);
        if (digitalRead(7) == LOW) { //if the button is pressed the difficulty changes
            velocity -= 100;
            delay(500);
            if (velocity == 0)
                velocity = 1000;
            Serial.println(velocity);
            lcd.clear();
        }
    }
    void loop() {
        while (digitalRead(2) == HIGH && current_length == 1) //if the start button
//hasn't been pressed and the level is 1 we can set the difficulty
        {
            digitalWrite(3, HIGH);
            lcd.setCursor(0, 0);
            lcd.print("Set difficulty");
            lcd.setCursor(0, 1);
            lcd.print("Lvl of dif: ");
            lcd.setCursor(12, 1);
            if (velocity == 100)
                lcd.print("MAX");
            else
                lcd.print(10 - velocity / 100);
            if (digitalRead(7) == LOW) { //if the button is pressed the difficulty changes
                velocity -= 100;
                delay(500);
                if (velocity == 0)
                    velocity = 1000;
                Serial.println(velocity);
                lcd.clear();
            }
        }

        void show_sequence() {
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            for (int i = 0; i < current_length; i++) {
                digitalWrite(sequence[i], HIGH);
                delay(velocity);
                digitalWrite(sequence[i], LOW);
                delay(400);
            }
        }

        void get_sequence() //in this function we decide if the buttons were pressed
//correctly or not
        {
            int flag = 0; //this flag indicates if a button was pressed
            int timp = millis();
            for (int i = 0; i < current_length; i++) {
                flag = 0;
                while (flag == 0) {
                    if (millis() - timp >= 5000) //if no button is pressed for 5 sec then the
//game resets
                    {
                        wrong_sequence();
                        return;
                    }
                    if (digitalRead(A0) == LOW) {
                        digitalWrite(12, HIGH);
                        current_sequence[i] = 12;
                        flag = 1;
                        delay(500);
                        if (current_sequence[i] != sequence[i]) {
                            wrong_sequence();
                            return;
                        }
                        digitalWrite(12, LOW);
                    }
                    if (digitalRead(A1) == LOW) {
                        digitalWrite(11, HIGH);
                        current_sequence[i] = 11;
                        flag = 1;
                        delay(500);
                        if (current_sequence[i] != sequence[i]) {
                            wrong_sequence();
                            return;
                        }
                        digitalWrite(11, LOW);
                    }
                    if (digitalRead(A2) == LOW) {
                        digitalWrite(10, HIGH);
                        current_sequence[i] = 10;
                        flag = 1;
                        delay(500);
                        if (current_sequence[i] != sequence[i]) {
                            wrong_sequence();
                            return;
                        }
                        digitalWrite(10, LOW);
                    }
                    if (digitalRead(A3) == LOW) {
                        digitalWrite(9, HIGH);
                        current_sequence[i] = 9;
                        flag = 1;
                        delay(500);
                        if (current_sequence[i] != sequence[i]) {
                            wrong_sequence();
                            return;
                        }
                        digitalWrite(9, LOW);
                    }
                }
            }
            correct_sequence();
        }

        void generate_sequence() { //in this function we generate the random sequence
            randomSeed(millis()); //in this way is really random
            for (variabilaLoc; variabilaLoc < max_length; variabilaLoc++) {
                sequence[variabilaLoc] = random(9, 13);//genereaza numere intre 9 si 12
            }
        }

        void wrong_sequence()//in this function we decide the pattern for the wrong pressed
        sequence {
            lcd.clear();
            if (score == 0) //if no buttons were pressed at all
            {
                lcd.setCursor(0, 0);
                lcd.print("Game Over!");
                lcd.setCursor(0, 1);
                lcd.print("No input");
            } else
            {
                lcd.setCursor(0, 0);
                lcd.print("Game Over!");
                lcd.setCursor(0, 1);
                lcd.print("Final Score: ");
                lcd.setCursor(13, 1);
                lcd.print(score);
            }
            for (int i = 0; i < 1; i++)
            {
                digitalWrite(9, LOW);
                digitalWrite(10, LOW);
                digitalWrite(11, LOW);
                digitalWrite(12, LOW);
                delay(200);
                digitalWrite(12, HIGH);
                delay(200);
                digitalWrite(11, HIGH);
                delay(200);
                digitalWrite(10, HIGH);
                delay(200);
                digitalWrite(9, HIGH);
                delay(200);
                digitalWrite(9, LOW);
                digitalWrite(10, LOW);
                digitalWrite(11, LOW);
                digitalWrite(12, LOW);
                delay(200);
                digitalWrite(9, HIGH);
                digitalWrite(10, HIGH);
                digitalWrite(11, HIGH);
                digitalWrite(12, HIGH);
                delay(200);
                digitalWrite(9, LOW);
                digitalWrite(10, LOW);
                digitalWrite(11, LOW);
                digitalWrite(12, LOW);
                delay(2000);
            }
            current_length = 1; //we reset the variables to the initial values
            velocity = 1000;
            score = 0;
            variabilaLoc = 0;
            lcd.clear();
        }
        void correct_sequence()//in this function we decide the pattern for the correct
        pressed sequence {
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            delay(500);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            delay(1000);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            delay(500);
            if (current_length < max_length); //if the sequence hasn't reached the maximum
//limit the game continues
            current_length++;
            score++;
        }
