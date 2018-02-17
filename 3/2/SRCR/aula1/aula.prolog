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
  filho( D,B), grau(B,A,N-1).

