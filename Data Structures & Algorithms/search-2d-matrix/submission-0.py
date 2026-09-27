class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        flat_list = list(chain.from_iterable(matrix))
        
        left = 0
        right = len(flat_list)-1

        while (left<=right):
            mid = (left+right)//2

            if (flat_list[mid] == target):
                return True
            elif (flat_list[mid]< target):
                left = mid+1
            else:
                right = mid-1

        return False