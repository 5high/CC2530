#include "WATCHDOG.h"

void (*WDT_fun)(void);
/*****************************************************************************
*  ��������  �� void initWatchdog(ENUM_WATCHDOG_INTERVAL��ENUM_WATCHDOG_MODE)
*  ��������  �� ����eatchdogInterval��watchdogMode��ʼ�����Ź�
*            ��
*    ����    �� watchdogMode  �� ���Ź�ģʽ
*            �� eatchdogInterval �� ���Ź�ʱ����
*   ����ֵ   �� ��
******************************************************************************/
void initWatchdog(ENUM_WATCHDOG_INTERVAL eatchdogInterval,\
  ENUM_WATCHDOG_MODE watchdogMode)
{
  WDCTL = 0x00;   //����IDLE�������ÿ��Ź�
  WDT_fun = 0;
  switch(eatchdogInterval)
  {
  case WATCHDOG_INTERVAL_1s:
    WDCTL |= (0 << 0);  //����ʱ����
    break;
  case WATCHDOG_INTERVAL_0_25s:
    WDCTL |= (1 << 0);  //����ʱ����
    break;
  case WATCHDOG_INTERVAL_15_625ms:
    WDCTL |= (2 << 0);  //����ʱ����
    break;
  case WATCHDOG_INTERVAL_1_9ms:
    WDCTL |= (3 << 0);  //����ʱ����
    break;
  }
  
  switch(watchdogMode)
  {
  case WATCHDOG_MODE_IDEL:
    WDCTL |= (0 << 2);  //ģʽѡΪ����ģʽ
    break;
  case WATCHDOG_MODE_WATCHDOGMODE:
    WDCTL |= (2 << 2);  //ģʽѡΪ���Ź�
    break;
  case WATCHDOG_MODE_TIMERMODE:
    IEN2 |= (1 << 5);  //ʹ�ܶ�ʱ���ж�
    WDTIF = 0;  //����жϱ�־λ
    EA = 1;
    WDCTL |= (3 << 2);  //ģʽѡΪ��ʱ��ģʽ
    break;
  }

}

#pragma vector = WDT_VECTOR
__interrupt void WDT_ISR(void)
{
  if( WDT_fun != 0)
  {
      WDT_fun();
  }
   WDTIF = 0;  //����жϱ�־λ
}

void setWDTFun(void (*inWDT_fun)(void))
{
  WDT_fun = inWDT_fun;
}


void feetdog(void)
{
  WDCTL = 0xa0;    //�����ʱ������0xA����0x5д����Щλ����ʱ�������
  WDCTL = 0x50;
}
