#include "INTKEY.h"


 #if ( (IS1 > 0) || (IS2 > 0) )
    void intKeyInit()
    {
      #if (IS1 > 0)
        P0IEN |= (1 << 1);   //����ʹ��
        PICTL |= (1 << 0);   //�˿�0�½��ش���
        P0IFG &= (1 << 1);   //��ʼ���ж�ֵ
        IEN1  |= (1 << 5);   //�˿�0ʹ��
        EA = 1;
      #endif
        
      #if (IS2 > 0)
        P2IEN |= (1 << 0);    //����ʹ��
        PICTL |= (1 << 3);    //�˿�0�½��ش���
        P2IFG &= (1 << 0);   //��ʼ���ж�ֵ
        IEN2  |= (1 << 1);    //�˿�0ʹ��
        EA = 1;
      #endif
    }

  #endif


#if (IS1 > 0)
    void (*IS1_fun)(void);
    void setIntKey1Fun(void (*fun)(void))
    {
      IS1_fun = fun;
    }

    #pragma vector = P0INT_VECTOR
    __interrupt void P0_ISR(void)
    {
      IS1_fun();
      P0IFG &= ~(1 << 1);   //��ʼ���ж�ֵ      
      P0IF = 0x00;              //��������˿�0���ж�Ӧ�ö��õ�������,�˿�0
                                //���ж�δ��
    }
#endif
    
#if (IS2 > 0)
    void (*IS2_fun)(void);
    void setIntKey2Fun(void (*fun)(void))
    {
      IS2_fun = fun;
    }

    #pragma vector = P2INT_VECTOR
    __interrupt void P2_ISR(void)
    {
      IS2_fun();
      P2IFG &= ~(1 << 0);
    
      P2IF = 0x00;          //��������˿�2���ж�Ӧ�ö��õ�������,�˿�2���ж�δ��
      
      
    }
#endif


