import matplotlib.pyplot as plt
import numpy as np


def first_function(x, y):
    return (x ** 2 + y ** 2) / 2


def gradient_function_1(x):
    return x


def gradient_function_2(y):
    return y


def optimal_learning_rate(x, y, b):
    if b ** 3 * y ** 2 + x ** 2:
        return (b ** 2 * y ** 2 + x ** 2) / (b ** 3 * y ** 2 + x ** 2)
    else:
        return 0.00000001


def gradient_descent_method(x, y, b, max_iter, tol):
    iterations = 0
    steps = [(x, y)]
    # learning_rate = 0.6

    for _ in range(max_iter):
        iterations += 1
        learning_rate = optimal_learning_rate(x, y, b)
        diff_of_x = learning_rate * gradient_function_1(x)
        diff_of_y = learning_rate * gradient_function_2(y)
        if np.abs(diff_of_x) < tol or np.abs(diff_of_y) < tol:
            break

        x = x - diff_of_x
        y = y - diff_of_y
        steps.append((x, y))

    return steps, first_function(x, y), iterations


def main():
    b = 1
    x = np.linspace(-5, 5, 100)
    y = np.linspace(-5, 5, 100)
    X, Y = np.meshgrid(x, y)
    Z = first_function(X, Y)

    ax = plt.axes(projection='3d')

    path, desired_result, nr_of_occurences = gradient_descent_method(3, 3 * b, 3, 1000, 0.00000001)
    steps_of_x = [p[0] for p in path]
    steps_of_y = [p[1] for p in path]
    steps_of_z = [first_function(x, y) for x, y in path]

    ax.plot_surface(X, Y, Z, rstride=1, cstride=1, alpha=0.5, cmap='viridis', edgecolor='none')
    ax.plot3D(steps_of_x, steps_of_y, steps_of_z, 'red', label='Gradient Descent Path')

    text = (f"Learning rate: optimal\n"
            f"Min. local value: {first_function(3, 3):.3f}\n"
            f"No. of iterations: {nr_of_occurences}")

    props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)

    fig = plt.gcf()
    fig.text(0.01, 0.01, text, fontsize=10.5, verticalalignment='bottom',
             horizontalalignment='left', bbox=props)

    plt.show()


main()