#include <stdio.h>
#include <stdlib.h>

#include "ring.h"
buffer *q;
error_msg p;
int main()
{
	u_int8_t x=25;
	u_int8_t *data=&x;
	q=malloc(sizeof(buffer));
	q->buff_point=malloc(sizeof(uint8_t)*100);	
	p=init(q,100);	
	p=buf_add(q,'a');
	printf("Head=%p\n",q->head);
	printf("Data=%c\n",*(q->head-1));
	printf("Tail=%p\n",q->tail);
	p=buf_add(q,25);
	printf("Head=%p\n",q->head);
        printf("Tail=%p\n",q->tail);
	p=buf_delete(q,&x);
	printf("Head=%p\n",q->head);
        printf("Tail=%p\n",q->tail);
	printf("Data=%d\n",*(q->tail-1));
	
	return 0;
}

