from src.queue import Queue, Node

q = Queue()
for x, i in enumerate(range(10)):
    n = Node("hello " + str(i))
    q.enqueue(n)
    print("enqueue: " + str(n))
print(q)
while q.isempty() != True:
    print("dequeue: " + str(q.dequeue()))
