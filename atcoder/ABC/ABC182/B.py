N = int(input())
A = list(map(int, input().split()))

import math

ans = 0
mx = 0
for k in range(2, 1000):
    num = 0
    for a in A:
        if a%k == 0:
            num += 1
    if num > mx:
        mx = num
        ans = k

print(ans)