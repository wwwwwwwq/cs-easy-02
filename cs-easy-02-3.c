#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char i[1000];
    int t;
};

void init(struct Stack *s) {
    s->t = -1;
}

int isempty(struct Stack *s) {
    return s->t == -1;
}

void push(struct Stack *s, char x) {
    if (s->t < 999) {
        s->i[++(s->t)] = x;
    }
}

char pop(struct Stack *s) {
    return isempty(s) ? '\0' : s->i[(s->t)--];
}

void print(struct Stack *s) {
    for (int j = 0; j <= s->t; j++) {
        printf("%c ", s->i[j]);
    }
}

int main() {
    char c[] = "kiglnmrmeiahenrteof4ardar";
    char n[] = "3112212112122112211221122112111112";

    struct Stack s;
    init(&s);
    char d[1000];
    int di = 0, ci = 0;

    for (int i = 0; i < strlen(n); i++) {
        int num = n[i] - '0';

        if (i % 2 == 0) {
            for (int j = 0; j < num && c[ci] != '\0'; j++) {
                push(&s, c[ci++]);
            }
        } else {
            for (int j = 0; j < num; j++) {
                char pChar = pop(&s);
                if (pChar != '\0') {
                    d[di++] = pChar;
                } else {
                    break;
                }
            }
        }
    }

    d[di] = '\0';
    printf("%s\n", d);

    return 0;
}
