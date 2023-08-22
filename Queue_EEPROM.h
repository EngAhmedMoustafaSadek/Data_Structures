

#ifndef QUEUE_EEPROM_H_
#define QUEUE_EEPROM_H_

#define EPPROM_REQUEST_MAXNUM  10

typedef enum
{
	Queue_Full,
	Queue_Empty,
	Queue_Space,
	Queue_Done
} EEPROMQueueStatus_t;

typedef struct
{
	u16 address;
	u8  data_size;
	u8* data;
}EEPROM_Request_t;

typedef struct {
	u8 size;
	u8 front;
	u8 back;
	EEPROM_Request_t request_arr[EPPROM_REQUEST_MAXNUM];
	u8 count;
}Queue_EEPROM_t;

void EQ_Queue_Init(Queue_EEPROM_t * queue,u8 s);
EEPROMQueueStatus_t EQ_enqueue(Queue_EEPROM_t *queue,EEPROM_Request_t request);
EEPROMQueueStatus_t EQ_dequeue(Queue_EEPROM_t *queue,EEPROM_Request_t *request);
EEPROMQueueStatus_t EQ_isFull(Queue_EEPROM_t queue);
EEPROMQueueStatus_t EQ_isEmpty(Queue_EEPROM_t queue);




#endif /* QUEUE_EEPROM_H_ */