#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Defining a Dequeue.
#define MAX_DQUEUE 10

typedef char DqueueElement;

typedef struct dqueue {
    DqueueElement items [MAX_DQUEUE];
    int front;
    int rear;
    int count;
} Dqueue;

// Creating the Dequeue.
void CreateDqueue (Dqueue *q) {
    q -> count = 0;
    q -> front = -1;
    q -> rear = -1;
}

// Checks if the dequeue is empty.
int IsDqueueEmpty (const Dqueue *q) {
    if (q -> rear < q -> front)
        return (TRUE);
    else
        return(FALSE);
}

// Checks if the dequeue is full.
int IsDqueueFull (const Dqueue *q) {
    if (q -> rear == MAX_DQUEUE - 1)
        return (TRUE);
    else
        return(FALSE);
}


// Append an element to the front of the Dequeue.
void AppendFront (Dqueue *q, DqueueElement x) {
    if (IsDqueueFull(q)) {
        printf("Dequeue is Full\n");
        exit(1);

    } else {
        if (IsDqueueEmpty(q)) {
            q -> items [q -> front] = x;
            q -> rear++;

        } else {
            if(q -> front == 0) {
                //need to move elements to the back by one position.
                for (int i = q -> rear; i >= q -> front; i--) {
                    q -> items[i+1] = q -> items[i];
                }

                q -> rear++;
                q-> items[q -> front] = x;

            } else
                q -> items[--(q -> front)] = x;
        }
        q -> count++;
        printf("Appended element to the front: %c\n", x);
    }

}


// Displaying the Dequeue.
void displayDqueue(const Dqueue *q) {

    if(IsDqueueEmpty(q)) {
        printf("Dequeue is empty, underflow\n");
        return;
    }
    printf("\nDequeue Elements: ");

    for ( int i = q -> front; i <= q -> rear; i++) {
        printf("%c ", q -> items[i]);
    }
    printf("\n");
}

// Main program for the Dequeue operations.
int main () {

    Dqueue DQ;

    CreateDqueue(&DQ);

    AppendFront(&DQ, 'M');

    AppendFront(&DQ, 'B');

    AppendFront(&DQ, 'L');

    AppendFront(&DQ, 'P');

    AppendFront(&DQ, 'C');

    AppendFront(&DQ, 'J');

    displayDqueue(&DQ);
}
