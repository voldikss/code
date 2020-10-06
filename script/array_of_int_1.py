import random

for i in range(10):
    length = random.randint(1,10)
    print("[", end='')
    for i in range(length):
        print(random.randint(0, 10), end='')
        if i != length - 1:
            print(',', end='')
    print(']')
