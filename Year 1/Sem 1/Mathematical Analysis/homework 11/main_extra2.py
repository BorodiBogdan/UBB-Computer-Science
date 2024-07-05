import numpy as np

# Define the objective function and its gradient
def custom_objective_function(variables: np.ndarray) -> float:
    return 100 * (variables[1] - variables[0]**2)**2 + (1 - variables[0])**2

def compute_gradient(variables: np.ndarray) -> np.ndarray:
    partial_x = -400 * variables[0] * (variables[1] - variables[0]**2) - 2 * (1 - variables[0])
    partial_y = 200 * (variables[1] - variables[0]**2)
    return np.array([partial_x, partial_y])

def compute_hessian(variables: np.ndarray) -> np.ndarray:
    d2f_dx2 = -400 * (variables[1] - 3 * variables[0]**2) + 2
    d2f_dxdy = -400 * variables[0]
    d2f_dydx = -400 * variables[0]
    d2f_dy2 = 200
    return np.array([[d2f_dx2, d2f_dxdy], [d2f_dydx, d2f_dy2]])

# Initialize starting point for Newton's method
initial_point_newton = np.array([-1.2, 1])

# Initialize counter for Newton's method
iteration_count_newton = 0

# Apply Newton's method
for _ in range(100):  # maximum 100 iterations
    gradient_newton = compute_gradient(initial_point_newton)
    hessian_newton = compute_hessian(initial_point_newton)
    new_point_newton = initial_point_newton - np.linalg.inv(hessian_newton).dot(gradient_newton)

    # Check for convergence
    if np.allclose(initial_point_newton, new_point_newton):
        break

    initial_point_newton = new_point_newton
    iteration_count_newton += 1

print(f"Newton's method converged to a minimum at {initial_point_newton} in {iteration_count_newton} steps.")

# Initialize starting point for gradient descent
initial_point_gd = np.array([0.76311487, -3.17503385])

# Set learning rate for gradient descent
learning_rate = 0.001

# Initialize counter for gradient descent
iteration_count_gd = 0

# Apply gradient descent
for _ in range(10000):  # maximum 10000 iterations
    gradient_gd = compute_gradient(initial_point_gd)
    new_point_gd = initial_point_gd - learning_rate * gradient_gd

    # Check for convergence
    if np.allclose(initial_point_gd, new_point_gd):
        break

    initial_point_gd = new_point_gd
    iteration_count_gd += 1

print(f"Gradient descent converged to a minimum at {initial_point_gd} in {iteration_count_gd} steps.")
