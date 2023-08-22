

#ifndef STACK_H_
#define STACK_H_

#define STACK_MAXSIZE 5

typedef struct{
	s8 sp;
	u8 *dataArr[STACK_MAXSIZE];
}stack_t;

typedef stack_t*   STACK_T;


typedef enum{
	STACK_FULL,
	STACK_EMPTY,
	STACK_DONE
}stackStatus_t;


void Stack_Init(stack_t * stack,u8 s);
stackStatus_t push(stack_t* stack,u8* data);
stackStatus_t pop(stack_t* stack,u8**pdata);




#endif /* STACK_H_ */