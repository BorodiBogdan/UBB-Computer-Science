"""
Given the set of positive integers S, partition this set into two subsets S1 and S2 so that the difference
between the sum of the elements in S1 and S2 is minimal. For example, for set S = { 1, 2, 3, 4, 5 }, the two
subsets could be S1 = { 1, 2, 4 } and S2 = { 3, 5 }. Display at least one of the solutions.
"""
def min_partition_difference(GivenSetInTheProblem):
    CandidateForSubsetSum = sum(GivenSetInTheProblem)
    LengthOfTheSet = len(GivenSetInTheProblem)

    # Create a table to store the results of subproblems
    CheckIfTheSumCanBeWrittenWithElementsOfTheSet = [[False] * (CandidateForSubsetSum // 2 + 1) for _ in range(LengthOfTheSet + 1)]

    # Initialize the first column as True, since we can achieve a sum of 0 with an empty subset
    for NumberOfElements in range(LengthOfTheSet + 1):
        CheckIfTheSumCanBeWrittenWithElementsOfTheSet[NumberOfElements][0] = True

    # Fill the table using a bottom-up approach
    for NumberOfElements in range(1, LengthOfTheSet + 1):
        for GivenSum in range(1, CandidateForSubsetSum // 2 + 1):
            CheckIfTheSumCanBeWrittenWithElementsOfTheSet[NumberOfElements][GivenSum] = CheckIfTheSumCanBeWrittenWithElementsOfTheSet[NumberOfElements - 1][GivenSum]
            if GivenSetInTheProblem[NumberOfElements - 1] <= GivenSum:
                CheckIfTheSumCanBeWrittenWithElementsOfTheSet[NumberOfElements][GivenSum] |= CheckIfTheSumCanBeWrittenWithElementsOfTheSet[NumberOfElements - 1][GivenSum - GivenSetInTheProblem[NumberOfElements - 1]]

    # Find the largest GivenSum for which CheckIfTheSumCanBeWrittenWithElementsOfTheSet[LengthOfTheSet][GivenSum] is True
    GivenSum = CandidateForSubsetSum // 2

    while not CheckIfTheSumCanBeWrittenWithElementsOfTheSet[LengthOfTheSet][GivenSum]:
        GivenSum -= 1

    # Reconstruct the subsets
    OneOfTheSubsetsThatGivesTheMinimumDifferenceWhenPartitioning = []
    AnotherSubsetThatGivesTheMinimumDifferenceWhenPartitioning = []
    NumberOfElements = LengthOfTheSet

    while NumberOfElements > 0 and GivenSum > 0:
        if not CheckIfTheSumCanBeWrittenWithElementsOfTheSet[NumberOfElements - 1][GivenSum]:
            OneOfTheSubsetsThatGivesTheMinimumDifferenceWhenPartitioning.append(GivenSetInTheProblem[NumberOfElements - 1])
            GivenSum -= GivenSetInTheProblem[NumberOfElements - 1]
        else:
            AnotherSubsetThatGivesTheMinimumDifferenceWhenPartitioning.append(GivenSetInTheProblem[NumberOfElements - 1])
        NumberOfElements -= 1

    return OneOfTheSubsetsThatGivesTheMinimumDifferenceWhenPartitioning, AnotherSubsetThatGivesTheMinimumDifferenceWhenPartitioning

# Example usage
SetOfPositiveIntegers = [1, 2, 3, 4, 5]

OneOfTheSubsetsThatGivesTheMinimumDifferenceWhenPartitioning, AnotherSubsetThatGivesTheMinimumDifferenceWhenPartitioning = min_partition_difference(SetOfPositiveIntegers)

print("Subset 1:", OneOfTheSubsetsThatGivesTheMinimumDifferenceWhenPartitioning)
print("Subset 2:", AnotherSubsetThatGivesTheMinimumDifferenceWhenPartitioning)