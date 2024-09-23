#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int *num, int s)
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = *num;
    struct Node *current = head;

    for (int i = 1; i < s; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = *(num + i);
        current->next = newNode;
        current = newNode;
    }

    current->next = head;
    return head;
}

struct Node *find_3(struct Node *head)
{
    struct Node *current = head;
    while (current->data != 3)
    {
        current = current->next;
    }
    return current;
}

struct Node *delete_Data(struct Node *current, int m, int *deletedData)
{
    struct Node *previous = NULL;

    for (int i = 1; i < m; i++)
    {
        previous = current;
        current = current->next;
    }

    if (previous == NULL)
    {
        previous = current;
        while (previous->next != current)
        {
            previous = previous->next;
        }
    }

    *deletedData = current->data;
    previous->next = current->next;
    struct Node *nextNode = current->next;
    free(current);
    return nextNode;
}

void Josephus(struct Node *head)
{
    FILE *file = fopen("Josephus.out", "w");
    struct Node *current = find_3(head);
    int r = 1;
    while (current->next != current)
    {
        int deletedData;
        current = delete_Data(current, r, &deletedData);
        fprintf(file, "%d", deletedData);
        r++;
    }

    fprintf(file, "%d\n", current->data);
    fclose(file);
    free(current);
}

int main()
{
    int num[] = {1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 3, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 2};
    int size = sizeof(num) / sizeof(*num);
    struct Node *head = create(num, size);
    Josephus(head);
    return 0;
}
