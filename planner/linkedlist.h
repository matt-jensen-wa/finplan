struct node {
    struct node *next;
    struct entry *data;
};

void add(struct node *);
struct node *get();
struct node *peek();
int length(struct node *);
void del(struct node *);
void isempty(struct node *);
void print();
struct node *init();
