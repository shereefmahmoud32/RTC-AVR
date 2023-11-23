/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: ahmed saeed
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "GIE.h"
#include "DIO_interface.h"
#include "KYEPAD.h"
#include "LCD.h"
#include "Timer2.h"
#include "SEVENSEGMENT.h"
#include "util/delay.h"


uint8 u8CursorPos=0;
uint8 u8arrClk[3];
uint8 arr[8]={'0','0',':','0','0',':','0','0'};
sint8 HR,MN,SC;
uint8 flag=1;
uint8 flag1=0;
void print_lcd()
{
	uint8 i=0;
	LCD_voidMoveCourser(0,1,0);
	for(i=0;i<8;i++)
	{
		if(i==2 || i==5)
		{
			/* donothing*/
		}
		else
		{
			arr[i]='0';

		}
		LCD_voidSendChar(0,arr[i]);
	}
	u8CursorPos=0;

	LCD_voidMoveCourser(0,1,u8CursorPos);

}

void scan(uint8 arr[])
{
	u8arrClk[0]=((arr[0]-'0')*10)+(arr[1]-'0');
	u8arrClk[1]=((arr[3]-'0')*10)+(arr[4]-'0');
	u8arrClk[2]=((arr[6]-'0')*10)+(arr[7]-'0');
	HR=u8arrClk[0];
	MN=u8arrClk[1];
	SC=u8arrClk[2];
}
void SEC(void)
{
	SC++;
	//DIO_enuWritePin(DIO_PIN_NUM_B3,flag);
	//flag=!flag;
	fun();
}
void Seven_Seg(void)
{
	SEV_enuDisplay(0,HR/10);
	SEV_enuEnable(0);
	_delay_ms(5);
	SEV_enuDisable(0);

	SEV_enuDisplay(1,HR%10);
	SEV_enuEnable(1);
	_delay_ms(5);
	SEV_enuDisable(1);

	SEV_enuDisplay(2,MN/10);
	SEV_enuEnable(2);
	_delay_ms(5);
	SEV_enuDisable(2);

	SEV_enuDisplay(3,MN%10);
	SEV_enuEnable(3);
	_delay_ms(5);
	SEV_enuDisable(3);

	SEV_enuDisplay(4,SC/10);
	SEV_enuEnable(4);
	_delay_ms(5);
	SEV_enuDisable(4);

	SEV_enuDisplay(5,SC%10);
	SEV_enuEnable(5);
	_delay_ms(5);
	SEV_enuDisable(5);
}
volatile void fun (void)
{
	if(SC>59)
	{
		SC=0;
		MN++;
	}
	if(MN>59)
	{
		MN=0;
		HR++;
	}
	if(HR>23)
	{
		HR=0;

	}
}

void main (void)
{

	DIO_voidInit();
	LCD_voidInit();
	KPD_voidInit();
	GIE_voidEnable();
 	TIM2_voidInit();
    TIM2_ExtClkEnable();
    TIM2_voidSetCallBackOvfInt(SEC);
    TIM2_voidEnable(TIM2_PRESCALER_128);
	uint8 u8key=0xff;
	LCD_voidSendString(0,"HR:MN:SC");
	LCD_voidMoveCourser(0,1,u8CursorPos);
	print_lcd(arr);



	while(1)
	{


		u8key=KPD_u8GetPressedKey();

		if(u8key=='+')
		{

			if(u8CursorPos==7)
			{
				//do nothing
			}
			else
			{
				u8CursorPos++;
			}
			LCD_voidMoveCourser(0,1,u8CursorPos);

		}
		else if(u8key=='-')
		{
			if(u8CursorPos==0)
			{
				//do nothing
			}
			else
			{
				u8CursorPos--;
			}

			LCD_voidMoveCourser(0,1,u8CursorPos);
		}
		else if(u8key=='/')
		{
			if(arr[u8CursorPos]=='0' || arr[u8CursorPos]==':')
			{
				//do nothing
			}
			else
			{
				arr[u8CursorPos]--;

			}

			LCD_voidSendChar(0,arr[u8CursorPos]);
			LCD_voidMoveCourser(0,1,u8CursorPos);
		}

		else if(u8key=='*')
				{
					if(arr[u8CursorPos]==':')
					{
						//do nothing
					}
					else
					{
						if(u8CursorPos==0)
						{
							arr[u8CursorPos]++;
							if(arr[u8CursorPos] >'2')
								arr[u8CursorPos]='2';

						}
						else if(u8CursorPos==1)
						{
							arr[u8CursorPos]++;
							if(arr[u8CursorPos] >'3')
								arr[u8CursorPos]='3';

						}
						else if(u8CursorPos==3)
						{
							arr[u8CursorPos]++;
							if(arr[u8CursorPos] >'5')
								arr[u8CursorPos]='5';

						}
						else if(u8CursorPos==4)
						{
							arr[u8CursorPos]++;
							if(arr[u8CursorPos] >'9')
								arr[u8CursorPos]='9';

						}
						else if(u8CursorPos==6)
						{
							arr[u8CursorPos]++;
							if(arr[u8CursorPos] >'5')
								arr[u8CursorPos]='5';

						}
						else if(u8CursorPos==7)
						{
							arr[u8CursorPos]++;
							if(arr[u8CursorPos] >'9')
								arr[u8CursorPos]='9';

						}



					}
					LCD_voidSendChar(0,arr[u8CursorPos]);
					LCD_voidMoveCourser(0,1,u8CursorPos);
				}
		else if(u8key=='C')
		{
			print_lcd();
		}
		else if (u8key=='=' || flag1)
		{
            if(flag1==0)
            {
			scan(arr);
			TIM2_voidEnableOvfINt();
			flag1=1;
            }
            if(flag1==1)
            {
            	Seven_Seg();
            }
		}
	}
}
