#include "common.h"

unsigned int crc16(unsigned char *daBuf,unsigned char len)//ANSI CRC-16,x16 + x15 + x2 + 1
{  
   unsigned char BitFg;
   unsigned char  i,j;
   unsigned char hi,lo;
   unsigned int  nCRC = 0xffff; 
   for(j=0;j<len;j++)
   {  
      nCRC ^= daBuf[j];
      for(i=0;i<8;i++)
      {
         BitFg = nCRC&0x1;
         nCRC>>= 1;  
         if(BitFg==1)
            nCRC ^= 0xA001;
        }
    }

	hi=nCRC%256;
	lo=nCRC/256;
	nCRC=(hi<<8)|lo;

    return(nCRC);   /*return ((CRC>>8)+(CRC<<8)); 应用时可高在先 */
}
