/*
 *  rdxdt's Arcade Joystick firmware v: 1.0.0.0 
 *  by Rodrigo P.(a.k.a. rdxdt)
 *  Configure your emulator to the keys according the definitions below 
 */

//Library includes
#include <Joystick.h>

//Definitions of the buttons
#define btnStart 15 // p
#define btnSelect 16 //s 
#define btnL 14 //l
#define btnR 10 //r
#define btnDown  9 //down key
#define btnLeft  8 //left key
#define btnUp  7 //up key
#define btnRight 6 //right key
#define btnA 2 //a
#define btnB 3 //b
#define btnX 4 //x
#define btnY 5 //y

/*
 * Note: i skipped the 11,12,13 pins because on my ATMEGA32u4 dev board only i really don't know where they are located
 */

#define BTN_COUNT  16
#define BTN_LOW  2



//button state holders
bool currentButtonState[BTN_COUNT+1] ; 
bool lastButtonState[BTN_COUNT+1] ;
int i ;

Joystick_ Joystick;

void setup() {
  Joystick.begin(); //start joystick interface
  Joystick.setXAxis(256);
  Joystick.setYAxis(256);
  Serial.begin(9600); //Start USB UART interface
  for(i = BTN_LOW; i <= BTN_COUNT;i++){
    pinMode(i,INPUT_PULLUP); //SET THE I/O PINS TO INPUT WITH A INTERNAL PULLUP RESISTOR
    currentButtonState[i] = false; //Initialize the button status (false = not pressed);
    lastButtonState[i] = false;//Initialize the button status (false = not pressed);
  } 
}

void loop() { 
  for(i = BTN_LOW; i <= BTN_COUNT;i++){
    lastButtonState[i] = currentButtonState[i]; //Store the old states
    currentButtonState[i] = digitalRead(i) == LOW;//Pool the button state and store it in memory, since we are using "active low" then we need to compare to low see if the button is active(true)
    if( currentButtonState[i] && !lastButtonState[i] ){//if the button is pressed now and was not pressed
      switch(i){ //check which button we need to change the state to pressed
        case btnLeft:
          Joystick.pressButton(btnLeft);
         break;
       case btnDown:
          Joystick.pressButton(btnDown);
         break;
       case btnUp:
          Joystick.pressButton(btnUp);
         break;
       case btnRight:
          Joystick.pressButton(btnRight);
         break;
       case btnA:
          Joystick.pressButton(btnA);
         break;
       case btnB:
          Joystick.pressButton(btnB);
         break;
       case btnX:
          Joystick.pressButton(btnX);
         break;
       case btnY:
          Joystick.pressButton(btnY);
         break;
       case btnL:
          Joystick.pressButton(btnL);
         break;
       case btnR:
          Joystick.pressButton(btnR);
         break;
       case btnSelect:
          Joystick.pressButton(btnSelect);
         break;
       case btnStart:
          Joystick.pressButton(btnStart);
         break;
      }     
    }
    else if(!currentButtonState[i] && lastButtonState[i]){ //check if the button is 
      switch(i){ //check which button we need to change the state to released
        case btnLeft:
          Joystick.releaseButton(btnLeft);
         break;
       case btnDown:
          Joystick.releaseButton(btnDown);
         break;
       case btnUp:
          Joystick.releaseButton(btnUp);
         break;
       case btnRight:
          Joystick.releaseButton(btnRight);
         break;
       case btnA:
          Joystick.releaseButton(btnA);
         break;
       case btnB:
          Joystick.releaseButton(btnB);
         break;
       case btnX:
          Joystick.releaseButton(btnX);
         break;
       case btnY:
          Joystick.releaseButton(btnY);
         break;
       case btnL:
          Joystick.releaseButton(btnL);
         break;
       case btnR:
          Joystick.releaseButton(btnR);
         break;
       case btnSelect:
          Joystick.releaseButton(btnSelect);
         break;
       case btnStart:
          Joystick.releaseButton(btnStart);
         break;
      }  
    }
  }
}
