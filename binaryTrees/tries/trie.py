class Trie:
    def __init__(self):
        self.children = {}
        self.is_leaf = False

    def insert(self, key: str):
        curr = self

        for ch in key:
            curr = curr.children.setdefault(ch, Trie())

        curr.is_leaf = True

    def search(self, key: str):
        curr = self

        for ch in key:
            curr = curr.children.get(ch)
            if curr is None:
                return False

        return curr.is_leaf


if __name__ == "__main__":
    t = Trie()
    t.insert("xyz")
    print(t.search("xy"))
    print(t.search("xyz"))
