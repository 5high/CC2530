/****************************************************************************
* �� �� ��: main.c
* ��    ��: ���ɼ�������ʪ��ͨ�����ڷ��͵����ڵ�����������ʾ 115200 8N1
****************************************************************************/
#include <ioCC2530.h>
#include <string.h>
#include "INTUART.H" 
#include "DHT11.H" 

/****************************************************************************
* ������ں���
****************************************************************************/
void main(void)
{  
    char temp[3]; 
    char humidity[3];   
    char strTemp[13]="Temperature:";
    char strHumidity[10]="Humidity:";
    setSystemCLK();
    Delay_ms(1000);          //���豸�ȶ�
    initUart();              //���ڳ�ʼ��
    while(1)
    {         
        memset(temp, 0, 3);
        memset(humidity, 0, 3);
        DHT11();             //��ȡ��ʪ��

        //����ʪ�ȵ�ת�����ַ���
        temp[0]=wendu_shi+0x30;
        temp[1]=wendu_ge+0x30;
        humidity[0]=shidu_shi+0x30;
        humidity[1]=shidu_ge+0x30;
        
        //��õ���ʪ��ͨ�����������������ʾ
        sendString(strTemp, 12);
        sendString(temp, 2);
        sendString("   ", 3);
        sendString(strHumidity, 9);
        sendString(humidity, 2);
        sendString("\n", 1);
        
        Delay_ms(1000);  //��ʱ��2S��ȡ1�� 
    }
}
