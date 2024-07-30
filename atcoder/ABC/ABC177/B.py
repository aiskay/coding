S = input()
T = input()

ans = int(1e+3)
for i in range(len(S)-len(T)+1):
    num = 0
    for j in range(len(T)):
        if T[j] != S[i+j]:
            num += 1
    ans = min(ans, num)
print(ans)