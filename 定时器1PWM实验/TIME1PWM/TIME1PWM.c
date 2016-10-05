#include "TIME1PWM.h"


/*****************************************************************************
*  ��������  �� setPWMLocation
*  ��������  �����ö�ʱ��1���������λ��
*            ��
*    ����    �� localtion  �� ������ŵ�λ��
*   ����ֵ   �� ��
******************************************************************************/

void setPWMLocation(PWM_TIME1_LOCALTION localtion)
{
    switch(localtion)
    {
    case PWM_1_LOCALTION:
       PERCFG &= ~(1 << 6);    //��ʱ��1 ��IOλ��   PWM_1_LOCALTION:����λ��1
    case PWM_2_LOCALTION:
       PERCFG |= (1 << 6);    //��ʱ��1 ��IOλ��   PWM_2_LOCALTION:����λ��2 
    }
}



/*****************************************************************************
*  ��������  �� setTime1Priority
*  ��������  �����ö�ʱ��1�����ȼ����
*            ��
*    ����    �� ��
*   ����ֵ   �� ��
******************************************************************************/

void setTime1Priority()
{
    P2SEL &= ~0x10;          //��ʱ��1����
    P2DIR |= 0xC0;           //��1���ȼ�����ʱ��1ͨ��2-3
}

/****************************************************************************
* ��    ��: initT1PWM()
* ��    ��: ��������ʱ�䣬������Ƶ��Ϊ250KHz
* ��ڲ���: ��
* ���ڲ���: ��
****************************************************************************/
void initT1PWM(unsigned char val)
{
    CLKCONCMD &= ~0x40;      //����ϵͳʱ��ԴΪ32MHZ����
    while(CLKCONSTA & 0x40); //�ȴ������ȶ�Ϊ32M
    CLKCONCMD &= ~0x07;      //����ϵͳ��ʱ��Ƶ��Ϊ32MHZ   
    CLKCONCMD |= 0x38;       //ʱ���ٶ�32 MHz ��ʱ������������[5:3]250kHz
    
    T1CC0H = 0x00;           
    T1CC0L = val;           //����PWM����  
      
    T1CTL = 0x02;            //250KHz 1��Ƶ
}


/*****************************************************************************
*  ��������  �� setTime1PWMChannal
*  ��������  ������ͨ����ֵ��������ת��
*            ��
*    ����    �� time_channal��ͨ��
*            �� val         �� ��ֵ
*   ����ֵ   �� ��
******************************************************************************/

void setTime1PWMChannal(PWM_TIME1_CHANNAL time_channal,unsigned char val)
{
    switch(time_channal)
    {
    case PWM_TIME1_CHANNAL0:
      T1CC0H = 0x00;           
      T1CC0L = val;            //�޸�T1CC0L�ɵ���ռ�ձ�   
      T1CCTL0 = 0x1c;          // ģʽѡ�� ͨ��0�Ƚ�ģʽ
      break;
    case PWM_TIME1_CHANNAL1:
      T1CC1H = 0x00;         
      T1CC1L = val;            //�޸�T1CC2L�ɵ���led������    
      T1CCTL1 = 0x1c;          // ģʽѡ�� ͨ��1�Ƚ�ģʽ
      break;
    case PWM_TIME1_CHANNAL2:
      T1CC2H = 0x00;          
      T1CC2L = val;            //�޸�T1CC2L�ɵ���led������
      T1CCTL2 = 0x1c;          // ģʽѡ�� ͨ��2�Ƚ�ģʽ
      break;
    case PWM_TIME1_CHANNAL3:
      T1CC3H = 0x00;         
      T1CC3L = val;            //�޸�T1CC2L�ɵ���led������
      T1CCTL3 = 0x1c;          // ģʽѡ�� ͨ��3�Ƚ�ģʽ
      break;
    case PWM_TIME1_CHANNAL4:
      T1CC3H = 0x00;          
      T1CC3L = val;            //�޸�T1CC2L�ɵ���led������
      T1CCTL3 = 0x1c;          // ģʽѡ�� ͨ��4�Ƚ�ģʽ
      break;      
    }
}
