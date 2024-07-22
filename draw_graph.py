from matplotlib import pyplot as plt
import pandas as pd
import sys
import numpy as np

def main():
    args = sys.argv
    
    # デフォルト
    default_filename = 'output.csv'
    
    if len(args) < 2:
        filename1 = default_filename
    else:
        filename1 = args[1]
        
    filepath1 = f"./output/{filename1}"
    
    input_csv1 = pd.read_csv(filepath1)
    input_data1 = input_csv1[input_csv1.keys()[0]]
    n1 = len(input_csv1)
    y1 = []
    x1 = np.arange(0, n1, 1)
    _ = [y1.append(i) for i in input_data1]

    plt.plot(x1, y1, label=filename1)
    
    if len(args) > 2:
        filename2 = args[2]
        filepath2 = f"./output/{filename2}"
        
        input_csv2 = pd.read_csv(filepath2)
        input_data2 = input_csv2[input_csv2.keys()[0]]
        n2 = len(input_csv2)
        y2 = []
        x2 = np.arange(0, n2, 1)
        _ = [y2.append(i) for i in input_data2]
        
        plt.plot(x2, y2, 'r', label=filename2)
        
        output_filename = f'./output/{filename1[:-4]}-{filename2[:-4]}.png'
    else:
        output_filename = f'./output/{filename1[:-4]}.png'

    plt.legend()
    plt.xlim(left=0)
    plt.tight_layout()
    plt.savefig(output_filename)

if __name__ == '__main__':
    main()
