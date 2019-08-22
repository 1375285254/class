#include "finger.h"
#include "key.h"
#include "delay.h"
#include "deal_fg.h"

//添加指纹
int Add_FG(uint8_t num)
{
  int id = 0;	
	while(1)
	{
		while(KEY_Scand()==0);		//等待指纹放上
		delay_ms(500);
		if(KEY_Scand()==1)
		{
			id = num;
			 return Add_New_FG(0x00,id);
		}
	}
}

void cleck_FG(void)
{
		if(KEY_Scand()==1)
		{
			delay_ms(500);
			Allow_going();
			while(KEY_Scand()==1);		//等待手指离开
		}
}
