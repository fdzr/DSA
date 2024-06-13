def isValid(word: str) -> bool:
    vowels = "aeiou"
    vowels += vowels.upper()
    consonants = "bcdfghjklmnpqrstvwxyz"
    consonants += consonants.upper()
    digits = "0123456789"
    allowed = vowels + consonants + digits

    if len(word) < 3:
        return False

    has_consonant = False
    has_vowel = False
    for ch in word:
        if ch in vowels:
            has_vowel = True
        if ch in consonants:
            has_consonant = True
        if ch not in allowed:
            return False

    return has_vowel and has_consonant


print(isValid("OwP"))
