#include "ADC.h"

float getChannalValue(ENUM_ADC_CHANNAL channal,ENUM_ADC_RESOLUTION resolution,\
  ENUM_ADC_VOLTAGE voltage)
{
  short value = 0;
  char valueH = 0;
  char valueL = 0;
  //Ӧ���������òο���ѹ���ο���ѹ�ȶ���Ҫһ��ʱ�䡣
  ADCCON3 &= ~(3 << 6);    //���ο���ѹΪ���Ϊ0
  switch(voltage)
  {
  case INTERNAL_REFERENCE:
    //ADCCON3 |= (0 << 6);   //�ڲ��ο���ѹ
    break;
  case AIN7_EXTERNAL_VOLTAGE:
    ADCCON3 |= (1 << 6);   //AIN7���Ųο��ĵ�ѹ
    break;
  case AVDD5_PIN_VOLTAGE:
    ADCCON3 |= (2 << 6);   //AVDD5��Ϊ��ѹ
    break;
  case AIN6_AIN7_VOLTAGE:
    ADCCON3 |= (3 << 6);   //AIN6_AIN7���������ⲿ�ο���ѹ
    break;
  }

  
  ADCCON3 &= ~(15 << 0);
  switch(channal)
  {
    case  AIN0:
      APCFG   |=  (1 << 0); //����P0_0Ϊģ������
      ADCCON3 |= (0 << 0);  //ͨ��ѡ��
      break;
    case  AIN1:
      APCFG   |=  (1 << 1);
      ADCCON3 |= (1 << 0);  //ͨ��ѡ��
      break;
    case  AIN2:
      APCFG   |=  (1 << 2);
      ADCCON3 |= (2 << 0);  //ͨ��ѡ��
      break;
    case  AIN3:
      APCFG   |=  (1 << 3);
      ADCCON3 |= (3 << 0);  //ͨ��ѡ��
      break;
    case  AIN4:
      APCFG   |=  (1 << 4);
      ADCCON3 |= (4 << 0);  //ͨ��ѡ��
      break;
    case  AIN5:
      APCFG   |=  (1 << 5);
      ADCCON3 |= (5 << 0);  //ͨ��ѡ��
      break;
    case  AIN6:
      APCFG   |=  (1 << 6);
      ADCCON3 |= (6 << 0);  //ͨ��ѡ��
      break;
    case  AIN7:
      APCFG   |=  (1 << 7);
      ADCCON3 |= (7 << 0);  //ͨ��ѡ��
      break;
    case  AIN0_AIN1:
      APCFG   |=  (1 << 0);
      APCFG   |=  (1 << 1);
      ADCCON3 |= (8 << 0);  //ͨ��ѡ��
      break;
    case  AIN2_AIN3:
      APCFG   |=  (1 << 2);
      APCFG   |=  (1 << 3);
      ADCCON3 |= (9 << 0);  //ͨ��ѡ��
      break;
    case  AIN4_AIN5:
      APCFG   |=  (1 << 4);
      APCFG   |=  (1 << 5);
      ADCCON3 |= (10 << 0);  //ͨ��ѡ��
      break;
    case  AIN6_AIN7:
      APCFG   |=  (1 << 6);
      APCFG   |=  (1 << 7);
      ADCCON3 |= (11 << 0);  //ͨ��ѡ��
      break;
    case  GND:
      ADCCON3 |= (12 << 0);  //�زο�
      break;
    case  VCC:
      ADCCON3 |= (13 << 0);  //����ѹ�ο�
      break;
    case  TEMP:
      TR0 = (1 << 0);                 //����Ϊ1�������¶ȵ�SOC_ADC
      ATEST = (1 << 0);               //ʹ���¶ȴ���
      ADCCON3 |= (14 << 0);  //�¶ȴ�����
      break;
    case  VDD_3:
      ADCCON3 |= (15 << 0);  //
      break;
  }
  
  ADCCON3 &= ~(3 << 4);
  switch(resolution)
  {
    case BIT7:
      ADCCON3 |= (0 << 4);   //64��ȡ�ʣ�7λ�ķֱ���
      break;
    case BIT9:
      ADCCON3 |= (1 << 4);   //128��ȡ�ʣ�9λ�ķֱ���
      break;
    case BIT10:
      ADCCON3 |= (2 << 4);   //256��ȡ�ʣ�10λ�ķֱ���
      break;  
    case BIT12:
      ADCCON3 |= (3 << 4);   //512��ȡ�ʣ�12λ�ķֱ���
      break;  
   }
  
  

  
  ADCCON1 |= (3 << 4);   //ѡ��ADC������ģʽΪ�ֶ�
  ADCCON1 |= (1 << 1);   //����ת��
  
  while( !(ADCCON1 & (1 << 7)) );  //�鿴ת���Ƿ����
  //ADCL�Ĵ�������λ��Ч��������ֻ��12λ��Ч��ADCL�Ĵ�����4λ��Ч�����Ϻܶ����
  //���ﶼ���ƶ���λ�����ǲ��Ե�
  value = 0;
  valueL = ADCL;
  valueH = ADCH;
  value |= valueL;  
  value |= valueH << 8;

  switch(resolution)
  {
    case BIT7:
      value = value >> 8;
      break;
    case BIT9:
      value = value >> 6;
      break;
    case BIT10:
      value = value >> 5;
      break;  
    case BIT12:
      value = value >> 3;
      break;  
   }

  //����ADֵ�������ʵ�ʵ��¶ȣ��¶�ϵ��Ӧ����4.5 /'c�����¶�У���������ȥ5'C
  //(��ͬоƬ���ݾ������У��)
  return value;  
}
