class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        fleets = 0
        results  = []
        for i in range(len(position)):
            stack.append([position[i], speed[i]])
        stack.sort()
        
        stack.reverse()

        for i in range(len(stack)):
            results.append((target-stack[i][0])/stack[i][1])

            if (len(results)>= 2 and results[-1]<= results[-2]):
                results.pop()

        return len(results)

        