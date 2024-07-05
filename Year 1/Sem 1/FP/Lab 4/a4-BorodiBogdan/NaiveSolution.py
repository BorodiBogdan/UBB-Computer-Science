"""
Given the set of positive integers S, partition this set into two subsets S1 and S2 so that the difference
between the sum of the elements in S1 and S2 is minimal. For example, for set S = { 1, 2, 3, 4, 5 }, the two
subsets could be S1 = { 1, 2, 4 } and S2 = { 3, 5 }. Display at least one of the solutions.
"""
def FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(HowManyElementsAreInTheSetOfPositiveIntegers, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset, FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning, SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning):
    if(HowManyElementsAreInTheSetOfPositiveIntegers == -1):
        return [TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset, abs(TotalSumOfTheFirstPartitionedSubset - TotalSumOfTheSecondPartitionedSubset), FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning, SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning]

    SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning.append(SetOfPositiveIntegers[HowManyElementsAreInTheSetOfPositiveIntegers])
    FirstWayOfPartitioningTheSetOfPositiveIntegers = FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(HowManyElementsAreInTheSetOfPositiveIntegers - 1, TotalSumOfTheFirstPartitionedSubset, TotalSumOfTheSecondPartitionedSubset + SetOfPositiveIntegers[HowManyElementsAreInTheSetOfPositiveIntegers], FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning[:], SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning[:])

    SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning.pop()
    FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning.append(SetOfPositiveIntegers[HowManyElementsAreInTheSetOfPositiveIntegers])

    SecondWayOfPartitioningTheSetOfPositiveIntegers = FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(HowManyElementsAreInTheSetOfPositiveIntegers - 1, TotalSumOfTheFirstPartitionedSubset + SetOfPositiveIntegers[HowManyElementsAreInTheSetOfPositiveIntegers], TotalSumOfTheSecondPartitionedSubset, FirstSubsetThatGivesTheMinimumDifferenceWhenPartitioning[:], SecondSubsetThatGivesTheMinimumDifferenceWhenPartitioning[:])


    if(abs(SecondWayOfPartitioningTheSetOfPositiveIntegers[1] - SecondWayOfPartitioningTheSetOfPositiveIntegers[0]) < abs(FirstWayOfPartitioningTheSetOfPositiveIntegers[1] - FirstWayOfPartitioningTheSetOfPositiveIntegers[0])):
        return SecondWayOfPartitioningTheSetOfPositiveIntegers
    else:
        return FirstWayOfPartitioningTheSetOfPositiveIntegers


SetOfPositiveIntegers = [1, 2, 3, 4, 5]

InformationAboutTheOptimalWayToPartitionASetOfPositiveIntegersSuchThatTheDifferenceBetweenThemIsMinimum = FindTwoPartitionsOfTheSetOfPositiveIntegersThatHaveTheDifferenceBetweenTheSumOfThemMinimum(4, 0, 0, [], [])

print("Subset 1: " + str(InformationAboutTheOptimalWayToPartitionASetOfPositiveIntegersSuchThatTheDifferenceBetweenThemIsMinimum[3]))
print("Subset 2: " + str(InformationAboutTheOptimalWayToPartitionASetOfPositiveIntegersSuchThatTheDifferenceBetweenThemIsMinimum[4]))