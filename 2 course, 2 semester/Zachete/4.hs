func :: [Double] -> Double
func list = helper list 0 1

helper :: [Double] -> Double -> Double -> Double
helper [] sumBuf multBuf = sumBuf / multBuf
helper (x:list) sumBuf multBuf = helper list (sumBuf + x) (multBuf * cos(x))