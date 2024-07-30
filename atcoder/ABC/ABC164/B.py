A, B, C, D = map(int, input().split())

while A > 0 and B > 0:
    C -= B
    A -= D

if C > 0:
    print('No')
else:
    print('Yes')