checkList :: [a] -> (a -> Bool) -> Bool
checkList [] condition = True
checkList (x:list) condition = if (condition x)
                               then checkList list condition
                               else False