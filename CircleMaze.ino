//Engine Driver TB6612FNG
#define PWMA 5  //выходы arduino
#define PWMB 6 //
#define AIN1 7
#define AIN2 4
#define BIN1 9 //
#define BIN2 8
//Black Line sensors
#define L A1 // Пин для подключения датчика линии
#define C A2 // Пин для подключения датчика линии
#define R A3 // Пин для подключения датчика линии
//Axel ADXL335
//#define x A0
//#define y A6
//#define z A7
//#define Period 500

unsigned long timing = 0; // перепенная счетчик

uint8_t prevR = 1;    // Предыдущее состояние датчика линии
uint8_t prevC = 1;
uint8_t prevL = 1;

uint8_t curR = 1;     // Текущее состояние датчика линии
uint8_t curC = 1;
uint8_t curL = 1;

uint8_t global = 111; // Текущее состояние системы
bool f = false; // переменная Stop

//int motorSpeed = 500; //  скорость мотора
//int motorSpeedRotate = 400;


void setup() {

  Serial.begin(9600);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  //pinMode(PIN_LED, OUTPUT);
  pinMode(L, INPUT);
  pinMode(C, INPUT);
  pinMode(R, INPUT);

}

void left(int motorSpeedRotate) {
  digitalWrite(AIN1, 0);      // влево
  digitalWrite(AIN2, 1);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
  analogWrite(PWMA, motorSpeedRotate);
  analogWrite(PWMB, motorSpeedRotate);
}


void right(int motorSpeedRotate) {
  digitalWrite(AIN1, 1);      // вправо
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
  analogWrite(PWMA, motorSpeedRotate);
  analogWrite(PWMB, motorSpeedRotate);
}

void backward(int motorSpeed)
{
  digitalWrite(AIN1, 0);      // назад
  digitalWrite(AIN2, 1);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
  analogWrite(PWMA, motorSpeed);
  analogWrite(PWMB, motorSpeed);
}

void forward(int tempspeed)
{   
  tempspeed = motorSpeed;
  digitalWrite(AIN1, 1);      // движение вперед
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
  if(millis() - temptime <= 100)
  {
  temptime = millis();
  tempspeed++;
  analogWrite(PWMA, tempspeed);
  analogWrite(PWMB, tempspeed);
  }
}

void stop(bool f)
{
  if (f)
  {
    digitalWrite(AIN1, 0);      // stop
    digitalWrite(AIN2, 0);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 0);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
  }
}

//void loop() {
//  if ((digitalRead(R)*digitalRead(C)*digitalRead(L)) == 1)
//  {
//    forward();
//  }
//  if ((digitalRead(R) == 0) and (digitalRead(C) == 0) and (digitalRead(R) == 0))
//  {
//    backward();
//    left();
//  }
//  if ((digitalRead(R) == 0) and (digitalRead(C) == 1) and (digitalRead(R) == 1))
//  {
//    right();
//  }
//  if ((digitalRead(R) == 0) and (digitalRead(C) == 0) and (digitalRead(R) == 1))
//  {
//    right();
//  }
//  if ((digitalRead(R) == 1) and (digitalRead(C) == 1) and (digitalRead(R) == 0))
//  {
//    left();
//  }
//  if ((digitalRead(R) == 1) and (digitalRead(C) == 0) and (digitalRead(R) == 0))
//  {
//    left();
//  }
//}

void loop() {
  global = digitalRead(L) * 100 + digitalRead(C) * 10 + digitalRead(R);

  switch (global)
  {
    case 0: // 000
      {
        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {
          break;
        }

        backward(250);
        delay(200);
        left(150);
        delay(400);
      }

    case 111: // 111
      {
        forward(150);

        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {
          Serial.println("Break!");
          break;
        }
        Serial.println("DOne!");
      }

    case 110: // 110
      {
        left(150);

        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {
          break;
        }
      }

    case 11: // 011
      {
        right(150);


        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {
          break;
        }
      }

    case 101: // 101
      {
        backward(200);
        left(150);

        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {
          break;
        }
      }

    case 1: // 001
      {
        right(150);

        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {
          break;
        }
      }

    case 100: // 100
      {
        left(150);

        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {
          break;
        }
      }

    case 10: // 010
      {
        backward(200);
        left(150);

        if (digitalRead(L) + digitalRead(C) + digitalRead(R) == 0)
        {

          break;
        }

      }
    default: {
        break;
      }
  }
  prevR = curR;
  prevL = curL;
  prevC = curC;

  curR = digitalRead(R);
  curC = digitalRead(C);
  curL = digitalRead(L);

}
