import numpy as np
from scipy import misc
import matplotlib.pyplot as plt


def compress(array):
    count = 1
    char = ''
    prev = ''
    res = []
    for elem in array:
        char = elem
        if elem != prev:
            if prev:
                entry = (prev, count)
                res.append(entry)
            count = 1
            prev = elem
        else:
            count += 1
    entry = (char, count)
    res.append(entry)

    return res


def decompress(array):
    res = []
    for elem in array:
        for color in range(elem[1]):
            res.append(elem[0])

    return res


img = misc.imread("../../1.bmp")

matrix = np.array(img)
compressed = list()
res_matrix = list()

with open("0_shakalov_iz_10.txt", "w") as file:
    for array in matrix.tolist():
        print(array, file=file)

with open("5_shakalov_iz_10.txt", "w") as file:
    for array in matrix.tolist():
        print(compress(array), file=file)
        # print(compress(array))
        compressed.append(compress(array))
