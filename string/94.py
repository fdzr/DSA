import string
import random


class Codec:
    def __init__(self):
        self.code = {}
        self.decode_url = {}
        self.characters = string.ascii_letters + string.digits

    def get_code(self):
        new_code = "".join([random.choice(self.characters) for i in range(10)])

        return new_code

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL."""

        new_code = self.get_code()
        while new_code in self.code:
            new_code = self.get_code()

        self.code[new_code] = longUrl
        self.decode_url[longUrl] = new_code
        return new_code

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL."""
        return self.code[shortUrl]


if __name__ == "__main__":
    url = "https://leetcode.com/problems/design-tinyurl"
    codec = Codec()
    print(codec.decode(codec.encode(url)))
