#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert(struct Node *head, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
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

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n, x, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    printf("Original List: ");
    display(head);

    printf("Enter value to delete: ");
    scanf("%d", &value);

    head = deleteNode(head, value);

    printf("After deletion: ");
    display(head);

    return 0;
}