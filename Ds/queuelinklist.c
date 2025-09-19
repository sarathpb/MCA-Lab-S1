#include<stdio.h>
#include<conio.h>

struct node {
int data;
struct node *ptr;
};

struct node* front = NULL;
struct node* rear = NUILL;

void enqueue();
void dequeue();
void display();
void exit();

int main()
{
int choice, value;
    while(1){
    printf("\n--queue menu--\n");
    printf("\n1. enqueue\n2. dequeue\n3. display\n4. exit");
    printf("enter your choice");
    printf("%d",choice)}
    switch(choice)
        {
            case 1:
                    printf("enter the value to be enqueue");
                    scanf("%d",value);
                    enqueue(value);
                    break;
            case 2:
                    dequeue(value);
                    break;
            case 3: 
                    display(value);
                    break;
            case 4:
                    exit(value);
                    break;
            default 
                    printf("invalid choice try again")
        }
}
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { 
        front = rear = newNode;
    } else {
        rear->next = newNode; 
        rear = newNode;       
    }
    printf("Enqueued %d\n", value);
}
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow - Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued %d\n", temp->data);
    front = front->next;
    if (front == NULL) { 
    }
    free(temp);
}


void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}


void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}