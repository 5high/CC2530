/******************************************************************************
*项目名称 ： 按键流水灯
* 作者    ： 郑朋桥
* 时间    ： 2016/07/31
******************************************************************************/

/******************************************************************************
*导入头文件
******************************************************************************/
#include <ioCC2530.h>
#include "KEY.h"
#include "LED.h"
int status = 0;  //记录闪烁状态

/*****************************************************************************
*函数声明
*****************************************************************************/
void delayMS(int ms);

/*****************************************************************************
*函数含义：不精确延迟函数
*函数参数：延迟毫秒数
*  返回值：无返回值
*****************************************************************************/
void delayMS(int ms)
{
  int i,j;
  for(i = 0; i < ms; i++)
  {
    for(j = 0; j < 535; j++);
  }
}


/*****************************************************************************
*LED闪烁函数
*****************************************************************************/
void ledMagic()
{
  led1On();
  led2Off();
  delayMS(200);
  led1Off();
  led2On();
  delayMS(200);
}


/*****************************************************************************
*将小灯熄灭
*****************************************************************************/
void ledOff()
{
  led1Off();
  led2Off();
}

void main()
{
  ledInit();
  keyInit();
  
  while(1)
  {
    if(key1Scan() == 1)
    {
      status = ~status;
    }
    
    if(status != 0)    //如果状态不为零，就闪烁，否则，都熄灭
    {
      ledMagic();
    }
    else
    {
      ledOff();
    }
  }
}