//#include <Wire.h>

//#include <Keypad.h>

#include <LiquidCrystal.h>


// Adafruit_LiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
LiquidCrystal lcd(13,12,11,10,9,8);

//13 RS 12 E 11 D4, 10 D3 9 D2 8 D1
//7 Left mot pin key pad 
//3 speaker 
// 4 pir 
//right most pin on pad goes to 0 

//rows for keypad 
const int r1=7;
const int r2=6;
const int r3=5;
//const int r4=4;
//columns 
const int c1=2;
const int c2=1;
const int c3=0;

//piezo buzzer 
 const int buzzerPin = 3;
 int alarmStartTime = 0;
 
 //Motion sensor 
 //When PIR motion sensor and when it is triggered the LED light will turn on
 const int pirPin = 4;
 bool pir = false;

const int passwordLength =4;
int passwordCount =0;
int passwordCountDisarm =0;

bool systemArmed = false;
bool alarmActive = false;

bool alarmDisarm = false;
bool alarmSounding = false;

char password [5] ={ '1,2,3,4' };
char Data[5];

void setup()
{
  
  lcd.begin(16 , 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to your");
  lcd.setCursor(0,1);
  lcd.print("Security System.");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Initializing");
  lcd.setCursor(0,1);
  lcd.print("System...");
  
  for(int i = 200; i<10000; i++){
    tone(buzzerPin,i);
    if(i<3500){
    }else if(i<6500){
    }else{
    }
  }
  noTone(buzzerPin);
  delay(3000);
  lcd.clear();

  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
//  pinMode(r4,OUTPUT);
  pinMode(c1,INPUT);
  pinMode(c2,INPUT);
  pinMode(c3,INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin,INPUT);
  
}



void loop()

{
  pir = digitalRead(pir);

  
  alphkeypad();
  
  //systemArmed = true after user enters in password. alarmActive is initialized as false and set to true when the pir sensor reads motion
    if(systemArmed && !alarmActive)
    {
      alarmActive = (digitalRead(pirPin)==HIGH);
      alarmStartTime = millis();
    }

    if(alarmActive)
    {
      soundAlarm();
    }
    
    if(alarmActive)
    {
      disarmAlarm();
    }
}



void alphkeypad()
{
  if(!systemArmed)
 {
  
  lcd.setCursor(0,0);
  lcd.print("Enter Password: ");

  
  while(passwordCount < passwordLength)
  {
  
      digitalWrite(c1,HIGH);  
      digitalWrite(c2,HIGH);
      digitalWrite(c3,HIGH);
      digitalWrite(r1,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c1)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('1');
        Data[passwordCount] ='1';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
      
      if(digitalRead(c2)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('2');
        Data[passwordCount] ='2';
        passwordCount++;
        delay(500);
      }
      
      digitalWrite(r1,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c3)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('3');
        Data[passwordCount] ='3';
        passwordCount++;     
        delay(500);
      }
    
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c1)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('4');
        Data[passwordCount] ='4';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c2)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('5');
        Data[passwordCount] ='5';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      digitalWrite(r3,HIGH);
      
      if(digitalRead(c3)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('6');
        Data[passwordCount] ='6';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,LOW);
  
      if(digitalRead(c1)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('7');
        Data[passwordCount] ='7';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,LOW);
  
      if(digitalRead(c2)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('8');
        Data[passwordCount] ='8';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,LOW);
      //digitalWrite(r4,HIGH);
  
      if(digitalRead(c3)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('9');
        Data[passwordCount] ='9';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
      
      if(digitalRead(c1)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('*');
        Data[passwordCount] ='*';
        passwordCount++;
        delay(500);
      }
 
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c2)==LOW)
      {
        lcd.setCursor(passwordCount,1);
        lcd.print('0');
        Data[passwordCount] ='0';
        passwordCount++;
        delay(500);
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c3)==LOW)
      {
        lcd.setCursor(passwordCount,1); 
        lcd.print('#');
        Data[passwordCount] ='#';
        passwordCount++;
        delay(500);
      }
  
    }//WHILE ENDING
    
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password Saved!!");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Arming System...");
    delay(3000);
    lcd.clear();
   } //end If statement
    systemArmed = true;
}//KEYPAD  ENDING

void soundAlarm(){
  alarmSounding =true;
  
  if((millis()- alarmStartTime)<500){
    tone(buzzerPin,2500);
  }else if((millis()-alarmStartTime)<1000){
    noTone(buzzerPin);
  }else{
    alarmStartTime = millis();
  }
}

void disarmAlarm()
{    
   if(alarmSounding)
   {
      for(int i =0; i<passwordLength;i++)
     {
       
      digitalWrite(c1,HIGH);  
      digitalWrite(c2,HIGH);
      digitalWrite(c3,HIGH);
      digitalWrite(r1,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH); 
    
    
      if(digitalRead(c1)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
        {
          lcd.setCursor(passwordCountDisarm,1);
          lcd.print('1');
          passwordCountDisarm++;
          delay(200);
        }
      }
  
      digitalWrite(r1,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
      
      if(digitalRead(c2)==LOW)
      {
       if(Data[passwordCountDisarm] = password[i])
       {

        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('2');
        passwordCountDisarm++;
        delay(200);
        }
      }
      
      digitalWrite(r1,LOW);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c3)==LOW)
      {
       if(Data[passwordCountDisarm] = password[i])
       { 
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('3');
        passwordCountDisarm++;  
        delay(200);   
        }
      }
    
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c1)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('4');
        passwordCountDisarm++;
        delay(200);
        }
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c2)==LOW)
      {
        if(Data[passwordCount] = password[i])
       {
        lcd.setCursor(passwordCount,1);
        lcd.print('5');
        passwordCount++;
        delay(200);
        }
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
      digitalWrite(r3,HIGH);
      
      if(digitalRead(c3)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('6');
        passwordCountDisarm++;
        delay(200);
        }
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,LOW);
  
      if(digitalRead(c1)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('7');
        passwordCountDisarm++;
        delay(200);
        }
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,LOW);
  
      if(digitalRead(c2)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('8');
        passwordCountDisarm++;
        delay(200);
        }
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,LOW);
  
      if(digitalRead(c3)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('9');
        passwordCountDisarm++;
        delay(200);
        }
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
      
      if(digitalRead(c1)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('*');
        passwordCountDisarm++;
        delay(200);
        }
      }
 
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c2)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.setCursor(passwordCountDisarm,1);
        lcd.print('0');
        passwordCountDisarm++;
        delay(200);
        }
      }
  
      digitalWrite(r1,HIGH);
      digitalWrite(r2,HIGH);
      digitalWrite(r3,HIGH);
  
      if(digitalRead(c3)==LOW)
      {
        if(Data[passwordCountDisarm] = password[i])
       {
        lcd.print('#');
        passwordCountDisarm++;
        delay(200);
        }
      }
     }// end for loop
     alarmSounding = false; 
   }// end alarmSounding if 
   else 
   {
    alarmActive = false;
    systemArmed = false;
    noTone(buzzerPin);
    lcd.clear();
   }
}// end disarm alarm method




