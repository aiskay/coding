N, X = map(int, input().split())
S = input()

for s in S:
    if s == 'o':
        X += 1
    elif s == 'x' and X > 0:
        X -= 1
print(X)