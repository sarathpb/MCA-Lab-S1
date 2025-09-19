#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push function
void push(int value) {
    if (top == SIZE - 1) {
        printf("Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d into stack.\n", value);
    }
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Underflow! Stack is empty.\n");
    } else {
        int poppedValue = stack[top];
        top--;
        printf("Popped %d from stack.\n", poppedValue);
    }
}
//display function
void display() {
    if(top == -1) {
        printf("stack is empty.\n");
    }
    else{
        printf("stack elements(top to bottom)\n");
        for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
        }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n-- Stack Menu --\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. display\n");
        printf("4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
