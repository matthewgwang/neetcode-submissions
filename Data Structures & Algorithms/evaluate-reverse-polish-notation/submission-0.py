class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for i in tokens:
            
            if (i == '+' or i == '-' or i=='*' or i == '/'):
                right = stack.pop()
                left = stack.pop()
                if i == "+":
                    result = left + right
                elif i == "-":
                    result = left - right
                elif i == "*":
                    result = right * left
                elif i == "/":
                    result = int(left / right)

                stack.append(result)
            else:
                stack.append(int(i))

        return stack[0]