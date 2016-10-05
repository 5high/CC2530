#include "CHECKUART.h"


  
#if (UART0 > 0)
    void setSystemCLK()
    {
      CLKCONCMD &= ~(1 << 6); //����ϵͳʱ��ԴΪ32MHz
      while( CLKCONCMD & (1 << 6) );
      CLKCONCMD &= ~(7 << 0); //��ǰϵͳʱ��Ƶ��Ϊ32MHz
    
    }
  /*****************************************************************************
  *  ��������  ��  ��ʼ������
  *            ��
  *    ����    �� ��
  *   ����ֵ   �� ��
  ******************************************************************************/
  void initUart()
  {
    PERCFG &= ~(1 << 0); //����uart0��λ��1
    P0SEL  |= (1 << 2);  //��P0_2����Ϊ����
    P0SEL  |= (1 << 3);  //��P0_3����Ϊ����
    P2DIR  &= ~(3 << 6); //����uart0�����ȼ����
    U0CSR  |= (1 << 7);  //usart0��Ϊuart0
    //���ò�����Ϊ115200
    U0GCR  |= (11 << 0); //����BAUD_EΪ11
    U0BAUD = 216;        //����U0BAUD_MΪ216
    UTX0IF = 0;          //UART0 TX�жϱ�־Ϊ0
    U0CSR  |= (1 << 6); // ����Uarrt0�Ľ��չ���
  } 
  
  void sentChar(char ch)
  {
    U0DBUF = ch;
    while( UTX0IF == 0 );  //ֱ���з�������жϣ���ʾ�������
    UTX0IF = 0;
  }
  
  void sentString(char * str, int len)
  {
    int i = 0;
    while(i < len)
    {
      sentChar(*(str+i));
      i++;
    }
  }
  
  char readChar()
  {
    if( U0CSR & (1 << 2) )
    {
        return U0DBUF;
    }
    return -1;
  }
  
  int readString(char * str, int len)
  {
    int i = 0;
    char ch;
    while(i < len)
    {
      ch=readChar();
      if(ch != (char)-1)
      {
        *(str+i) = ch;
        i++;
      }
    }
    
    return i;
  }
#endif
