import matplotlib.pyplot as plt
import numpy as np


def plot_data(results_loops, results_sorting):
    fig, (ax1, ax2) = plt.subplots(1, 2)
    ax1.plot(results_loops[:, 0], results_loops[:, 1], label='Simple')
    ax1.plot(results_loops[:, 0], results_loops[:, 2], label='Summing up')
    ax1.set_xlabel('Number of Iterations')
    ax1.set_ylabel('Execution Time [seconds]')
    ax1.set_title("Computation Time")
    ax1.legend()
    ax2.plot(results_sorting[0:5, 0], results_sorting[0:5, 1], label='Bubble Sort')
    ax2.plot(results_sorting[:, 0], results_sorting[:, 2], label='Quick Sort')
    ax2.set_xlabel('Number of Values to Sort')
    ax2.set_ylabel('Execution Time [seconds]')
    ax2.set_title("Computation Time")
    ax2.legend()
    plt.show()

if __name__ == '__main__':
    results_loops = np.genfromtxt("./Timing.csv", delimiter=",", skip_header=1)
    results_sorting = np.genfromtxt("./Sorts.csv", delimiter=",", skip_header=1)
    plot_data(results_loops, results_sorting)
