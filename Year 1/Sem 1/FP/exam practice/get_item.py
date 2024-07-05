

class SparseListIterator:
    def __init__(self, sparse_list):
        self.sparse_list = sparse_list
        self.index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.index < len(self.sparse_list):
            self.index += 1
            return self.sparse_list[self.index - 1]
        else:
            raise StopIteration


class SparseList:
    def __init__(self):
        self.list = []

    def __len__(self):
        return len(self.list)

    def __getitem__(self, item):
        return self.list[item]

    def __setitem__(self, key, value):
        if key >= len(self.list):
            for i in range(len(self.list), key + 1):
                self.list.append(0)

        self.list[key] = value

    def __str__(self):
        return str(self.list)

    def __iter__(self):
        return SparseListIterator(self)

"""
s = [2]
u = [3, [1232]]

s = s + u
print(s)
"""

def test(a, b):
    b = b + 1
    a.append(2)
    a = [2, 3]
    print(a)

a = []
b = 3

test(a, b)

print(a, b)