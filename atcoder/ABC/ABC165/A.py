K = int(input())
A, B = map(int, input().split())

def check():
    for i in range(1, 1001):
        if A <= K*i <= B:
            return True
    return False

if check():
    print('OK')
else:
    print('NG')