'''
b. Determine the union of two sets. The sets are represented as lists
'''

from List import *

def isElement(elements: list, element) -> bool:
    if not elements:
        return False
    
    if elements[0] == element:
        return True
    
    return isElement(elements[1:], element)

def combineSets(set1: list, set2: list):
    if not set1:
        return set2
    
    unionSet = combineSets(set1[1:], set2)
    
    if not isElement(unionSet, set1[0]):
        return [set1[0]] + unionSet
    
    return unionSet
    
#print(combineSets([2,3,4,5,6], [5,6,3,2,65,43]))

def isElementEnhanced(nod: Nod, element):
    if not nod:
        return False

    if nod.e == element:
        return True

    return isElementEnhanced(nod.urm, element)

def combineSetsEnhancedHelper(set1: Nod, set2: Lista, set3: Lista):
    if not set1:
        return set2

    if not isElementEnhanced(combineSetsEnhancedHelper(set1.urm, set2, set3).prim, set1.e):
        if(set1.urm == None):
            set1.urm = set2.prim

        newNode = Nod(set1.e)
        newNode.urm = set1.urm
        set3.prim = newNode
        return set3
    else:
        return combineSetsEnhancedHelper(set1.urm, set2, set3)

def combineSetsEnhanced(set1: Lista, set2: Lista):
    R = Lista()
    combineSetsEnhancedHelper(set1.prim, set2, R)
    return R

a = creareLista()
b = creareLista()
tipar(combineSetsEnhanced(a, b))