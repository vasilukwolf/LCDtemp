//Подключение библиотеки для работы с LCD
#include <LiquidCrystal.h>

int minute = 1;
//Объявление обекта подключения LCD
// в номера пинов указаны в порядке
// RS E DB4 DB5 DB6 DB7
LiquidCrystal lcd(13,12,11,10,9,8);

void setup()
{
 // Укажем экрану его размер
 lcd.begin(16,2); 
}

void loop()
{
  float v = analogRead(A0)*5/1024.0;
  float temperature = -14.46*log((10000.0*v)/(5.0)/27315.0);
  //Установка курсора на 1 строку
   lcd.setCursor(0,0);
   lcd.print("Temp ");
   lcd.print(temperature);
   //Установка курсора на 2 строку
   lcd.setCursor(0,1);
   lcd.print("Minute ");
   lcd.print(minute);
   //Задержка
   delay(60000);
   ++minute;
   
}
