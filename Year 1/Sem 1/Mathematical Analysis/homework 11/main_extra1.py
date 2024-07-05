import numpy as np
from typing import Callable, Tuple, List

# Define a quadratic function and its gradient
def quadratic_function(x: np.ndarray) -> float:
    return x[0]**2 + 3*x[1]**2

def gradient_quadratic(x: np.ndarray) -> np.ndarray:
    df_dx = 2*x[0]
    df_dy = 6*x[1]
    return np.array([df_dx, df_dy])

def hessian_quadratic(x: np.ndarray) -> np.ndarray:
    return np.array([[2, 0], [0, 6]])

def newton_optimization(x: np.ndarray, objective_func: Callable, gradient_func: Callable, hessian_func: Callable, lr=0.01, lr_decr=0.999, max_iter=100, tolerance=0.001) -> Tuple[np.ndarray, List[np.ndarray], int]:
    trajectory = [x]
    iterations = 0
    for _ in range(max_iter):
        gradient = gradient_func(x)
        hessian = hessian_func(x)
        x_new = x - np.linalg.inv(hessian).dot(gradient)

        if np.linalg.norm(x_new - x) < tolerance:
            break

        x = x_new
        iterations += 1
        trajectory.append(x)

    return x, trajectory, iterations

# Initialize starting point
initial_point = np.array([-1.2, 1])

# Apply Newton's method
minimum_point, trajectory_points, num_iterations = newton_optimization(initial_point, quadratic_function, gradient_quadratic, hessian_quadratic)

print(f"The minimum point found by the optimization is {minimum_point} after {num_iterations} iterations.")