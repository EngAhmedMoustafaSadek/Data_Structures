
#ifndef QUEUE_H_
#define QUEUE_H_

#define Queue_Size 5

typedef enum
{
	Queue_Full,
	Queue_Empty,
	Queue_Space,
	Queue_Done
} QueueStatus_t;

typedef struct {
	u8 size;
	u8 front;
	u8 back;
	u8 **dataArr;
	u8 count;
	}Queue_t;

void Queue_Init(Queue_t * queue,u8 s);
QueueStatus_t enqueue(Queue_t *queue,u8* data);
QueueStatus_t dequeue(Queue_t *queue,u8** data);
QueueStatus_t isFull(Queue_t queue);
QueueStatus_t isEmpty(Queue_t queue);



#endif /* QUEUE_H_ */