/************************************************/
/* Description : SevenSegment config header File*/
/* Author      : ahmed saeed                    */
/* Version     : 0.1V                           */
/* Date        : 10:19:33  05 Aug 2023          */
/* History     : 0.1V Initial Creation          */
/************************************************/

#include "STD_Types.h"
#include "DIO_interface.h"
#include "SEVENSEGMENT_cfg.h"
#include "SEVENSEGMENT_priv.h"



tstrSevenSegConfig SEV_ConfigSet[SEV_MAX_NUM]=
{
		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						  /* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C0,

				COMMON_CATHODE   //20
		}

		,


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						  /* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C1,
				COMMON_CATHODE
		},


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						  /* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C2,
				COMMON_CATHODE
		},


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						  /* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C3,
				COMMON_CATHODE
		},


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						  /* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C4,
				COMMON_CATHODE
		},


		{
				{         /* a*/          /* b*/          /* c*/
						DIO_PIN_NUM_A0,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2,
						  /* d*/         /*e*/            /* f*/
						DIO_PIN_NUM_A3,DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						/* g*/
						DIO_PIN_NUM_A6
				},
				/* common*/
				DIO_PIN_NUM_C5,
				COMMON_CATHODE
		}







};
