#include "queueADT.h"
#include <stdlib.h>

typedef struct node {
    elementType value;
    struct node *next;
} TNode;

struct queueCDT {
    TNode *first;
    TNode *last;
};

queueADT newQueue(void) {
    return calloc(1, sizeof(struct queueCDT));
}

int isEmpty(queueADT q) {
    return q->first == NULL;
}

void queue(queueADT q, elementType n) {
    TNode *aux = calloc(1, sizeof(TNode));
    aux->value = n;
    if (isEmpty(q)) {
        q->first = aux;
        q->last = aux;
    } else {
        q->last->next = aux;
        q->last = aux;
    }
}

void dequeue(queueADT q, elementType *out) {
    if (!isEmpty(q)) {
        *out = q->first->value;
        TNode *currentFirst = q->first;
        if (currentFirst == q->last) {
            q->first = q->last = NULL;
        } else {
            q->first = q->first->next;
        }
        free(currentFirst);
    }
}

static void freeRec(TNode * l);

void freeQueue(queueADT q) {

}
