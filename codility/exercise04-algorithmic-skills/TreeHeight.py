from collections import deque
from extratypes import Tree  # library with types used in the task

def solution(T):
    # write your code in Python 3.6

    height = -1

    q = deque()
    q.append(T)
    while q:
        n = len(q)
        for _ in range(n):
            node = q.popleft()
            if node.l:
                q.append(node.l)
            if node.r:
                q.append(node.r)
        height += 1
    
    return height