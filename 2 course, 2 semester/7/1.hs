import System.Directory

findNumber :: [(String, String)] -> String -> Maybe String
findNumber [] _ = Nothing
findNumber (x:xs) name = if (fst x == name)
                         then Just (snd x)
                         else findNumber xs name
                   
findName :: [(String, String)] -> String -> Maybe String
findName [] _ = Nothing
findName (x:xs) number = if (snd x == number)
                         then Just (fst x)
                         else findName xs number
                         
dataToString :: [(String, String)] -> String
dataToString [] = ""
dataToString (x:xs) = (fst x) ++ "\n" ++ (snd x) ++ "\n" ++ dataToString(xs)

linesToData :: [String] -> Maybe [(String, String)]
linesToData [] = Just []
linesToData (name:(number:xs)) = let list = linesToData xs
                                 in case list of 
                                    Just ys -> Just ((name, number):ys)
                                    Nothing -> Nothing
linesToData _ = Nothing

printHelp :: IO()
printHelp = do
            putStrLn("Type:")
            putStrLn("1: to add record")
            putStrLn("2: to find number using name")
            putStrLn("3: to find name using number")
            putStrLn("4: to save data in file")
            putStrLn("5: to load data from file")
            putStrLn("6: to see help")

exec :: [(String, String)] -> IO()
exec list = do
    putStrLn("Enter your command:")
    command <- getLine
    case command of
         "0" -> return ()
         "1" -> do
                putStrLn("Type name:")         
                name <- getLine
                putStrLn("Type number:") 
                number <- getLine
                list <- return ((name, number):list)
                exec list
         "2" -> do
                putStrLn("Type name:")
                name <- getLine
                number <- return (findNumber list name)
                case number of
                    Just a -> putStrLn("Number is: " ++ a)
                    Nothing -> error "No record found!"
                exec list
         "3" -> do
                putStrLn("Type number:")
                number <- getLine
                name <- return (findName list number)
                case name of
                    Just a -> putStrLn("Name is: " ++ a)
                    Nothing -> error "No record found!"
                exec list
         "4" -> do
                putStrLn("Type output filename:")
                filename <- getLine
                writeFile filename (dataToString list)
                exec list
         "5" -> do
                putStrLn("Type input filename:")
                filename <- getLine
                exists <- doesFileExist filename
                if exists then do
                    input <- readFile filename
                    tempList <- return (linesToData(lines input))
                    case tempList of
                         Just a -> do 
                                  exec a
                                  return ()
                         Nothing -> do
                                    error "Wrong input format!"
                                    exec list
                else do
                     error "No such file!"
                     exec list
         "6" -> do
                printHelp
                exec list

main = do
    printHelp
    list <- return []
    exec list