import System.Random
import Control.Monad.State

data Tree = Leaf Int | Node Tree Int Tree deriving (Show)

helper (Leaf x) = do
            generator <- get
            let (randVal, newGen) = random generator
            put newGen
            return (Leaf randVal)
helper (Node leftBranch x rightBranch) = do
                                   generator <- get
                                   let (randVal, newGen) = random generator
                                   put newGen
                                   randomizedLeftBranch <- helper leftBranch
                                   randomizedRightBranch <- helper rightBranch
                                   return (Node randomizedLeftBranch randVal randomizedRightBranch)

randomizeTree :: Tree -> Int -> Tree
randomizeTree inputTree seed = evalState (helper inputTree) (mkStdGen seed)