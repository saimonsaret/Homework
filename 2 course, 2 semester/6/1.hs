import Control.Monad.State

data Tree = Empty | Node Char Tree Tree

treeToString :: Tree -> String
treeToString Empty = "e"
treeToString (Node x left right) = 'n' : x : (treeToString left ++ treeToString right)

stringToTree :: String -> Tree
stringToTree str = let temp = do
                        state <- get
                        case state of
                            ('e':xs) -> do
                                put xs
                                return Empty
                            ('n':x:xs) -> do
                                put xs
                                left <- temp
                                right <- temp
                                return (Node x left right)
                            _ -> error "Incorrect input"
                   in evalState temp str