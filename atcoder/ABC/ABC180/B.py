import math

N = int(input())
x = list(map(int, input().split()))

manh, euc, chev = 0, 0, 0
for v in x:
    manh += abs(v)
    euc += v*v
    chev = max(chev, abs(v))

print(manh)
print('{:.10f}'.format(math.sqrt(euc)))
print(chev)