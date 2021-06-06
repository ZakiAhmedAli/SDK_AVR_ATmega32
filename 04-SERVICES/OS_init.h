#ifndef OS_INIT_H
#define OS_INIT_H


#define NULL (void)0

typedef struct
{
	u16 periodicity		;
	void(*Fptr)(void)	;
	
	
}TASK;


void OS_voidCreateTask(u8 Copy_u8Peroid , u16 Copy_u16Periodicity , void (*Ptr)(void) );
void OS_voidStart(void);





#endif // OS_INIT_H