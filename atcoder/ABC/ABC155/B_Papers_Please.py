N = int(input())
A = list(map(int, input().split()))

ans = True
for a in A:
    if a%2 == 0 and a%3 != 0 and a%5 != 0:
        ans = False
        break

if ans:
    print('APPROVED')
else:
    print('DENIED')