import numpy as np

np.random.seed(2802)


for i in range(1,11):
    file = f"generate-test/input{i}.inp"
    random_number_array = np.random.uniform(0,1337,1000000)
    if i == 1:
        random_number_array.sort()
    if i == 2:
        random_number_array.sort()
        random_number_array = random_number_array[::-1]
    with open(file,'w') as filex:
        for j in random_number_array:
            filex.write(f"{j}\n")
