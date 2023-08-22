#include "StdTypes.h"
#include "Stack.h"

#include "LCD_Interface.h"

void Stack_Init(stack_t * stack,u8 s)
{
	//stack->size=s;
	stack->sp=-1;
}
stackStatus_t push(stack_t* stack,u8* data)
{
	if((stack->sp)<(STACK_MAXSIZE))
	{
		stack->sp++;
		stack->dataArr[stack->sp]=data;
		return STACK_DONE;
	}
	else
	{
		return STACK_FULL;
	}
}

stackStatus_t pop(stack_t* stack,u8**pdata)
{
	stackStatus_t status=STACK_DONE;
	if(stack->sp>=0)
	{
		*pdata=stack->dataArr[stack->sp];
		stack->sp--;
	}
	else
	{
		status= STACK_EMPTY;
	}
	return status;
}

