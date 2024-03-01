import numpy as np
import time

all_time =[]

for i in range(1,11):
    file = f"F:\\tailieudaihoc\\dsa\\generate-test\\input{i}.inp"
    number_array = []
    with open(file,'r') as filex:
        for number in filex:
            number_array.append(float(number.strip()))
    start_time = time.time()
    np.sort(number_array)
    end_time = time.time()
    elapsed_time = (end_time - start_time) * 1000
    all_time.append(round(elapsed_time))
    print(f"input{i}: {elapsed_time:.0f} ms")

print("Average: ",sum(all_time)/10)