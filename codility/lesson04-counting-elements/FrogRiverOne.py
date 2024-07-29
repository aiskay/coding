# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, A):
    # write your code in Python 3.6
    s = set()
    for i in range(1, X+1):
        s.add(i)
    for i in range(len(A)):
        s.discard(A[i])
        if(len(s) == 0):
            return i
    return -1