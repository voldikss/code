import math


def main():
    expr = input()
    stack = []
    stack2 = []
    for elem in expr.split():
        if elem[0] == "(":
            stack.append(elem[1:])
        elif elem[-1] == ")":
            num = elem.strip(")")
            stack.append(num)
            for _ in range(len(elem) - len(num)):
                stack.append(")")
        else:
            stack.append(elem)
    # print(stack)

    while len(stack) > 0:
        pop = stack.pop()
        if pop[-1] != ")" and len(stack2) > 0 and stack2[-1] != ")":
            num1 = int(pop)
            num2 = int(stack2.pop())
            op = stack.pop()
            if op == "add":
                res = num1 + num2
            elif op == "mul":
                res = num1 * num2
            elif op == "sub":
                res = num1 - num2
            else:  # div
                if num2 == 0:
                    print("error")
                    return
                res = math.floor(num1 / num2)
            stack.append(str(res))
            stack2.pop()
            # print(f"stack: {stack}", end='  ')
            # print(f"stack2: {stack2}")
            continue

        stack2.append(pop)
        # print(f"stack: {stack}", end='  ')
        # print(f"stack2: {stack2}")

        ...

    print(stack2[0])


if __name__ == "__main__":
    main()
