def isIsomorphic(s: str, t: str) -> bool:
    a = {}
    b = {}

    for index in range(len(s)):
        condition1 = s[index] in a and a[s[index]] != t[index]
        condition2 = t[index] in b and b[t[index]] != s[index]

        if condition1 or condition2:
            return False
        else:
            a[s[index]] = t[index]
            b[t[index]] = s[index]

    return True


print(isIsomorphic("foo", "bar"))
