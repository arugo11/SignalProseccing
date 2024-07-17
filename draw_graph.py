from matplotlib import pyplot as plt
import pandas as pd
import sys
import numpy as np
import csv

def main():
    args = sys.argv
    filename = args[1]  

    filepath = f"./input/{filename}"
    input_csv = pd.read_csv(filepath)
    input_data = input_csv[input_csv.keys()[0]]
    n = len(input_csv)
    y = []
    x = np.arange(0, n, 1)  
    _ = [y.append(i) for i in input_data]   

    plt.plot(x, y)
    plt.savefig(f'./output/{filename[:-4]}.png') 




if __name__ == '__main__':
    main()