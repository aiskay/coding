A, B, C = map(int, input().split())
K = int(input())

ans = False
for i in range(K+1):
    if C*2**i > B*2**(K-i) > A:
        ans = True
        break
if ans:
    print('Yes')
else:
    print('No')