import itertools
import numpy as np
from numpy.linalg import det

k = 4
n = 5
cnt = 0


def multiply_tuple(tuple_input, factor):  # for multipling the vector with a scalar
    multiplied_tuple = tuple(element * factor for element in tuple_input)
    return multiplied_tuple


maxlen = 0
ans = []  # here we store the answer
vectors = [vec for vec in itertools.product([0, 1], repeat=n) if any(vec)]  # all vectors
scalars = [vec for vec in itertools.product([0, 1], repeat=k)]  # all scalars

combinations = list(itertools.combinations(vectors, k))  # all possible k combinations of vectors

IsOrNot = {}  # to verify if we have generated the subspace or not
cnt = 0  # number of bases

for bases in combinations:

    subspace = []

    for scalars_set in scalars:  # we take all possible ways of  multiplying
        res = tuple([0] * n)

        for scalar, vector in zip(scalars_set, bases):
            res = tuple(
                (x ^ y) for x, y in zip(res, multiply_tuple(vector, scalar)))  # we multiply the vector eith the scalar

        subspace.append(res)

    subspace = tuple(sorted(subspace))
    subspace = tuple(set(subspace))

    if subspace not in IsOrNot:
        if (len(subspace) > maxlen):
            maxlen = len(subspace)
            ans.clear()
            ans.append(bases)
            cnt = 1
        elif (len(subspace) == maxlen):
            ans.append(bases)
            cnt += 1

        IsOrNot[subspace] = 1

print("The number of " + str(k) + "-dimensional subspaces of the vector (Z_2)^" + str(n) + " is: " + str(
    cnt))  # here we print the answers

for base in ans:
    print(base)