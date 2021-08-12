#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include "database.h"

struct node *head;
struct node *init() {
    struct entry *data[SAMPLE_LIMIT];
    int rv = sample(data);
    if( rv > 0 ) {
        for(int i = 0; i < SAMPLE_LIMIT; i++) {
            struct node *n = malloc(sizeof(struct node *));
            n->data = data[i];
            n->next = NULL;
            add(n);
        }
        return head;
    } else {
        fprintf(stderr, "query returns no rows\n");
        exit(1);
    }
}

void add(struct node *add) {
    if( head == NULL ) {
        head = add;
        return;
    }
    add->next = head;
    head = add;
    return;
}
int length(struct node *head){
    struct node *cur = head;
    int len = 0;
    while(cur != NULL){
        len++;
        cur++;
    }
    return len;
}

void print() {
    struct node *cur = head;
    while(cur != NULL) {
        printf("%s\n", cur->data->description);
        cur = cur->next;
    }
    return;
}

