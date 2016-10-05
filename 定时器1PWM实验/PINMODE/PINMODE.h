#ifndef __PINMODE_H_
#define __PINMODE_H_
#include "ioCC2530.h"
    typedef enum PWM_PIN_NUM_t
    {
      PWM_P0_2,
      PWM_P0_3,
      PWM_P0_4,
      PWM_P0_5,
      PWM_P0_6,
      PWM_P0_7,
      PWM_P1_0,
      PWM_P1_1,
      PWM_P1_2,
   }PWM_PIN_NUM;


/*****************************************************************************
*  ��������  �� pwmPinMode
*  ��������  �� ������1��������ų�ʼ�������ڳ�ʼ��PWMҪ���������
*            ��
*    ����    �� pinnum �� ������
*   ����ֵ   �� ��
******************************************************************************/
    extern void pwmPinMode(PWM_PIN_NUM pinnum);
#endif