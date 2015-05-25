data Expression = X | Const Int | Expression :+: Expression | Expression :-: Expression | Expression :*: Expression | Expression :^: Int 
                  deriving (Eq, Show)

derivative :: Expression -> Expression
derivative expr = simplify(derHelper (simplify expr))

derHelper :: Expression -> Expression
derHelper (Const n) = Const 0
derHelper X = Const 1
derHelper (expr1 :+: expr2) = (derHelper expr1) :+: (derHelper expr2)
derHelper (expr1 :-: expr2) = (derHelper expr1) :-: (derHelper expr2)
derHelper (expr1 :*: expr2) = ((derHelper expr1) :*: expr2) :+: (expr1 :*: (derHelper expr2))
derHelper (expr :^: n)   = ((Const n) :*: (expr :^: (n - 1))) :*: (derHelper expr)

simplify :: Expression -> Expression
simplify (Const n) = Const n
simplify X = X
simplify (expr1 :+: expr2) = simpHelper (simplify expr1 :+: simplify expr2)
simplify (expr1 :-: expr2) = simpHelper (simplify expr1 :-: simplify expr2)
simplify (expr1 :*: expr2) = simpHelper (simplify expr1 :*: simplify expr2)
simplify (expr1 :^: n) = simpHelper (simplify expr1 :^: n)
    
simpHelper :: Expression -> Expression
simpHelper (Const 0 :+: x) = x
simpHelper (Const 0 :*: x) = Const 0
simpHelper (Const 0 :^: x) = Const 0
simpHelper (Const 1 :*: x) = x
simpHelper (x :+: Const 0) = x
simpHelper (x :*: Const 0) = Const 0
simpHelper (x :^: 0) = Const 1
simpHelper (x :*: Const 1) = x
simpHelper (x :^: 1) = x
simpHelper (Const n1 :+: Const n2) = Const (n1 + n2)
simpHelper (Const n1 :-: Const n2) = Const (n1 - n2)
simpHelper (Const n1 :*: Const n2) = Const (n1 * n2)
simpHelper (Const n1 :^: n2) = Const (n1 ^ n2)
simpHelper expr = expr