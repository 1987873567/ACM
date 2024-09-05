def sovle():
    n, q = list(map(int, input().split()))
    s = list(map(int, input().split()))
    s = [0] + s
    for i in range(1, n + 1):
        s[i] += s[i - 1]

    def cal(x: int) -> int:
        res = 0
        p = x // n
        res += s[n] * p
        x %= n
        res += s[min(n, x + p)] - s[p]
        res += s[max(0, x + p - n)]
        return res

    while q > 0:
        q -= 1
        l, r = list(map(int, input().split()))
        x = cal(l - 1)
        y = cal(r)
        print(y - x)


T = int(input())

while T > 0:
    T -= 1
    sovle()
