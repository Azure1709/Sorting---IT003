import random 
import numpy as np

random.seed(1709)

with open("test_case.txt", "w") as output: 
    list = [random.randint(-100_000_000, 100_000_000) for i in range(1_000_000)]
    list = np.sort(list) 
    for number in list: 
        output.write(str(number) + ' ')
    output.write('\n')

    list = [random.randint(-100_000_000, 100_000_000) for i in range(1_000_000)]
    list = np.sort(list)
    list = list[::-1] #Giảm dần
    for number in list: 
        output.write(str(number) + ' ')
    output.write('\n')

    #Tạo 8 dãy ngẫu nhiên
    for i in range(8):
        for j in range(1_000_000):
            output.write(str(random.randint(-100_000_000, 100_000_000) / 100) + ' ') # Lấy số thực
        output.write('\n')