//circular linked list

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void create(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        newNode->next = *head;
    } else 
    {
        struct Node* temp = *head;
        while (temp->next != *head) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void traverse(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insert_beg(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insert_end(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void delete_beg(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) 
    {
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = temp->next;
        *head = temp->next;
        free(temp);
    }
}

void delete_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        struct Node* second_last = NULL;
        while (temp->next != *head) {
            second_last = temp;
            temp = temp->next;
        }
        second_last->next = *head;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Traverse\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create the list: ");
                scanf("%d", &data);
                create(&head, data);
                break;
            case 2:
                printf("Elements in the Circular Linked List: ");
                traverse(head);
                break;
            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_beg(&head, data);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 5:
                delete_beg(&head);
                printf("Deleted node from beginning.\n");
                break;
            case 6:
                delete_end(&head);
                printf("Deleted node from end.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
