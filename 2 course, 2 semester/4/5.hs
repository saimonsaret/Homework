addToList :: [String] -> String -> [String]
addToList [] val = [val]
addToList (x:list) val = if (val <= x)
                         then val:x:list
                         else x:(addToList list val)
                         
removeFromList :: [String] -> String -> [String]
removeFromList [] val = []
removeFromList (x:list) val = if (val == x)
                              then list
                              else x:(removeFromList list val)

printList :: [String] -> IO()
printList [] = do
               putStrLn("")
               return ()
printList (x:list) = do 
                     putStr(x)
                     putStr(" ")
                     printList list
                     
printHelp :: IO()
printHelp = do
            putStrLn("Type:")
            putStrLn("1: to add value")
            putStrLn("2: to remove value")
            putStrLn("3: to print list")
            putStrLn("4: to see help")

exec :: [String] -> IO()
exec list = do
    putStrLn("Enter your command:")
    command <- getLine
    case command of
         "0" -> return ()
         "1" -> do
                putStrLn("Type value you want to add:")         
                val <- getLine
                list <- return (addToList list val)
                exec list
         "2" -> do
                putStrLn("Type value you want to remove:")
                val <- getLine
                list <- return (removeFromList list val)
                exec list
         "3" -> do
                putStrLn("Your list:")
                printList list
                exec list
         "4" -> do
                printHelp
                exec list

main = do
    printHelp
    list <- return []
    exec list