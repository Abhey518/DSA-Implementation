#include <stdio.h>
#include <stdlib.h>

// *** Implementation of a Double-Ended Queue ***

#define TRUE 1
#define FALSE 0

// Defining a Dequeue.
#define MAX_DQUEUE 10

typedef int DqueueElement;

typedef struct dqueue {
    DqueueElement items [MAX_DQUEUE];
    int front;
    int rear;
    int count;
} Dqueue;

// Creating the Dequeue.
void CreateDqueue (Dqueue *q) {
    q -> count = 0;
    q -> front = 0;
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

// Append an element to the rear of the Dequeue.
void AppendRear (Dqueue *q, DqueueElement x) {
    if (IsDqueueFull(q)) {
        printf("Dequeue is Full\n");
        exit(1);

    } else {
        q -> items [++(q -> rear)] = x;
        q -> count++;
        printf("Appended element to the rear: %d\n", x);
    }
}
/*
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
        printf("Appended element to the front: %d\n", x);
    }

}
*/

// Serve an element from the front of the Dequeue.
void ServeFront (Dqueue *q, DqueueElement *x) {
    if (IsDqueueEmpty(q)) {
        printf("Dequeue is empty, underflow\n");
        exit(1);
    }
    *x = q -> items [(q -> front)++];
    q -> count--;
    printf("Served element from the front: %d\n", *x);
}

/*
// Serve an element from the rear of the Dequeue.
void ServeRear (Dqueue *q, DqueueElement *x) {
    if (IsDqueueEmpty(q)) {
        printf("Dequeue is empty, underflow\n");
        exit(1);
    }
    *x = q -> items [(q -> rear)--];
    q -> count--;
    printf("Served element from the rear: %d\n", *x);
}
*/

// Displaying the Dequeue.
void displayDqueue(const Dqueue *q) {

    if(IsDqueueEmpty(q)) {
        printf("Dequeue is empty, underflow\n");
        return;
    }
    printf("\nDequeue Elements: ");

    for ( int i = q -> front; i <= q -> rear; i++) {
        printf("%d ", q -> items[i]);
    }
    printf("\n");
}


// *** Implementation of a Circular Queue ***

// Defining a Circular Queue.
#define MAX_CQUEUE 10

typedef int CqueueElement;

typedef struct cqueue {
    CqueueElement items [MAX_CQUEUE];
    int front;
    int rear;
    int count;
} Cqueue;

// Creating the Circular Queue.
void CreateCqueue (Cqueue *q) {
    q -> count = 0;
    q -> front = 0;
    q -> rear = -1;
}

// Checks if the Circular Queue is empty.
int IsCqueueEmpty (const Cqueue *q) {

    return (q -> count == 0);
}

// Checks if the Circular Queue is full.
int IsCqueueFull (const Cqueue *q) {

    return (q -> count == MAX_CQUEUE);
}


// Append an element to the Circular Queue.
void Append (Cqueue *q, CqueueElement x) {
    if (IsCqueueFull(q)) {
        printf("Circular Queue is Full\n");
        exit(1);

    } else {
        q -> rear = (q -> rear + 1) % MAX_CQUEUE;
        q -> items [(q -> rear)] = x;
        q -> count++;
        printf("Appended element: %d\n", x);
    }
}

// Serve an element from the Circular Queue.
void Serve (Cqueue *q, CqueueElement *x) {
    if (IsCqueueEmpty(q)) {
        printf("Circular Queue is empty, underflow\n");
        exit(1);

    } else {
        *x = q -> items[(q -> front)];
        q -> front = (q -> front+1) % MAX_CQUEUE;
        q -> count--;
        printf("Served element: %d\n", *x);
    }
}

/*
// Size of the Circular Queue.
void CqueueSize (const Cqueue *q) {
    printf("Element count: %d\n", q -> count);
    return;
}
*/

// Displaying the Circular Queue.
void displayCqueue(const Cqueue *q) {

    if(IsCqueueEmpty(q)) {
        printf("Circular Queue is empty, underflow\n");
        return;
    }
    printf("\nCircular Queue Elements: ");

    for ( int i = q -> front; i <= q -> rear; i++) {
        printf("%d ", q -> items[i]);
    }
    printf("\n");
}

// Main program for the Dequeue operations.
int mainDQ () {

    Dqueue DQ;
    DqueueElement dItem;

    CreateDqueue(&DQ);

    AppendRear(&DQ, 75);

    AppendRear(&DQ, 110);

    AppendRear(&DQ, 125);

    ServeFront(&DQ, &dItem);

    AppendRear(&DQ, 50);

    displayDqueue(&DQ);
}


// Main program for the Circular Queue operations.
int mainCQ () {

    Cqueue CQ;
    CqueueElement cItem;

    CreateCqueue(&CQ);

    Append(&CQ, 85);

    Append(&CQ, 120);

    Append(&CQ, 135);

    Serve(&CQ, &cItem);

    Append(&CQ, 60);

    displayCqueue(&CQ);
}

int main() {
    printf("***** Dequeue Operations *****\n\n");
    mainDQ();  // Run DQ main program

    printf("\n***** Circular Queue Operations *****\n\n");
    mainCQ();  // Run CQ main program

    return 0;
}



