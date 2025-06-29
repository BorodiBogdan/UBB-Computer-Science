class Nod:
    def __init__(self, e):
        self.e = e
        self.urm = None


class Lista:
    def __init__(self):
        self.prim = None

def creareLista():
    lista = Lista()
    lista.prim = creareLista_rec()
    return lista


def creareLista_rec():
    x = int(input("x="))
    if x == 0:
        return None
    else:
        nod = Nod(x)
        nod.urm = creareLista_rec()
        return nod


def tipar(lista):
    tipar_rec(lista.prim)
    print('')


def tipar_rec(nod):
    if nod != None:
        print(nod.e, end=" ")
        tipar_rec(nod.urm)
