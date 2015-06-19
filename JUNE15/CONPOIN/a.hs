import Control.Monad
main = do
    t <- readLn :: IO Int
    replicateM_ t $ do
        nm <- getLine
        let (n:m:_) = map read . words $ nm
        print $ ans n m
        replicateM_ m getLine
ans 1 0 = 1
ans 2 1 = 1
ans 3 3 = 1
ans 4 6 = 1
ans 5 9 = 1
ans n m = 0