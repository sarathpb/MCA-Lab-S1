#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert at beginning
void insertAtBeginning(int newdata) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = head;
    head = newnode;
}

// Print list
void printList() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, data;
    printf("How many numbers do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &data);
        insertAtBeginning(data);
    }

    printf("Linked List: ");
    printList();

    return 0;
}
