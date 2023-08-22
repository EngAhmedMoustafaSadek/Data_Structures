
#include "StdTypes.h"
#include "Queue.h"



void Queue_Init(Queue_t * queue,u8 s)
{
	queue->size=s;
	queue->front=0;
	queue->back=0;
	queue->count=0;
}

QueueStatus_t isFull(Queue_t queue)
{
	QueueStatus_t status = Queue_Space;
	if (queue.count == queue.size)
	{
		status = Queue_Full;
	}
	return status;
}
QueueStatus_t isEmpty(Queue_t queue)
{
	QueueStatus_t status = Queue_Space;
	if (queue.count == 0)
	{
		status = Queue_Empty;
	}
	return status;
}
QueueStatus_t enqueue(Queue_t *queue,u8* data)
{
	QueueStatus_t status = Queue_Full;
	if (isFull(*queue) != Queue_Full)
	{
		if (queue->back == queue->size)
		{
			queue->back = 0;
		}
		queue->dataArr[queue->back] = data;
		queue->back++;
		queue->count++;
		status = Queue_Done;
	}
	return status;
}

QueueStatus_t dequeue(Queue_t *queue,u8** data)
{
	QueueStatus_t status = Queue_Empty;

	if (isEmpty(*queue) != Queue_Empty)
	{
		if (queue->front == queue->size)
		{
			queue->front = 0;
		}
		*data = queue->dataArr[queue->front];
		queue->front++;
		queue->count--;
		status = Queue_Done;
	}
	return status;
}