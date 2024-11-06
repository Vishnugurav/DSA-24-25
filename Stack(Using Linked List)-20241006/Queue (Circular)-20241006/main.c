#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int printmenu() {
	int choice;
	printf("1. enqueue \n2. dequeue \n3. exit \n");
	scanf("%d",&choice);	
           return choice;
}
int main() {
	queue q;
	char name[16];
	int choice;
	qinit(&q);
	while(1) {
	printq(&q);
		choice = printmenu();
		switch(choice) {
		case 1: /* insert */
			printf("Enter name: \n");
			scanf("%s", name);
			if(!isqfull(&q))
 				enqueue(&q, name);
			else
                                                    printf("Sorry\n");
			break;
case 2: /* dequeue */
	if(!isqempty(&q))
	 printf("Patient name: %s \n",        dequeue(&q));
	else
	     printf("No more patients\n");
			break;
case 3: /* exit */
			exit(0);
		}
		}
}



