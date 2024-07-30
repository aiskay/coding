X, Y = map(int, input().split())

if (Y-2*X)%2 == 0 and Y-2*X >= 0 and (4*X-Y)%2 == 0 and 4*X-Y >= 0:
    print('Yes')
else:
    print('No')