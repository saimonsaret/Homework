isCorrect :: [Char] -> Bool
helper :: ([Char], [Char]) -> Bool
isCorrect string = helper (string, "")
helper ("", "") = True
helper ("", _) = False
helper ('(':xs, stack) = helper (xs, '(':stack)
helper ('[':xs, stack) = helper (xs, '[':stack)
helper ('{':xs, stack) = helper (xs, '{':stack)
helper (')':xs, '(':stack) = helper (xs, stack)
helper (']':xs, '[':stack) = helper (xs, stack)
helper ('}':xs, '{':stack) = helper (xs, stack)
helper (_, _) = False