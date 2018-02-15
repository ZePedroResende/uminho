SELECT Equipa, Posicao, Nome
	FROM Cromo as C
    LEFT OUTER JOIN Jogador AS J
		ON C.Jogador = J.Nr
		WHERE Jogador IS NOT NULL 
        
SELECT Nome
	FROM Cromo as C
    LEFT OUTER JOIN Jogador AS J
		ON C.Jogador = J.NR 
        Where Jogador IS NOT NULL AND C.Adquirido= 'S'
        
SELECT Adquirido
	FROM Cromo