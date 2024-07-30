H, W = map(int, input().split())
S = []
for _ in range(H):
    S.append(input())

ans = 0
for i in range(H):
    for j in range(W):
        if S[i][j] == '.':
            if j+1 < W and S[i][j+1] == '.':
                ans += 1
            if i+1 < H and S[i+1][j] == '.':
                ans += 1
print(ans)