#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void beginsert();
void begindelete();
void randominsert();
void randomdelete();
void lastinsert();
void lastdelete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 9) {
        printf("\n1.Insert at beginning\n2.Delete at beginning\n3.Insert at position\n4.Delete at position\n5.Insert at end\n6.Delete at end\n7.Display\n8.Search\n9.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                beginsert();
                break;
            case 2:
                begindelete();
                break;
            case 3:
                randominsert();
                break;
            case 4:
                randomdelete();
                break;
            case 5:
                lastinsert();
                break;
            case 6:
                lastdelete();
                break;
            case 7:
                display();
                break;
            case 8:
                search();
                break;
            case 9:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}

void beginsert() {
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head = ptr;
    printf("Node inserted at beginning\n");
}

void begindelete() {
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    printf("Node deleted from beginning\n");
}

void randominsert() {
    int loc, item, i;
    struct node *ptr, *temp;

    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &item);
    printf("Enter the position to insert (starting from 0): ");
    scanf("%d", &loc);

    ptr->data = item;
    ptr->next = NULL;

    if (loc == 0) {
        ptr->next = head;
        head = ptr;
        printf("Node inserted at position 0\n");
        return;
    }

    temp = head;
    for (i = 0; i < loc - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range\n");
            free(ptr);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(ptr);
    } else {
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Node inserted at position %d\n", loc);
    }
}

void randomdelete() {
    int loc, i;
    struct node *ptr, *prev;

    printf("Enter the position to delete (starting from 0): ");
    scanf("%d", &loc);

    if (head == NULL) {
        printf("UNDERFLOW - List is empty\n");
        return;
    }

    if (loc == 0) {
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Node deleted from position 0\n");
        return;
    }

    ptr = head;
    for (i = 0; i < loc; i++) {
        prev = ptr;
        ptr = ptr->next;
        if (ptr == NULL) {
            printf("Position out of range\n");
            return;
        }
    }

    prev->next = ptr->next;
    free(ptr);
    printf("Node deleted from position %d\n", loc);
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;

    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
        printf("Node inserted at end (first node)\n");
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
        printf("Node inserted at end\n");
    }
}

void lastdelete() {
    struct node *ptr, *prev;

    if (head == NULL) {
        printf("UNDERFLOW - List is empty\n");
        return;
    }

    if (head->next == NULL) {
        ptr = head;
        head = NULL;
        free(ptr);
        printf("Only node deleted from the list\n");
        return;
    }

    ptr = head;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    printf("Node deleted from the end\n");
}

void display() {
    struct node *ptr = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void search() {
    struct node *ptr = head;
    int item, pos = 0, found = 0;

    if (head == NULL) {
        printf("List is empty\n");                                                          
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &item);

    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("Item found at position %d\n", pos);
            found = 1;
            break;
        }
        ptr = ptr->next;
        pos++;
    }

    if (!found)
        printf("Item not found in the list\n");
}
