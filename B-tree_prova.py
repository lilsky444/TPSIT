import random

class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

    def insertNode(self, key):
        if self.key is not None:
            if key > self.key:
                if self.right is None:
                    self.right = Node(key)
                else:
                    self.right.insertNode(key)
            elif key < self.key:
                if self.left is None:
                    self.left = Node(key)
                else:
                    self.left.insertNode(key)
        else:
            self.key = key

    def printTree(self, level=0):
        if self.left is not None:
            self.left.printTree(level+1)
        print(f'Livello {level} -> {self.key}')
        if self.right is not None:
            self.right.printTree(level+1)

    def ricerca(self, key):
        if key > self.key:
            if self.right is not None:
                if key != self.right:
                    return f"Nodo {key} non trovato"
                return self.right.ricerca(key)
        elif key < self.key:
            if self.left is not None:
                if key != self.left:
                    return f"Nodo {key} non trovato"
                return self.left.ricerca(key)
        else:
            return f"Nodo {key} trovato"
        
    def altezza(self, key):
        if self.key is not None:
            cont = 1
            if key > self.key:
                if self.right is not None:
                    cont += 1
                else:
                    return self.right.altezza(key)
            elif key < self.key:
                if self.left is not None:
                    cont += 1
                else:
                    return self.left.altezza(key)
        return cont
                    

def main():
    lista_key = list(range(0, 40, 5))
    random.shuffle(lista_key)
    print(lista_key)
    albero = Node(lista_key[0])
    for key in lista_key[1:]:
        albero.insertNode(key)

    if albero.ricerca(30):
        print(f'Trovato')
    else: print(f'Non trovato')

    albero.altezza(lista_key[0])

    lista_key.sort()

    print(albero.printTree())

if __name__ =="__main__":
    main()