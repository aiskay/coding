# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N):
    # write your code in Python 3.6
    ans, pos = 0, -1
    for i in range(len(bin(N))-2):
        if N & (1<<i):
            if pos != -1:
                ans = max(ans, i-pos-1)
            pos = i
    return ans


if __name__ == '__main__':

    N = int(input())
    print(solution(N))