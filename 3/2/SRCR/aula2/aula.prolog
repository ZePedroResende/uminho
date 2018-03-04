%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Base de Conhecimento com informacao genealogica.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SICStus PROLOG: Declaracoes iniciais

:- set_prolog_flag( discontiguous_warnings,off ).
:- set_prolog_flag( single_var_warnings,off ).
:- set_prolog_flag( unknown,fail ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado filho: Filho,Pai -> {V,F}


filho( joao,jose ).
filho( jose,manuel ).
filho( carlos,jose ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado pai: Pai,Filho -> {V,F}

pai( P,F ) :-
  filho( F,P ).

pai(paulo,filipe).
pai(paulo,maria).
%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado avo: Avo,Neto -> {V,F}
avo( A,N ) :-
  pai( A,P ), pai( P,N ).


avo(antonio,nadia).


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado bisavo: Bisavo,Bisneto -> {V,F}
bisavo( BA,BN ) :-
  pai(BA,A), avo(A,BN).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% predicado masculino: Pessoa -> {V}
masculino(joao).
masculino(jose).
masculino(carlos).
masculino(manuel).
masculino(paulo).
masculino(antonio).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% predicado feminino: Pessoa -> {V}
feminino(maria).
feminino(joana).
feminino(nadia).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado descendente: Descendente,Ascendente -> {V,F}
descendente( D,A ) :-
  filho( D,A ).
descendente( D,A ) :-
  filho(D,B), descendente(B,A).

ascendente( A,D ) :-
  descendente(D,A).



%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado descendente: Descendente,Ascendente,Grau -> {V,F}

grau( D,A,1 ) :-
  filho( D,A ).
grau( D,A,N ) :-
  filho( D,B), grau(B,A,G),
  N is G+1.


%------------------------------------------------------------------------------------------
% Extensao do predicado

soma(X,Y,R) :-
   R is X+Y.


soma3(X,Y,R,Z) :-
   Z is X+Y+R.

% ele expande a lista e começa da direita para a esquerda dai o [],0
% [1,2,3]
% soma([2,3],soma([3],soma([],soma([],0)+3)+2)+1)
soma([],0).
soma([H|T],R):-
  soma(T,S),
  R is H + S.

% operacao aritmetica(adicao,subtracao,multiplicacao,divisao)
operacao(X,-,Y,Z) :-
   Z is X+Y.
operacao(X,+,Y,Z) :-
   Z is X+Y.
operacao(X,*,Y,Z) :-
   Z is X*Y.
operacao(X,/,Y,Z) :-
   Y \= 0,
   Z is div(X,Y).

%
maior(X,Y,X) :-
  X>Y.
maior(X,Y,Y) :-
  X<Y.

maior3(X,Y,Z,X) :-
  maior(X,Y,X),maior(X,Z,X).
maior3(X,Y,Z,Y) :-
  maior(X,Y,Y),maior(Y,Z,Y).
maior3(X,Y,Z,Z) :-
  maior(X,Z,Z),maior(Y,Z,Z).


opLista([],+,0).
opLista([H|T],+,R):-
  opLista(T,+,S),
  R is H + S.

opLista([],-,0).
opLista([H|T],-,R):-
  opLista(T,-,S),
  R is H - S.

opLista([],*,1).
opLista([H|T],*,R):-
  opLista(T,*,S),
  R is H * S.

opLista([],/,1).
opLista([H|T],/,R):-
  opLista(T,/,S),
  R is div(H,S).

