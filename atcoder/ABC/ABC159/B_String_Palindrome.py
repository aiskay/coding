S = input()
N = len(S)

def is_palindrome(s):
    n = len(s)
    i, j = 0, n-1
    while i < j:
        if s[i] != s[j]:
            return False
        else:
            i += 1
            j -= 1
    return True

if is_palindrome(S) and is_palindrome(S[:(N-1)//2]) and is_palindrome(S[(N+1)//2:]):
    print('Yes')
else:
    print('No')