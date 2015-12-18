import Prelude hiding (head, tail, singleton, concat, reverse, List)
 
data List a = Nil | Cons a (List a)
           deriving Show
 
head Nil = error "empty List"
head (Cons x xs) = x
 
tail Nil = error "empty List"
tail (Cons x xs) = xs
 
singleton x = Cons x Nil
 
concat Nil ys = ys
concat xs Nil = xs
concat xxs@(Cons x xs) yys@(Cons y ys) = Cons x (concat xs yys)
 
reverse Nil = Nil
reverse (Cons x xs) = reverse xs `concat` (singleton x)
 
t1 = (Cons 1 (Cons 2 (Cons 3 Nil)))
t2 = (Cons 4 (Cons 5 (Cons 6 (Cons 7 Nil))))
 
main = do
  let t3 = t1 `concat` t2
  print t3
  print (reverse t3)
