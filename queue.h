#ifndef _queue_h
#define _queue_h

typedef struct queueNode {
	struct queueNode* next;
	struct queueNode* prev;
	void* object;
} queueNode;

typedef struct queue {
	queueNode* head;
	queueNode* tail;
} queue;

queueNode* createQueueNode(void* object);
queue* createQueue();
queue* enqueue(queue* self, void* object);
void* dequeue(queue* self);

#endif
