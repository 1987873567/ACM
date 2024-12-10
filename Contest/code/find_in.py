with open('a.txt', 'r') as file:
    a = file.read().split()
with open('b.txt', 'r') as file:
    b = file.read().split()
with open('ask.txt', 'r') as file:
	ask = file.read().split()
# print(a)
# print(b)
# print(ask)
op, x, y = list(map(int, input().split()))
my = []
if op == 1:
    if x == 'a':
        a.append(y)
    else:
        b.append(y)
else:
	for i in ask:
		if (str(i) in a) or (str(i) in b):
			my.append(i)
print(my)
with open('a.txt', 'w') as file:
    file.write(' '.join(a))
with open('b.txt', 'w') as file:
    file.write(' '.join(b))
with open('ask.txt', 'w') as file:
    file.write(' '.join(my))
