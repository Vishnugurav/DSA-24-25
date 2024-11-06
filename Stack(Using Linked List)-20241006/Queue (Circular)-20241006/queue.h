#define N 16

typedef struct queue {
	char *arr[N];
	int count, front, rear;
}queue; 

void qinit(queue *q);
void enqueue(queue *q, char *name);
char *dequeue(queue *q);
int isqempty(queue *q);
int isqfull(queue *q);
void printq(queue *q);

