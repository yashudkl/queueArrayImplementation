// Queue using array
#include <stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int r;
    int f;
    int * arr;
};

int isFull(struct Queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
};
int isEmpty(struct Queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
};

void enqueue(struct Queue *q,int val){
    if(isFull(q)){
        printf("This queue is full");
    }
    else{
      q->r++;
      q->arr[q->r] = val;
    }
}

int dequeue(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->f++;
        a = q->arr[q->f] ;
    }
    return a; //So basically memory is actually not freed but we are just moving the front ahead so that the previous memory is not accessible if I do -- it will simply disturb FIFO order 
}


int main() {
    struct Queue q;
    q.size = 2;
    q.r = q.f = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));
    
 
    
    enqueue(&q,20);
      enqueue(&q,50);
      
        
     
       printf("Dequeuing element %d \n",dequeue(&q));
        printf("Dequeuing element %d \n",dequeue(&q));
           
           if(isEmpty(&q)){
           printf("Queue is empty");
           
        
    }
 
    return 0;
}