import numpy as np
import time

with open("test_case.txt", "r") as input:
    test_case = input.readlines()

    i = 1
    for line in test_case:
        list = [float (x) for x in line.split()]
        start = time.time()
        list = np.sort(list)
        end = time.time()
        
        print(f"Sort (numpy) time_data {i}:", round((end - start)*1000), "\tms\n")
        i+=1
