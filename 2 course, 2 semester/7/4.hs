import Control.Monad.Cont

newMap :: (a -> b) -> [a] -> Cont r [b]
newMap func []  = return []
newMap func (x:xs) = do
                     ys <- newMap func xs
                     return ((func x):ys)

newFilter :: (a -> Bool) -> [a] -> Cont r [a]
newFilter func [] = return []
newFilter func (x:xs) = do
                        ys <- newFilter func xs
                        if (func x)
                        then return (x:ys)
                        else return ys