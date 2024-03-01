import numpy as np

np.random.seed(1337)


for i in range(1,11):
    file = f"input{i}.inp"
    random_number_array = np.random.rand(1000000)
    with open(file,'w') as filex:
        for j in random_number_array:
            filex.write(f"{j}\n")
