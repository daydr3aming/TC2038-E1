def longestPalindrome(s):

# Algoritmo de Manacher
    n = len(s)
    a = [None] * (n-1)
    r = -1
    p = -1
    for i in range(0, n-1):
        if i <= r:
            a[i] = min(a[2*p-i], r-i)
        else:
            a[i] = 0
        while i-a[i]-1 >= 0 and i+a[i]+1 < n and s[i-a[i]-1] == s[i+a[i]+1]:
            a[i] = a[i] + 1
        if i+a[i] > r:
            r = i+a[i]
            p = i
    return a

# Palindromo mas largo
def matchPalindrome(string, lsp):
    indexpal = lsp.index(max(lsp))
    return string[indexpal-lsp[indexpal]:indexpal+lsp[indexpal]+1]
   
# Programa principal
string = "abacabacabb"
lsp = longestPalindrome(string)
print(f"Longest palindrome: {matchPalindrome(string, lsp)}")



