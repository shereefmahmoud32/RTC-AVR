/********************************************/
/* Description : SevenSegment private c File*/
/* Author      : ahmed saeed                */
/* Version     : 0.1V                       */
/* Date        : 10:19:33  05 Aug 2023      */
/* History     : 0.1V Initial Creation      */
/********************************************/




#ifndef SEVENSEGMENT_PRIV_H
#define SEVENSEGMENT_PRIV_H

#define  COMMON_ANODE       10
#define  COMMON_CATHODE     20


typedef struct
{
    uint8 au8SevCon[7];
    uint8 u8common;
    uint8 u8ConMode;
}tstrSevenSegConfig;

static void SEV_HexToBin(uint8 u8SevIndexCpy,uint8 u8HexCpy );
extern tstrSevenSegConfig SEV_ConfigSet[SEV_MAX_NUM];


#endif


