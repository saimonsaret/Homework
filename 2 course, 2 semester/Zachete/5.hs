data Product =
    Book {
        name :: String,
        author :: String,
        price :: Int
    } |
    Journal {
        name :: String,
        year :: String,
        editionNumber :: Int,
        price :: Int
    }

countPrice :: [Product] -> Int
countPrice (x:xs) = (price x) + countPrice xs