  #define TIME1 1
  #define TIME3 0
  #define TIME4 0


ѡ��������һ���ж϶�ʱ��


����timex�жϺ���
 extern void setINTTimexFun(int (*inTx_function)());
����TxCC��ֵ���ڷ�����ģʽʱʹ��
extern void setTxCCxValue(unsigned short val, ENUM_TIME1_CHANNAL channal);
���ݲ�����ʼ����ʱ��
extern void initTimex(ENUM_TIME1_CLKDIV time_clkdiv,ENUM_TIME1_MODE time_mode, \
  ENUM_TIME1_CHANNAL channal);