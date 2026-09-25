class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        stack = []
        results = [0]*len(temperatures)
        
        for i in range(len(temperatures)):
            if (stack == []):
                stack.append((temperatures[i], i))

            if (temperatures[i]<=stack[-1][0]):
                stack.append((temperatures[i], i))
            elif (temperatures[i]>stack[-1][0]):
                while (len(stack)>0 and temperatures[i]>stack[-1][0]):
    
                    diff = i - stack[-1][1]
                    results[stack[-1][1]] = diff
                    stack.pop()
                stack.append((temperatures[i], i))

        return results
