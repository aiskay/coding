N, S = map(int, input().split())
A = list(map(int, input().split()))

MOD = 998244353

def solution(A, S):
    N = len(A)
    
    dp = [[0]*(S+1) for _ in range(N+1)]
    dp[0][0] = 1
    for i in range(1, N+1):
        for j in range(S+1):
            dp[i][j] += 2*dp[i-1][j]
            dp[i][j] %= MOD
            if j >= A[i-1]:
                dp[i][j] += dp[i-1][j-A[i-1]]
                dp[i][j] %= MOD
    return dp[N][S]

print(solution(A, S))