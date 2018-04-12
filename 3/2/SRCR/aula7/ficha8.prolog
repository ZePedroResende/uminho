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
:- op( 900,xfy,'::' ). % definição de um invariante
:- dynamic filho/2.
:- dynamic pai/2.
%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado nao: Questao -> {V,F}

nao( Questao ) :-
    Questao, !, fail.
nao( Questao ).

% Predicado comprimento:
% Lista, Comprimento -> {V,F}
comprimento([_H],1).
comprimento([_H|T],N) :- comprimento(T,M), N is M+1.

% Predicado solucoes:
% Termo, Predicado, Lista -> {V,F}
solucoes(T,Q,S) :- findall(T,Q,S).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado demo: Questao,Resposta -> {V,F}

demo( Questao,verdadeiro ) :-
    Questao.
demo( Questao,falso ) :-
    -Questao.
demo( Questao,desconhecido ) :-
    nao( Questao ),
    nao( -Questao ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SICStus PROLOG: definicoes iniciais

%--------------------------------------------------------

pai( P,F ) :- filho( F,P ).
excecao(pai(P,F)):- pai(rand,F)

avo(A,N) :- grau(A,N,2).

neto(N,A) :- avo(A,N).

descendente(D, A) :- filho(D,A).
descendente(D, A) :- filho(D,B), descendente(B,A).

ascendente(A , D) :- descendente(D,A).

grau(D,A,1) :- filho(D,A).
grau(D,A,G) :- filho(D,F), grau(F,A,N), G is N+1.

%--------------------------------------------------------
% Invariante Estrutural:  nao permitir a insercao de conhecimento
%                         repetido

+filho(F,P) :: (solucoes( (F,P),(filho( F,P )),S ),
                  comprimento( S,N ),
				  N==1).

+pai(P,F) :: (solucoes((P,F),(pai(P,F)),S),
             comprimento(S,N),
             N==1).

+avo(A,N) :: (solucoes((A,N),(avo(A,N)),S),
             comprimento(S,X),
             X==1).

+neto(N,A) :: (solucoes((N,A),(neto(N,A)),S),
            comprimento(S,X),
            X==1).

+descendente(D,A) :: (solucoes((D,A),(descendente(D,A)),S),
             comprimento(S,N),
             N==1).
% Invariante Referencial: nao admitir mais do que 2 progenitores
%                         para um mesmo individuo

+filho( F,P ) :: (solucoes( (F,NP),(filho( F,NP )),S ),
                  comprimento( S,N ),
				  N=<2).

+pai( P,F ) :: (solucoes( (F,NP),(filho( F,NP )),S ),
                comprimento( S,N ),
  				N=<2).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensão do predicado que permite a evolucao do conhecimento

evolucao(T) :- solucoes(Inv, +T::Inv, S),
               insercao(T),
               testa(S).

insercao(T) :- assert(T).
insercao(T) :- retract(T),!,fail.

% !,fail == insucesso na prova

testa([]).
testa([H|T]) :- H, testa(T).


%-----------------------------
%
%
%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado filho: Filho,Pai -> {V,F,D}

filho( ana,abel).
filho( ana,alice).
filho(anibel,antonio)
filho(anibel,alberta)
filho(berto,bras)
filho(berto,belem)
filho(berta,bras)
filho(berta,belem)
filho(crispim,catia)
pai(daniel,danilo)

excecao(pai(rand,danilo))
excecao(pai(celso,crispim))
excecao(pai(caio,crispim))

data(ana,01-01-2010)
data(anibel,02-01-2010)
data(berto,02-02-2010)
data(berta,02-02-2010)
data(catia,03-03-2010)
data(danilo,04-04-2010)
