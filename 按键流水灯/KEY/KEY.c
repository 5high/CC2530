#include "KEY.h"
#if ( (S1 > 0) || (S2 > 0) )
  //��ʼ��Key
  void keyInit()
  {
    #if (S1 > 0)
      P0SEL &= ~(1 << 1);   //ͨ��IO����
      P0DIR &= ~(1 << 1);   //���뷽��
      //����Ϊ����
      P0INP &= ~(1 << 1);
      P2INP &= ~(1 << 5);
    #endif
    #if (S2 > 0)
      
      P2SEL &= ~(1 << 0);   //ͨ��IO����
      P2DIR &= ~(1 << 0);   //���뷽��
      //����Ϊ����
      P2INP &= ~(1 << 0);
      P2INP &= ~(1 << 7);
    #endif
  }
#endif
#if (S1 > 0)
  
    int key1Scan()
    {
      int i;
      if(KEY1 == 0) //�ߵ�ƽ��Ч
      {
          //��⵽����
          for(i = 0;i<10000;i++)
          {
          }
          
          if(KEY1 == 0)
          {
            while(!KEY1); //ֱ���ɿ�����
            return(1);
          }
      }
      return 0;
    }
#endif

#if (S2 > 0)
    int key2Scan()
    {
      int i;
      if(KEY2 == 0) //�ߵ�ƽ��Ч
      {
          //��⵽����
        for(i = 0;i<10000;i++)
        {
        }
          if(KEY2 == 0)
          {
            while(KEY2); //ֱ���ɿ�����
            return(1);
          }
      }
      return 0;
    }
#endif 