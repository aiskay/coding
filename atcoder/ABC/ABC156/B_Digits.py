N, K = map(int, input().split())

ans = 0
while N//K > 0:
    N //= K
    ans += 1

print(ans+1)