#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

void qinit(queue *q){
	q->front= q->rear = q->count = 0;
	return;
}



void enqueue(queue *q, char *name){
	q->arr[q->rear] = malloc(strlen(name) + 1);
	strcpy(q->arr[q->rear], name);
	q->rear = ((q->rear) + 1) % N;
	(q->count)++;


}
char *dequeue(queue *q){
	char *tmp = q->arr[q->front];
	q->front = ((q->front) + 1) % N;
	(q->count)--;
	return tmp;

}
int isqempty(queue *q){
	return q->count == 0;
}

int isqfull(queue *q){
	return q->count == N;

}


void printq(queue *q){
	int x;
	printf("[ ");
	for(x = q->front ; x != q->rear;  x = (x + 1)  % N){
			printf("%s ", q->arr[x]);
		}
	printf("] \n");

}

