N, K = map(int, input().split())

is_appear = [False]*N
for _ in range(K):
    _ = int(input())
    A = list(map(int, input().split()))
    for a in A:
        is_appear[a-1] = True

ans = 0
for b in is_appear:
    if b == False:
        ans += 1

print(ans)