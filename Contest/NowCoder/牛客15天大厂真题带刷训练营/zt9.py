from math import log2
n, q = list(map(int, input().split()))
s = input()
s = ' ' + s
t = [0] * (n + 2);
def add(i : int, val :int):
	while i <= n:
		t[i] += val
		i += (i & (-i))
def ask(x : int):
	pos, Sum = 0, 0
	for j in range(int(log2(n) + 2), -1, -1):
		if pos + (1 << j) <= n and Sum + t[pos + (1 << j)] <= x:
			pos |= (1 << j)
			Sum += t[pos]
	return pos
def ask_range(l : int, r : int):
	return aks(r) - aks(l - 1)
for i in range(1, n + 1):
	add(i, 1)

while q > 0:
	l, r = list(map(int, input().split()))
	l, r = ask(l), ask(r)
	print(l, r)
	add(l, ask_range(l, l) - )
	add(r + 1, -1)
	q -= 1
ans = ""

for i, c in enumerate(s):
	ans += (c * i)
print(ans)
"""
abcdef
abbccddef

"""