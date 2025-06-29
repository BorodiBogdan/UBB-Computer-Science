% reverse_list
% reverse_list(List, Acc, Result) - Reverses List by accumulating the result in Acc.
% Parameters:
% - List: The list to reverse.
% - Acc: An accumulator, initialized as an empty list. Stores the reversed list during recursion.
% - Result: The final reversed list when List is empty.
reverse_list([], Acc, Acc).
reverse_list([H|T], Acc, Result) :-
    reverse_list(T, [H|Acc], Result).


% reverse_list
% reverse_list(List, Result) - Reverses List and unifies the reversed list with Result.
% Parameters:
% - List: The list to reverse.
% - Result: The reversed list.
reverse_list(List, Result) :-
    reverse_list(List, [], Result).

% multiply_digits
% multiply_digits(Digits, Multiplier, Carry, Result) - Multiplies each digit in Digits (in reverse order) by Multiplier, handling carries.
% Parameters:
% - Digits: The list of digits to multiply, in reverse order.
% - Multiplier: The single digit multiplier.
% - Carry: The carry from the previous multiplication, initially 0.
% - Result: The resulting list of digits after multiplication, in reverse order.
%
multiply_digits([], _, 0, []).
multiply_digits([], _, Carry, [CarryDigit|[]]) :-
    Carry > 0,
    CarryDigit is Carry mod 10.
multiply_digits([], _, Carry, [CarryDigit|Result]) :-
    Carry > 0,
    CarryDigit is Carry mod 10,
    NewCarry is Carry // 10,
    multiply_digits([], _, NewCarry, Result).
multiply_digits([D|Digits], Multiplier, Carry, [ResDigit|Result]) :-
    Product is D * Multiplier + Carry,
    ResDigit is Product mod 10,
    NewCarry is Product // 10,
    multiply_digits(Digits, Multiplier, NewCarry, Result).

% multiply_by_digit
% multiply_by_digit(NumberList, Multiplier, Result) - Multiplies NumberList (a list of digits) by a single digit Multiplier.
% Parameters:
% - NumberList: The list of digits representing the number to multiply.
% - Multiplier: The single digit multiplier.
% - Result: The resulting list of digits after multiplication.
multiply_by_digit(NumberList, Multiplier, Result) :-
    reverse_list(NumberList, RevNumberList),
    multiply_digits(RevNumberList, Multiplier, 0, RevResult),
    reverse_list(RevResult, Result).

% Test cases for reverse_list
testReverseList :-
    reverse_list([], []),
    reverse_list([1], [1]),
    reverse_list([1, 2, 3], [3, 2, 1]),
    reverse_list([a, b, c], [c, b, a]).

% Test cases for multiply_by_digit
testMultiplyByDigit :-
    multiply_by_digit([1, 2, 3], 2, [2, 4, 6]),
    multiply_by_digit([9, 9], 9, [8, 9, 1]),
    multiply_by_digit([5, 5], 3, [1, 6, 5]),
    multiply_by_digit([4, 4, 4], 2, [8, 8, 8]).

% Run all tests
testAllFunctions :-
    testReverseList,
    testMultiplyByDigit.





