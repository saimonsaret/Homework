import Data.Char
import Control.Monad.State

data HashTable key val = HashTable {hash :: (key -> Int), table :: [(Int, val)]}

addHelper :: [(Int, val)] -> (Int, val) -> [(Int, val)]
addHelper [] record = [record] 
addHelper ((key, val):xs) record = if (fst record < key)
                                  then record : ((key, val):xs)
                                  else if (fst record > key)
                                       then (key, val) : (addHelper xs record)
                                       else record : xs


addValue :: HashTable key val -> key -> val -> HashTable key val
addValue (HashTable hashFunc table) key val = HashTable hashFunc (addHelper table (hashFunc key, val))

addValueState key val = do
                        newHashTable <- get
                        put(addValue newHashTable key val)
                                              
removeHelper :: [(Int, val)] -> (Int, val) -> [(Int, val)]
removeHelper [] _ = []
removeHelper ((key, val):xs) record = if (fst record < key)
                                      then (key, val) : (xs)
                                      else if (fst record > key)
                                           then (key, val) : (removeHelper xs record)
                                           else xs
                                            
                                              
remove :: HashTable key val -> key -> val -> HashTable key val
remove (HashTable hashFunc table) key val  = HashTable hashFunc (removeHelper table (hashFunc key, val))
         
removeValueState key val = do
                           newHashTable <- get
                           put(remove newHashTable key val)

findHelper :: [(Int, val)] -> Int -> Maybe val
findHelper [] _ = Nothing
findHelper ((key, val):xs) hashVal = if (hashVal < key)
                                     then Nothing
                                     else if (hashVal > key)
                                          then (findHelper xs hashVal)
                                          else Just val
                           
find :: HashTable key val -> key -> Maybe val
find (HashTable hashFunc table) key = findHelper table (hashFunc key)