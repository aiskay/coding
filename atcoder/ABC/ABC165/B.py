import math

X = int(input())

ans = 0
now = 100
while(now < X):
    now = math.floor(now*1.01)
    ans += 1

print(ans)