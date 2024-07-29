def solution(A):
    # write your code in Python 3.6
    N = len(A)

    ans = 0
    cum_sum = A.copy()
    for i in reversed(range(N-1)):
        cum_sum[i] += cum_sum[i+1]
        if A[i] == 0:
            ans += cum_sum[i]
    
    if ans > int(1e+9):
        return -1
    return ans