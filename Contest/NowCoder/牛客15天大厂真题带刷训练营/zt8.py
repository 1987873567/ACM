n = int(input())
ans = ''
l = 0
while n > 0:
    if n & 1: 
        ans += chr(ord('a') + l)  
    n >>= 1  
    l += 1  
print(ans)
