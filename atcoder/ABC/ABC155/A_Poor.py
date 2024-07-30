A, B, C = map(int, input().split())

if (A == B and A != C) or (A == C and A != B) or (B == C and A != B):
    print('Yes')
else:
    print('No')