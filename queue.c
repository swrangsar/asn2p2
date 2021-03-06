#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queueNode* createQueueNode(void* object)
{
	queueNode* new = malloc(sizeof(queueNode));
	new->next = new->prev = NULL;
	new->object = object;
	return queueNode;
}

queue* createQueue()
{
	queue* new = malloc(sizeof(queue));
	new->head = new->tail = NULL;
	return queue;
}

queue* enqueue(queue* self, void* object)
{
	if (!self || !object) {
		perror("Nonexistent queue or a null object!\n");
		exit(1);
	}
	queueNode* new = createQueueNode(object);
	if (!self->head || !self->tail) {
		self->head = self->tail = new;
	} else {
		new->next = self->head;
		self->head->prev = new;
		self->head = new;
	}
	return self;
}

void* dequeue(queue* self)
{
	if (!self || !self->tail) {
		perror("Nonexistent or empty queue!\n");
		exit(1);
	}
	queueNode* QueueNode = self->tail;
	if (self->tail) {
		if (!self->tail->prev) {
			self->head = self->tail = NULL;
		} else {
			self->tail = self->tail->prev;
		}
	}
	void* object;
	object = QueueNode->object;
	free(QueueNode);
	
	return QueueNode->object;
}
