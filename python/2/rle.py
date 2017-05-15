import numpy as np
from scipy import misc
from matplotlib import pyplot as plt
import sys

def rle(line):
    iterator = iter(line)
    cur = next(iterator)
    count = 1
    for e in iterator:
        if e == cur:
            count += 1
        else:
            yield count, cur
            cur = e
            count = 1
    yield count, cur

mat = np.array(misc.imread(str(sys.argv[1])))

plt.imshow(mat)
plt.show()

with open(str(sys.argv[2]), 'w') as f:
    for line in mat.tolist():
        print(line, file=f)

with open(str(sys.argv[3]), 'w') as f:
    for line in mat.tolist():
        print(list(rle(line)), file=f)
