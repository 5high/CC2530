#ifndef __TIME1PWM_H_
#define __TIME1PWM_H_
#include "ioCC2530.h"  
  typedef enum PWM_TIME1_LOCALTION_t
  {
      PWM_1_LOCALTION,
      PWM_2_LOCALTION,
  }PWM_TIME1_LOCALTION;
  
  typedef enum PWM_TIME1_CHANNAL_t
  {
      PWM_TIME1_CHANNAL0,
      PWM_TIME1_CHANNAL1,
      PWM_TIME1_CHANNAL2,
      PWM_TIME1_CHANNAL3,
      PWM_TIME1_CHANNAL4,
      
  }PWM_TIME1_CHANNAL;
  
  
/****************************************************************************
* ��    ��: initT1PWM()
* ��    ��: ��������ʱ�䣬������Ƶ��Ϊ250KHz
* ��ڲ���: ��
* ���ڲ���: ��
****************************************************************************/
extern void initT1PWM(unsigned char val);

/*****************************************************************************
*  ��������  �� setTime1Priority
*  ��������  �����ö�ʱ��1�����ȼ����
*            ��
*    ����    �� ��
*   ����ֵ   �� ��
******************************************************************************/
extern void setTime1Priority();


/*****************************************************************************
*  ��������  �� setPWMLocation
*  ��������  �����ö�ʱ��1���������λ��
*            ��
*    ����    �� localtion  �� ������ŵ�λ��
*   ����ֵ   �� ��
******************************************************************************/
extern void setPWMLocation(PWM_TIME1_LOCALTION localtion);


/*****************************************************************************
*  ��������  �� setTime1PWMChannal
*  ��������  ������ͨ����ֵ��������ת��
*            ��
*    ����    �� time_channal��ͨ��
*            �� val         �� ��ֵ
*   ����ֵ   �� ��
******************************************************************************/
extern void setTime1PWMChannal(PWM_TIME1_CHANNAL time_channal,unsigned char val);


#endif