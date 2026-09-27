class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        low = 0
        high = max(piles)

        def test(piles: List[int], k:int) -> bool:
            count = 0
            if (k == 0):
                return False
            for i in range(len(piles)):
                if (piles[i] % k != 0):
                    count = count + (piles[i]//k +1)
                else:
                    count += (piles[i]/k)
            if count >h:
                return False
            else:
                return True


        while (low<= high):
            mid = (low+high)//2
        
            if (test(piles, mid) == True and test(piles, mid-1) == False):
                return mid
            if (test(piles, mid) == True and test(piles, mid-1) == True):
                high = mid-1
            else:
                low = mid+1

        
                
            