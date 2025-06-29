from List import *
'''
a. Transform a list in a set.
'''
'''
def isInArray(elements: list, element) -> bool:
    if not elements:
        return False

    if elements[0] == element:
        return True

    return isInArray(elements[1:], element)

def transformList(elements: list):
    if not elements:
        return []

    transformedElements = transformList(elements[1:])

    if not isInArray(transformedElements, elements[0]):
        return [elements[0]] + transformedElements

    return transformedElements
'''

def isElement(nod: Nod, element):
    if not nod:
        return False

    if nod.e == element:
        return True

    return isElement(nod.urm, element)

def transformInSetHelper(nod: Nod, returnedList: Lista):
    if not nod.urm:
        returnedList.prim = nod
        return returnedList

    if not isElement(transformInSetHelper(nod.urm, returnedList).prim, nod.e):
        newNode = Nod(nod.e)
        newNode.urm = nod.urm
        returnedList.prim = newNode
        return returnedList
    else:
        return returnedList

def transformInSet(list : Lista):
    R = Lista()
    transformInSetHelper(list.prim, R)
    return R

a = creareLista()
tipar(transformInSet(a))

