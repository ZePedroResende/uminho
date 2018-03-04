%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Base de Conhecimento com informacao genealogica.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SICStus PROLOG: Declaracoes iniciais

:- set_prolog_flag( discontiguous_warnings,off ).
:- set_prolog_flag( single_var_warnings,off ).
:- set_prolog_flag( unknown,fail ).

%pertence([H|T],Y):-
%  H=Y;
%  pertence(T,Y).

pertence([Y|T],Y).
pertence([H|T],Y):-
  H\=Y,
  pertence(T,Y).

tamanho([],0).
tamanho([H|T],Y):-
  tamanho(T,K),
  Y is K +1.

diferente([],0).
diferente([H|T],Y):-
  pertence(T,H), diferente(T,Y).
diferente([H|T],Y):-
  not(pertence(T,H)),
  diferente(T,K),
  Y is K +1.

%apaga1([],L,T).
%apaga1([H|T],L,X):-
  %apaga1()

  %apagaT()

concatenar([  ], l1,l2).
concatenar([X|L1],L2,[X|L]):-
  concatenar(L1,L2,L).

inverter([],[]).
inverter([X|L], NL):-
  inverter(L,I),
  concatenar(I,[X],NL).

sublista(_,[]).
sublista([X|L],[X|T]):- sublista(L,T).
sublista([Y|L],[X|T]]):- sublista([Y|L],T).

sublistaStor(L,S) :-
  concatenar(L1,L3,L),
  concatenar(S,L2,L3).

