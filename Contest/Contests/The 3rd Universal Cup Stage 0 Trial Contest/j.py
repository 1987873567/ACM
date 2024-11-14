n, p = list(map(int, input().split()))
# print(n, p)
v = [0] * (n + 1)
# s = [0] * (n + 1)
for i in range(1, n + 1):
	x = int(input())
	v[i] = x
	# s[i] = s[i - 1] + x
# def f(x : int):
# 	temp = s[x - 1]
# 	temp += (x - 1) * (v[x] - 1)
# 	return p - temp < v[x]
# l, r = 0, n + 1
# while l + 1 != r:
# 	m = (l + r) // 2
# 	if f(m):
# 		r = m
# 	else:
# 		l = m
# print(l)
s = 0
ans = 0
for i in range(1, n + 1):
	ss = s + (v[i] - 1) * (i)
	if(ss >= p):
		# print(i)
		break;
	s += v[i]
	ans = i
print(ans)
