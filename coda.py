import queue

coda = queue.Queue()
#enqueue -> put
#dequeue -> get

coda.put(3)
coda.put(5)
coda.put(19)

print(coda.get()) #legge l'elemento e lo toglie
print(list(coda.queue))