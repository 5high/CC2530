/*****************************************************************************
*  ��Ŀ����  �� ��ʱ��1PWMʵ��
*    ����    �� ֣����
*    ʱ��    �� 2016/08/11
******************************************************************************/
#include <ioCC2530.h>
#include "TIME1PWM.h"
#include "PINMODE.h"

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

/****************************************************************************
* ������ں���
****************************************************************************/
void main(void)
{
    pwmPinMode(PWM_P1_0);		         //���ó�ʼ������
    pwmPinMode(PWM_P1_1);		         //���ó�ʼ������
    
    setTime1Priority();
    setPWMLocation(PWM_2_LOCALTION);   //��ʱ��1 ��IOλ��   PWM_2_LOCALTION:����λ��2
    initT1PWM(250);     
    setTime1PWMChannal(PWM_TIME1_CHANNAL1,0);
    setTime1PWMChannal(PWM_TIME1_CHANNAL2,0);
    
    while(1)
    {
     
      
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,0);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,0);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,10);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,20);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,30);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,40);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,60);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,60);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,100);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,90);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,150);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,120);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,180);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,150);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,210);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,170);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,240);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,200);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,250);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,230);
        delayMS(300);
        setTime1PWMChannal(PWM_TIME1_CHANNAL1,250);
        setTime1PWMChannal(PWM_TIME1_CHANNAL2,250);
        delayMS(300);
            
    }
}