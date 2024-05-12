class Solution:
    def precedence(self, op: str) -> int:
        if op in {"+", "-"}:
            return 1
        if op == "*":
            return 2
        return 0

    def compute(self, op: str, a: int, b: int) -> int:
        if op == "+":
            return a + b
        elif op == "-":
            return a - b
        elif op == "*":
            return a * b
        return 0

    def solve(self, s: str) -> int:
        operand = []
        operator = []

        i = 0
        while i < len(s):
            if s[i] == " ":
                i += 1
                continue
            elif s[i].isdigit():
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                operand.append(num)
                i -= 1
            elif s[i] == "(":
                operator.append(s[i])
            elif s[i] == ")":
                while operator[-1] != "(":
                    op = operator[-1]
                    operator.pop()
                    b = operand[-1]
                    operand.pop()
                    a = operand[-1]
                    operand.pop()
                    operand.append(self.compute(op, a, b))
                operator.pop()
            else:
                while operator and self.precedence(operator[-1]) >= self.precedence(s[i]):
                    op = operator[-1]
                    operator.pop()
                    b = operand[-1]
                    operand.pop()
                    a = operand[-1]
                    operand.pop()
                    operand.append(self.compute(op, a, b))
                operator.append(s[i])
            i += 1

        while operator:
            op = operator[-1]
            operator.pop()
            b = operand[-1]
            operand.pop()
            a = operand[-1]
            operand.pop()
            operand.append(self.compute(op, a, b))

        return operand[-1]

s1="(2*(3-4))*5"
s2="3+2*3*4-1"
s=Solution()
print(s.solve(s1))
print(s.solve(s2))