/*****************************************************************************
*  ��Ŀ����  �� AD�ɼ�cc2530�¶ȴ�����ʾ
*    ����    �� ֣����
*    ʱ��    �� 2016/08/06
******************************************************************************/


/*****************************************************************************
*  ���ͷ�ļ�
******************************************************************************/
#include <ioCC2530.h>
#include "INTUART.h"
#include <stdio.h>
#include <string.h>
#include "ADC.h"
#include "LED.h"
/*****************************************************************************
*�������壺����ȷ�ӳٺ���
*�����������ӳٺ�����
*  ����ֵ���޷���ֵ
*****************************************************************************/
void delayMS(int ms)
{
  int i,j;
  for(i = 0; i < ms; i++)
  {
    for(j = 0; j < 535; j++);
  }
}

void main()
{
    float AvgTemp;
    char strTemp[7];
    setSystemCLK();
    initUart();
    ledInit();
    while(1)
    {
        
//TEMP��12λ�ֱ��ʣ��ο���ѹΪAVDD5
/*        AvgTemp = getChannalValue(TEMP,BIT12,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A12",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT10,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A10",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT9,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A09",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT7,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A07",3);
        sendNewLine();
        delayMS(3000);
        
        AvgTemp = getChannalValue(TEMP,BIT12,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A12",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT10,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A10",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT9,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A09",3);
        sendNewLine();
        delayMS(1000);
        
        AvgTemp = getChannalValue(TEMP,BIT7,INTERNAL_REFERENCE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendString("A07",3);
        sendNewLine();
        delayMS(3000);
*/    
        AvgTemp = getChannalValue(AIN5,BIT12,AVDD5_PIN_VOLTAGE);
        memset(strTemp,0,sizeof(strTemp));
        sprintf(strTemp,"%.02f",AvgTemp);
        sendString(strTemp,5);
        sendNewLine();
        delayMS(100);
    }
}
