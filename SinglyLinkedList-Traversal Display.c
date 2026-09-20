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

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, x;

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

    printf("Traversal: ");
    display(head);

    return 0;
}