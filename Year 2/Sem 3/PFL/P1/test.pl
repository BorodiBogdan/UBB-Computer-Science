% Base case: An empty list results in an empty result.
remove_repetitive([], []).

% Recursive case: For each head element, check how many times it occurs in the list.
remove_repetitive([H|T], R) :-
    count_occurrences(H, [H|T], N),   % Count how many times H appears in the list.
   write(N),
   write('|'),
    N =:= 1,                          % If it appears exactly once,
    write(N),nl,
    remove_repetitive(T, R1),         % Process the rest of the list,
    R = [H|R1].                       % and include H in the result.

remove_repetitive([H|T], R) :-
    count_occurrences(H, [H|T], N),   % If H occurs more than once,
    N > 1,
    remove_repetitive(T, R).

% Helper predicate to count occurrences of an element in the list.
count_occurrences(_, [], 0).           % No more elements, count is 0.
count_occurrences(X, [X|T], N) :-      % If the head matches X,
    count_occurrences(X, T, N1),       % recursively count occurrences in the tail,
    N is N1 + 1.                       % and increment the count.
count_occurrences(X, [_|T], N) :-      % If the head does not match X,
    count_occurrences(X, T, N).        % move to the next element.
