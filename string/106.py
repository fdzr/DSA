def arrangeWords(text: str) -> str:
    return " ".join(sorted(text.split(), key=len)).capitalize()


print(arrangeWords("To be or not to be"))
