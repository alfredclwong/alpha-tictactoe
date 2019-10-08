from subprocess import Popen, PIPE
import numpy as np
#import keras

n = 10000
print(f"Running {n} games")
p = Popen(['./a.out'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
data, _ = p.communicate(input=str.encode("1000"))
games = np.array((n, 9, 4, 9), dtype=bool)
results = np.array((n, 1), dtype=int)
print(data)
