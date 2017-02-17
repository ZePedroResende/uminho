module Ficha1 where 
import Cp

length1 :: [a] -> Int 
length1 y = foldl (\ a _ -> a+1) 0 y  

reverse1 :: [a] -> [a]
reverse1 x = foldl (\ acc x ->x:acc)  [] x

catMaybes :: [Maybe a] -> [a]
catMaybes []  = []
catMaybes ((Nothing):t) = ( catMaybes t)
catMaybes ((Just a):t) = (a: catMaybes t )

ouncurry :: (a -> b -> c) -> (a,b)-> c
ouncurry f (a,b) = f a b

ocurry :: ((a , b) -> c) -> a->b-> c
ocurry f a b = f (a,b)

oflip :: (a->b->c)->b->a->c
oflip f a b = f b a

data LTree a = Leaf a | Fork (LTree a,LTree a) deriving Show 

flatten :: LTree a -> [a]
flatten (Leaf a) = [a] 
flatten (Fork(a,b)) = flatten a ++ flatten b

mirror :: LTree a -> LTree a
mirror (Leaf a) = Leaf a 
mirror (Fork(a,b)) =  Fork(mirror b , mirror a)

ofmap:: (b->a) -> LTree b -> LTree a
ofmap f (Leaf x) = Leaf (f x)
ofmap f (Fork(a,b)) =  Fork((ofmap f a) , (ofmap f b))


lengthF :: [a]-> Int
lengthF x = foldr(\x a -> a+1) 0 x

-- (1:(2:(3:(4:([])))))

{-fol :: (a -> b -> b) -> b -> [a] -> b
fol [] [] = []
fol [] (x : xs) = x (:) (fol [] xs)
-}


{-
concat :: [[a]] -> [a]
concat (++) [] [] = []
concat (++) [] (x:xs) = x ++ (concat (++) xs)
    -}

concatt :: [[a]] -> [a]
concatt []  = []
concatt (x:xs)= x ++ concatt xs 

f :: [Int] -> [Int]
f = foldr(\x a -> if x > 0 then x+1 : a else a) []
--f s = [a+1 | a <- s, a > 0]

m :: (a-> b) -> [a] -> [b]
m f [] = []
m f (h:t) = (f h) : m f t 


m1 :: (a-> b) -> [a] -> [b]
m1 f x = foldr  (\x a -> (f x) : a) [] x


m2 :: (a-> b) -> [a] -> [b]
m2 f x = map f x 

-- (d) concat e o inverso da singl logo vai executar a identidade 
