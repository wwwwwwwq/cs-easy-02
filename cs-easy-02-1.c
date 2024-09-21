#include <stdio.h>
#include <stdlib.h>
// 格式化文档了，真的是自己写的qwq
struct Node
{
    int data;
    struct Node *next;
};

struct Node *h = NULL;

struct Node *createNode(int x)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void init()
{
    h = createNode(1);
    h->next = h;
}

void H(int x)
{
    struct Node *p = createNode(x);
    if (h == NULL)
    {
        h = p;
        p->next = h;
        return;
    }
    struct Node *t = h;
    while (t->next != h)
    {
        t = t->next;
    }
    p->next = h;
    t->next = p;
    h = p;
}

void T(int x)
{
    struct Node *p = createNode(x);
    if (h == NULL)
    {
        h = p;
        h->next = h;
        return;
    }
    struct Node *t = h;
    while (t->next != h)
    {
        t = t->next;
    }
    t->next = p;
    p->next = h;
}

void D(int l)
{
    if (h == NULL)
        return;

    struct Node *t = h;
    if (l == 1)
    {
        if (h->next == h)
        {
            free(h);
            h = NULL;
            return;
        }
        struct Node *rm = h;
        while (t->next != h)
        {
            t = t->next;
        }
        h = h->next;
        t->next = h;
        free(rm);
        return;
    }
    for (int i = 1; i < l - 1; i++)
    {
        t = t->next;
        if (t->next == h)
            return;
    }
    if (t->next == h)
        return;
    struct Node *rm = t->next;
    t->next = rm->next;
    free(rm);
}
void C()
{
    if (h == NULL)
        return;
    struct Node *end = h;
    while (end->next != h)
    {
        end = end->next;
    }
    end->next = h;
}
void print(FILE *f)
{
    if (h == NULL)
    {
        fprintf(f, "NULL\n");
        return;
    }
    struct Node *t = h;
    do
    {
        fprintf(f, "%d -> ", t->data);
        t = t->next;
    } while (t != h);
    fprintf(f, "NULL\n");
}

int main()
{
    init();

    FILE *input = freopen("input.in", "r", stdin);
    FILE *output = freopen("output.out", "w", stdout);

    char x;
    int a, b, c, l;

    while (fscanf(input, " %c", &x) != EOF)
    {
        if (x == 'H')
        {
            fscanf(input, "%d %d %d", &a, &b, &c);
            H(c);
            H(b);
            H(a);
        }
        else if (x == 'T')
        {
            fscanf(input, "%d %d %d", &a, &b, &c);
            T(a);
            T(b);
            T(c);
        }
        else if (x == 'D')
        {
            fscanf(input, "%d", &l);
            D(l);
        }
        else
            C();
        print(output);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
