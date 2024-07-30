A = [list( map(int, input().split()) ) for _ in range(3)]
N = int(input())
b = set([int(input()) for _ in range(N)])

def check(A, b):
    # 横
    for i in range(3):
        col, row = [], []
        for j in range(3):
            col.append(A[i][j])  # 横
            row.append(A[j][i])  # 縦
        if set(col) <= b or set(row) <= b:
            return True

    # 斜め
    if set([A[0][0], A[1][1], A[2][2]]) <= b or set([A[0][2], A[1][1], A[2][0]]) <= b:
        return True

if check(A, b):
    print('Yes')
else:
    print('No')