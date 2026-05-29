def numberOfSpecialChars(word: str) -> int:
    lowercase_table = [0] * 26
    uppercase_table = [0] * 26

    for ch in word:
        character_converted = ord(ch)

        if ch.islower():
            if uppercase_table[character_converted - 32 - 65] == 0:
                lowercase_table[character_converted - 97] = 1
            else:
                lowercase_table[character_converted - 97] = 0
        else:
            uppercase_table[character_converted - 65] = 1

    answer = 0
    for index in range(26):
        if uppercase_table[index] != 0:
            answer += lowercase_table[index]

    return answer


cad = "AbBCab"
print(numberOfSpecialChars(cad))
