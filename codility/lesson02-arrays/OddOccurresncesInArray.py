# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    d = {}
    for a in A:
        if a not in d:
            d[a] = 1
        else:
            d[a] += 1

    for k, v in d.items():
        if v%2 == 1:
            return k