#include"STD_Types.h"
#include"BIT_Math.h"
#include"GIE.h"
#include"GIE_priv.h"



void GIE_voidEnable(void)
{
	SET_BIT(SREG,INTEURRPT_PIN);
}


void GIE_voidDisable(void)
{
	CLR_BIT(SREG,INTEURRPT_PIN);
}