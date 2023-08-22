
#include "StdTypes.h"
#include "Queue_EEPROM.h"


void EQ_Queue_Init(Queue_EEPROM_t * queue,u8 s)
{
	queue->size=s;
	queue->front=0;
	queue->back=0;
	queue->count=0;
}

EEPROMQueueStatus_t EQ_isFull(Queue_EEPROM_t queue)
{
	EEPROMQueueStatus_t status = Queue_Space;
	if (queue.count == queue.size)
	{
		status = Queue_Full;
	}
	return status;
}
EEPROMQueueStatus_t EQ_isEmpty(Queue_EEPROM_t queue)
{
	EEPROMQueueStatus_t status = Queue_Space;
	if (queue.count == 0)
	{
		status = Queue_Empty;
	}
	return status;
}
EEPROMQueueStatus_t EQ_enqueue(Queue_EEPROM_t *queue,EEPROM_Request_t request)
{
	EEPROMQueueStatus_t status = Queue_Full;
	if (EQ_isFull(*queue) != Queue_Full)
	{
		if (queue->back == queue->size)
		{
			queue->back = 0;
		}
		queue->request_arr[queue->back] = request;
		queue->back++;
		queue->count++;
		status = Queue_Done;
	}
	return status;
}

EEPROMQueueStatus_t EQ_dequeue(Queue_EEPROM_t *queue,EEPROM_Request_t *request)
{
	EEPROMQueueStatus_t status = Queue_Empty;

	if (EQ_isEmpty(*queue) != Queue_Empty)
	{
		if (queue->front == queue->size)
		{
			queue->front = 0;
		}
		*request = queue->request_arr[queue->front];
		queue->front++;
		queue->count--;
		status = Queue_Done;
	}
	return status;
}