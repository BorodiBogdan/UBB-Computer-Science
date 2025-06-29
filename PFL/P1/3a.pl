remove([], _, []).
remove([H|T], H, R) :-
    remove(T, H, R).
remove([H|T], E, [H|R]) :-
    H =\= E,
    remove(T, E, R).

count_occ([], _, 0).
count_occ([H|T], H, R) :-
    count_occ(T, H, R1),
    R is R1 + 1.
count_occ([H|T], E, R) :-
    H =\= E,
    count_occ(T, E, R).

remove_rep([], []).
remove_rep([H|T], [H|R]) :-
    count_occ(T, H, C),
    C =:= 0,
    remove_rep(T, R).
remove_rep([H|T], R) :-
    count_occ(T, H, C),
    C =\= 0,
    remove([H|T], H, R1),
    remove_rep(R1, R).
