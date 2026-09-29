class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #
        front_prod = [0]*len(nums)
        back_prod = [0]*len(nums)

        front_prod[0] = 1
        back_prod[-1] = 1

        for i in range(1, len(nums)):
            front_prod[i] = nums[i-1]*front_prod[i-1]
            back_prod[len(nums)-i-1] = nums[len(nums)-i]*back_prod[len(nums)-i]
        
        
        results = [0]*len(nums)
        for i in range(len(nums)):
            results[i] = front_prod[i] * back_prod[i]

        return results
        