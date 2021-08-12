#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include "database.h"

char *dburl() {
    char *url = malloc(sizeof(char)* 255);
    char *host = getenv("DB_HOST");
    host = host == NULL ? "localhost" : host;
    char *username = getenv("DB_USERNAME");
    username = username == NULL ? "postgres" : username;
    char *database = getenv("DB_DATABASE");
    database = database == NULL ? "postgres" : database;
    char *password = getenv("DB_PASSWORD");
    password = password == NULL ? "" : password;
    snprintf(url, 255, "host=%s dbname=%s user=%s password=%s", host, database, username, password);
    return url;
}
PGresult *get_pgsql() {
    char *url = dburl();
    fprintf(stderr, "%s\n", url);
    PGconn *conn =  PQconnectdb(url);
    if( PQstatus(conn) == CONNECTION_BAD ) {
        fprintf(stderr, "error connection to database");
    }
    const char *query = "select date, description, amount, type from finance.transactions order by date desc limit $1";
    int nParams = 1;
    const char *params[nParams];
    char str[32];
    sprintf(str, "%d", SAMPLE_LIMIT);
    params[0] = str;
    PGresult *result = PQexecParams(conn, query, nParams, NULL, params, NULL, NULL, 0);
    // if( PQcmdStatus(PGresult *res);
    if( PQresultStatus(result) != PGRES_TUPLES_OK ) {
        fprintf(stderr, "query error (%s)\n", PQresultErrorMessage(result));
        exit(127);
    }
    return result;
}
int sample(struct entry *dest[]) {
    int rows = 0;
    if( name == PGSQL ) {
        PGresult *res = get_pgsql();
        rows = PQntuples(res);
        for( int i = 0; i < rows; i++ ) {
            struct entry* record = (struct entry *) malloc(sizeof(struct entry));
            float a;
            sscanf(PQgetvalue(res, i, 2), "%f", &a);
            record->description = PQgetvalue(res, i, 1);
            record->amount = a;
            dest[i] = record;
        }
    } else {
        fprintf(stderr, "%s", "sqlite support not implemented");
        exit(1);
    }
    return rows;
}
