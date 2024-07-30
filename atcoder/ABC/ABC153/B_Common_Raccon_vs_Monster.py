H, N = map(int, input().split())
A = list(map(int, input().split()))

S = sum(A)
if S >= H:
    print('Yes')
else:
    print('No')