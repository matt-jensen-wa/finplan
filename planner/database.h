enum debitorcredit {DEBIT, CREDIT};
struct entry {
    int date;
    char *description;
    float amount;
    enum debitorcredit type;
};
int sample(struct entry **);

#define SAMPLE_LIMIT 100
enum db {PGSQL, SQLITE};
extern enum db name;
