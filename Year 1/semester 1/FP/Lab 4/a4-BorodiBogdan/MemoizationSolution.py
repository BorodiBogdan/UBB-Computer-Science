"""
Given the set of positive integers S, partition this set into two subsets S1 and S2 so that the difference
between the sum of the elements in S1 and S2 is minimal. For example, for set S = { 1, 2, 3, 4, 5 }, the two
subsets could be S1 = { 1, 2, 4 } and S2 = { 3, 5 }. Display at least one of the solutions.
"""
def PrintCacheNicely(cache):
    for element in cache:
        print (element, end = ": ")
        print(cache[element])
def FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(SetOfPositiveIntegers, CurrentElementOfThePositiveIntegersSet, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset, FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning, SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning, CacheForMemorisingFindPartitionFunctionCalls):
    if CurrentElementOfThePositiveIntegersSet == -1:
        return [TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset, abs(TotalSumOfTheFirstPartitionedSubset - TotalSumOfTheSecondPartitionedSubset), FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning, SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning]

    if (CurrentElementOfThePositiveIntegersSet, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset) in CacheForMemorisingFindPartitionFunctionCalls:
        return CacheForMemorisingFindPartitionFunctionCalls[(CurrentElementOfThePositiveIntegersSet, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset)]

    SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning.append(SetOfPositiveIntegers[CurrentElementOfThePositiveIntegersSet])
    FirstWayOfPartitioningTheSetOfPositiveIntegers = FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(SetOfPositiveIntegers, CurrentElementOfThePositiveIntegersSet - 1, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset + SetOfPositiveIntegers[CurrentElementOfThePositiveIntegersSet], FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning.copy(), SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning.copy(), CacheForMemorisingFindPartitionFunctionCalls)

    SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning.pop()
    FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning.append(SetOfPositiveIntegers[CurrentElementOfThePositiveIntegersSet])
    SecondWayOfPartitioningTheSetOfPositiveIntegers = FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(SetOfPositiveIntegers, CurrentElementOfThePositiveIntegersSet - 1, TotalSumOfTheFirstPartitionedSubset + SetOfPositiveIntegers[CurrentElementOfThePositiveIntegersSet], TotalSumOfTheSecondPartitionedSubset, FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning.copy(), SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning.copy(), CacheForMemorisingFindPartitionFunctionCalls)

    if SecondWayOfPartitioningTheSetOfPositiveIntegers[2] < FirstWayOfPartitioningTheSetOfPositiveIntegers[2]:
        CacheForMemorisingFindPartitionFunctionCalls[(CurrentElementOfThePositiveIntegersSet, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset)] = SecondWayOfPartitioningTheSetOfPositiveIntegers
        return SecondWayOfPartitioningTheSetOfPositiveIntegers

    else:
        CacheForMemorisingFindPartitionFunctionCalls[(CurrentElementOfThePositiveIntegersSet, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset)] = FirstWayOfPartitioningTheSetOfPositiveIntegers
        return FirstWayOfPartitioningTheSetOfPositiveIntegers

SetOfPositiveIntegers = [1, 2]
CacheForMemorisingFindPartitionFunctionCalls = {}
InformationAboutTheOptimalWayToPartitionASetOfPositiveIntegersSuchThatTheDifferenceBetweenThemIsMinimum = FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(SetOfPositiveIntegers, len(SetOfPositiveIntegers) - 1, 0, 0, [], [], CacheForMemorisingFindPartitionFunctionCalls)

#print(CacheForMemorisingFindPartitionFunctionCalls)
PrintCacheNicely(CacheForMemorisingFindPartitionFunctionCalls)

print("Subset 1: " + str(InformationAboutTheOptimalWayToPartitionASetOfPositiveIntegersSuchThatTheDifferenceBetweenThemIsMinimum[3]))
print("Subset 2: " + str(InformationAboutTheOptimalWayToPartitionASetOfPositiveIntegersSuchThatTheDifferenceBetweenThemIsMinimum[4]))