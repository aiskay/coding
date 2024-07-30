N, M = map(int, input().split())
A = list(map(int, input().split()))

A.sort(reverse=True)
S = sum(A)

ans = True
for i in range(M):
    if A[i]*4*M < S:
        ans = False
        break

if ans:
    print('Yes')
else:
    print('No')