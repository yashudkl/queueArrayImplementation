#include <stdio.h>
#include <stdlib.h>

struct circularQueue{
    int size;
    int front;
    int rear ;
    int *arr;
};

int isEmpty(struct circularQueue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
};


//If circular increment of rear is equals to front then queue is Full
int isFull(struct circularQueue *q){
    if((q->rear+1)%q->size == q->front){
        return 1;
    }
    return 0;
};

void enqueue(struct circularQueue *q , int value){
    if(isFull(q) == 1){
        printf("Queue is full \n");
        
    }

    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = value;
    }
}


int dequeue(struct circularQueue * q){
    int val = 0;
    if(isEmpty(q)){
        printf("circularQueue is Empty");
        return -1;
    }
    else{
        q->front = (q->front) % q->size;
        val = q->arr[q->front];
        return val;
    }
}
void display(struct circularQueue *q){
    printf("%d ", q->arr[q->rear]);
}
int main(int argc, char const *argv[])
{
   
    struct circularQueue* q = (struct circularQueue*)malloc(sizeof(struct circularQueue));
     q->size = 4;
    q->arr = (int *)malloc(q->size * sizeof(int));
   
   q->rear = 0;
   q->front = -1;
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
  
printf("Dequeued %d",dequeue(q));

}
