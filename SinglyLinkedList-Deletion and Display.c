#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

struct Node* deleteNode(struct Node *head, int value) {
    if (head == NULL)
        return NULL;

    if (head->data == value) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *temp = head;

    while (temp->next != NULL &&
           temp->next->data != value)
        temp = temp->next;

    if (temp->next != NULL) {
        struct Node *del = temp->next;
        temp->next = del->next;
        free(del);
    }

    return head;
}

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, x, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("Original: ");
    display(head);

    printf("\nEnter value to delete: ");
    scanf("%d", &value);

    head = deleteNode(head, value);

    printf("After deletion: ");
    display(head);

    return 0;
}