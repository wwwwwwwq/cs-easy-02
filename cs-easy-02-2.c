#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int d) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d;
    n->next = n;
    return n;
}

void insertNode(struct Node** h, int d) {
    struct Node* n = createNode(d);
    if (*h == NULL) {
        *h = n;
    } else {
        struct Node* t = *h;
        while (t->next != *h) {
            t = t->next;
        }
        t->next = n;
    }
    n->next = *h;
}

void josephus(struct Node** h, int m, FILE* output) {
    if (*h == NULL) return;

    struct Node* c = *h;
    struct Node* p = NULL;

    while (c->data != 3) {
        c = c->next;
    }

    while (c->next != c) {
        for (int i = 1; i < m; i++) {
            p = c;
            c = c->next;
        }
        fprintf(output, "%d", c->data);
        p->next = c->next;
        struct Node* t = c;
        c = c->next;
        free(t);
    }
    fprintf(output, "%d", c->data);
    free(c);
}

int main() {
    struct Node* h = NULL;

    int values[] = {1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2, 2, 2, 2, 1, 2, 1, 1, 3, 1, 1, 2, 1, 2, 2, 2, 2, 1, 1, 2, 2, 1, 1, 1};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        insertNode(&h, values[i]);
    }

    FILE* output = freopen("Josephus.out", "w", stdout);
    
    int m = 3;
    josephus(&h, m, output);

    fclose(stdout);
    return 0;
}
