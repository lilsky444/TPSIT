a = [1, 2, 3, 4]
b = a
c = a.copy()
b[0] = 9999
c[0] = 1111
print(a)
print(c)

a.pop(2)
print(a)