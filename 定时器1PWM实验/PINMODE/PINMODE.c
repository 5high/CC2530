#include "PINMODE.h"
#define LED1 P1_0       // P1.0�ڿ���LED1
#define LED2 P1_1       // P1.0�ڿ���LED1



/*****************************************************************************
*  ��������  �� pwmPinMode
*  ��������  �� ������1��������ų�ʼ�������ڳ�ʼ��PWMҪ���������
*            ��
*    ����    �� pinnum �� ������
*   ����ֵ   �� ��
******************************************************************************/

void pwmPinMode(PWM_PIN_NUM pinnum)
{
    switch(pinnum)
    {
    case PWM_P0_2:
      P0DIR |= (1 << 2);           //�˿�1Ϊ���    
      P0SEL |= (1 << 2);           //timer1 ͨ��2ӳ���P1_0
      break;
    case PWM_P0_3:
      P0DIR |= (1 << 3);           //�˿�1Ϊ���    
      P0SEL |= (1 << 3);           //timer1 ͨ��2ӳ���P1_0
      break;
    case PWM_P0_4:
      P0DIR |= (1 << 4);           //�˿�1Ϊ���    
      P0SEL |= (1 << 4);           //timer1 ͨ��2ӳ���P1_0
      break;
    case PWM_P0_5:
      P0DIR |= (1 << 5);           //�˿�1Ϊ���    
      P0SEL |= (1 << 5);           //timer1 ͨ��2ӳ���P1_0
      break;
    case PWM_P0_6:
      P0DIR |= (1 << 6);           //�˿�1Ϊ���    
      P0SEL |= (1 << 6);           //timer1 ͨ��2ӳ���P1_0
      break;
    case PWM_P0_7:
      P0DIR |= (1 << 7);           //�˿�1Ϊ���    
      P0SEL |= (1 << 7);           //timer1 ͨ��2ӳ���P1_0
      break;
    case PWM_P1_0:
      P1DIR |= (1 << 0);           //�˿�1Ϊ���    
      P1SEL |= (1 << 0);           //timer1 ͨ��2ӳ���P1_0
      break;
    case PWM_P1_1:
      P1DIR |= (1 << 1);           //�˿�1Ϊ���    
      P1SEL |= (1 << 1);           //timer1 ͨ��1ӳ���P1_1
      break;
    case PWM_P1_2:
      P1DIR |= (1 << 2);           //�˿�1Ϊ���    
      P1SEL |= (1 << 2);           //timer1 ͨ��1ӳ���P1_1
      break;
    }
  
    
}
