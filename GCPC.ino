#include <Wire.h>
#include "paj7620.h"
#include "DigiKeyboard.h"
 
#define GES_REACTION_TIME		800
#define GES_QUIT_TIME			1000

byte i;

void setup()
{
	uint8_t error = 0;

	error = paj7620Init();			// initialize Paj7620 registers
 
DigiKeyboard.sendKeyStroke(0);
delay (100);

}

void loop()
{
	uint8_t data = 0, data1 = 0, error; 

	error = paj7620ReadReg(0x43, 1, &data);				// Read Bank_0_Reg_0x43/0x44 for gesture result.
	if (!error) 
	{
		switch (data) 									// When different gestures be detected, the variable 'data' will be set to different values by paj7620ReadReg(0x43, 1, &data).
		{
			case GES_RIGHT_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_LEFT_FLAG) 
				{
        DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);
        delay(200);
					//("Right-Left");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					forw ();
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					back ();
					delay(GES_QUIT_TIME);
				}
				else
				{
        DigiKeyboard.sendKeyStroke(KEY_Y, MOD_CONTROL_LEFT);
        delay(200);
					//("Right");
				}          
				break;
			case GES_LEFT_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_RIGHT_FLAG) 
				{
        DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
        delay(200);
					//("Left-Right");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					forw ();
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					back ();
					delay(GES_QUIT_TIME);
				}
				else
				{
        
       DigiKeyboard.sendKeyStroke(KEY_Z, MOD_CONTROL_LEFT);
       delay(200);
					//("Left");
				}          
				break;
				break;
			case GES_UP_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_DOWN_FLAG) 
				{
          DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
          delay(200);
					//("Up-Down");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					forw ();
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					back ();
					delay(GES_QUIT_TIME);
				}
				else
				{
        DigiKeyboard.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
        delay(200);
					//("Up");
				}
				break;
			case GES_DOWN_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_UP_FLAG)
				{
           DigiKeyboard.sendKeyStroke(KEY_A, MOD_CONTROL_LEFT);
           delay(200);
					//("Down-Up");
				}
				else if(data == GES_FORWARD_FLAG) 
				{
					forw ();
					delay(GES_QUIT_TIME);
				}
				else if(data == GES_BACKWARD_FLAG) 
				{
					back ();
					delay(GES_QUIT_TIME);
				}
				else
				{
        DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
        delay(200);
					//("Down");
				}
				break;
			case GES_FORWARD_FLAG:
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_BACKWARD_FLAG) 
				{
					//("Forward-Backward");
					delay(GES_QUIT_TIME);
				}
				else
				{
					forw ();
					delay(GES_QUIT_TIME);
				}
				break;
			case GES_BACKWARD_FLAG:		  
				delay(GES_REACTION_TIME);
				paj7620ReadReg(0x43, 1, &data);
				if(data == GES_FORWARD_FLAG) 
				{
					//("Backward-Forward");
					delay(GES_QUIT_TIME);
				}
				else
				{
					back ();
					delay(GES_QUIT_TIME);
				}
				break;
			case GES_CLOCKWISE_FLAG:
        for (i=0;i<10;i++)
  {
DigiKeyboard.sendKeyStroke(0x52);
delay(200);
  }
				//("Clockwise");
				break;
			case GES_COUNT_CLOCKWISE_FLAG:
        for (i=0;i<10;i++)
  {
DigiKeyboard.sendKeyStroke(0x51);
delay(200);
  }
				//("anti-clockwise");
				break;  
			default:
				paj7620ReadReg(0x44, 1, &data1);
				if (data1 == GES_WAVE_FLAG) 
				{
DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
DigiKeyboard.delay(500);
DigiKeyboard.sendKeyStroke(KEY_ENTER);
delay(200);
					//("wave");
				}
				break;
		}
	}
	delay(200);
}

void forw ()
{
DigiKeyboard.sendKeyStroke(0x4B, MOD_CONTROL_LEFT);
delay(300);
DigiKeyboard.sendKeyStroke(0x4B, MOD_CONTROL_LEFT);
delay(200);
}

void back ()
{
DigiKeyboard.sendKeyStroke(0x4E, MOD_CONTROL_LEFT);
delay(300);
DigiKeyboard.sendKeyStroke(0x4E, MOD_CONTROL_LEFT);
delay(200);
}
