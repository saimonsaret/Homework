import Control.Monad.State

data Graph vertex edge = Graph [(Int, vertex)] [(Int, Int, edge)]

inf = maxBound :: Int

updateMinDist :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
updateMinDist minDist (newVertex, newDist) = map (\(vertex, curDist) -> if (newVertex == vertex) 
                                                                        then (vertex, newDist) 
                                                                        else (vertex, curDist)) minDist

findNearestHelper :: [(Int, Int)] -> (Int, Int) -> (Int, Int)
findNearestHelper [] curMin = curMin
findNearestHelper (cur:xs) curMin = if (snd cur < snd curMin)
                                    then findNearestHelper xs cur
                                    else findNearestHelper xs curMin
                                                                        
findNearest :: [(Int, Int)] -> (Int, Int)
findNearest (first:xs) = findNearestHelper xs first

dijkstra' :: [(Int, Int)] -> [(Int, Int, Int)] -> Int -> [(Int, Int)]
dijkstra' minDist edges curVertex = if (length minDist == 1)
                                    then minDist
                                    else case (lookup curVertex minDist) of
                                         Nothing -> error ("No vertex " ++ show(curVertex))
                                         Just dist -> let helper [] = return []
                                                          helper((first, second, len):xs) = if (first == curVertex)
                                                                                            then do
                                                                                            notVisited <- get
                                                                                            case (lookup second notVisited) of
                                                                                                Nothing -> helper xs
                                                                                                Just curMin -> if curMin < (dist + len)
                                                                                                               then helper xs
                                                                                                               else do
                                                                                                               put(updateMinDist notVisited (second, dist + len))
                                                                                                               helper xs
                                                                                            else helper xs
                                                      in let newMinDist = filter (\(x,y) -> x /= curVertex) (execState (helper edges) minDist) 
                                                         in let nextVertex = findNearest newMinDist 
                                                            in (findNearest minDist):(dijkstra' newMinDist edges (fst nextVertex))

dijkstra :: Graph vertex Int -> Int -> [(Int, Int)]
dijkstra (Graph vertexList edges) start = dijkstra' (map (\(x,y) -> if x == start then (x, 0) else (x, inf)) vertexList) edges start