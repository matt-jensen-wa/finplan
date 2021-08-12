#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "linkedlist.h"
#include "database.h"

void usage(char *);

void usage(char *command) {
  fprintf (stderr, "%s: \n", command);
  exit(1);
}
enum db name = PGSQL;
int main(int argc, char **argv) {
    extern char *optarg;
    int ch;
    while ((ch = getopt(argc, argv, "d:")) != -1) {
        switch (ch) {
            case 'd':  /* database */
                name = strcmp(optarg, "pgsql") == 0 ? PGSQL : SQLITE;
        break;
            case '?': /* help */
            default:
            usage(argv[0]);
        }
    }
    if( init() == NULL ) {
        fprintf(stderr, "error creating linked list\n");
    }
    print();
}
