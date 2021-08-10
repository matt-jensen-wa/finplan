class Node:
    next = None
    value = ""
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return self.value

class Queue:
    head = None
    tail = None
    def __init__(self):
        self.head = None

    def enqueue(self, node):
        if( self.tail is not None ):
            self.tail.next = node
        if( self.head is None ):
            self.head = node
        self.tail = node
        return

    def peek(self):
        return self.head

    def dequeue(self):
        n = self.head
        self.head = self.head.next
        n.next = None
        return n

    def __str__(self):
        n = self.head
        out = "queue: "
        while n is not None:
            out += " " + n.value
            n = n.next
        return out

    def isempty(self):
        return self.head is None
