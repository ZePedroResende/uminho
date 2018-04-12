%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Programacao em logica estendida

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SICStus PROLOG: Declaracoes iniciais

:- set_prolog_flag( discontiguous_warnings,off ).
:- set_prolog_flag( single_var_warnings,off ).
:- set_prolog_flag( unknown,fail ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SICStus PROLOG: definicoes iniciais

:- dynamic '-'/1.
%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado nao: Questao -> {V,F}

nao( Questao ) :-
    Questao, !, fail.
nao( Questao ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado demo: Questao,Resposta -> {V,F}

demo( Questao,verdadeiro ) :-
    Questao.
demo( Questao,falso ) :-
    -Questao.
demo( Questao,desconhecido ) :-
    nao( Questao ),
    nao( -Questao ).

%-----------------------------
%% 1

jogo(1,aa,500).
-jogo(I,1,C) :-
  nao(jogo(I,1,C)),
  nao(excecao(jogo(I,1,C))).

%% 2 - incerto
jogo(2,bb,xpto023).
excecao(jogo(I,A,C)) :- jogo(I,A,xpto023).

%% 3 - impreciso
excecao(jogo(3,cc,500)).
excecao(jogo(3,cc,2000)).

%% 4 - impreciso
excecao(jogo(4,dd,250)).
excecao(jogo(4,dd,750)).

%% 5 - interdito
