# PYTHON=~/.venv/bin/python3
SRC=planner
DIST=dist
CFILES=$(wildcard $(SRC)/*.c)
OBJS=$(CFILES:.c=.o)
CFLAGS= -Wall -Wextra -g
CFLAGS += $(shell pkg-config --cflags libpq)
CFLAGS += -lpq
DBPATH = database
SQL = sqlite3
SQLFLAGS = -bail

all: planner

# python:
# 	$(PYTHON) test.py

data:
	$(SQL) $(SQLFLAGS) $(DBPATH)/finance.db < $(DBPATH)/create.sql
	$(SQL) $(SQLFLAGS) $(DBPATH)/finance.db < $(DBPATH)/import.sql

planner: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(DIST)/$@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf src/*.o
	$(SQL) $(SQLFLAGS) $(DBPATH)/finance.db < $(DBPATH)/drop.sql
