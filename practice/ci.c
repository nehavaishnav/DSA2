#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
    int id;              
    int burstTime;       
    int remainingTime;   
};


struct CircularQueue {
    struct Process queue[MAX_PROCESSES]; 
    int front;               
    int rear;                
    int maxSize;             
};

void initializeQueue(struct CircularQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->maxSize = MAX_PROCESSES;
}

int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % q->maxSize == q->front;
}

int isEmpty(struct CircularQueue* q) {
    return q->front == (q->rear + 1) % q->maxSize;
}


void enqueue(struct CircularQueue* q, struct Process p) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add more processes.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->maxSize; 
    q->queue[q->rear] = p;
}

struct Process dequeue(struct CircularQueue* q) {
    struct Process emptyProcess = { -1, 0, 0 };
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return emptyProcess;
    }
    struct Process temp = q->queue[q->front];
    q->front = (q->front + 1) % q->maxSize; 
    return temp;
}

void roundRobin(struct Process processes[], int n, int timeQuantum) {
    struct CircularQueue queue;
    initializeQueue(&queue);
    int currentTime = 0;

    
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime; 
        enqueue(&queue, processes[i]);
    }

    while (!isEmpty(&queue)) {
        struct Process currentProcess = dequeue(&queue); 

        int executionTime = (currentProcess.remainingTime < timeQuantum) ? 
                            currentProcess.remainingTime : timeQuantum;
        currentProcess.remainingTime -= executionTime;
        currentTime += executionTime;

        
        printf("Process %d executed for %d units.\n", currentProcess.id, executionTime);

        // If the process is completed
        if (currentProcess.remainingTime > 0) {
            // If not completed, add it back to the queue
            enqueue(&queue, currentProcess);
        } else {
            printf("Process %d completed at time %d.\n", currentProcess.id, currentTime);
        }
    }
}

int main() {
    struct Process processes[MAX_PROCESSES]; 
    int n, timeQuantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Exceeds maximum allowed processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", (i + 1));
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i + 1; 
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    roundRobin(processes, n, timeQuantum);

    return 0;
}
