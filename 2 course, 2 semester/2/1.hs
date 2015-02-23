rev :: [a] -> [a]
rev list = if length list == 1
        then list
		else last list : rev(init list)