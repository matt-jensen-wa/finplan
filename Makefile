PYTHON=~/.venv/bin/python3
DATA=stack queue linkedlist doublylinkedlist hashtable heap tree priorityqueue

all:
	$(PYTHON) test.py

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
