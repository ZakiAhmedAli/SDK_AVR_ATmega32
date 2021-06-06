#include"STD_TYPES.h"
#include"BIT_MATH.h"



#include"MSTK_init.h"


volatile u16 TickCount=0;

/*Array of struct*/
static TASK OS_Tasks[NUM_OF_TASKS]={ NULL };

/*ID peroid id*/
void OS_voidCreateTask(u8 Copy_u8Peroid , u16 Copy_u16Periodicity , void (*Ptr)(void) )
{
	OS_Tasks[Copy_u8Peroid].periodicity = Copy_u16Periodicity;
	OS_Tasks[Copy_u8Peroid].Fptr = Ptr;

}

void OS_voidStart(void)
{
	/* init */
	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(1000 , OS_schedular);
}

 
/*MSTK_voidSetIntervalPeriodic function call OS_schedular every 1 msec
	OS_schedular ordering Tasks */
static void OS_schedular(void)
{
	for(u8 i=0 ; i<3 ; i++)
	{
		if( (TickCount % OS_Tasks[i].periodicity) ==0)
		{
			OS_Tasks[i].Fptr();
		}
	}	
	
	TickCount++;
	
}



