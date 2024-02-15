class Kante:
    def __init__(self):
        self.list = [2, 3, 4]

    def __add__(self, other: int):
        nou = Kante()
        nou.list = self.list
        nou.list.append(other)
        return nou
    # 1 2 3 4 4 5 6   sub kante - 4 1 2 3 5 6
    def __sub__(self, other: int): # suprascriem - (a - b --> sub(a,b) -- > Kante )
        nou = Kante()
        nou.list = self.list
        lista_noua = []

        for item in nou.list:
            if item != other:
                lista_noua.append(item)

        nou.list = lista_noua
        return nou

    def __sub__(self, other: str): # suprascriem - (a - b --> sub(a,b) -- > Kante )
        nou = Kante()
        nou.list = self.list
        lista_noua = []

        for item in nou.list:
            if item != other:
                lista_noua.append(item)

        nou.list = lista_noua
        return nou

    def __str__(self):
        return str(self.list)

    def __eq__(self, other):
        return self.list == other.list



plm = Kante()
plt = plm + 5 + 7 + 12 + 5
plt = plt + "as"
plt = plt - "as"
plt = plt - 12
print(plt)
