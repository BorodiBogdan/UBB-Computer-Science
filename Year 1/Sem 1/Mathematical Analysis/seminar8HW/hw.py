import numpy as np
import matplotlib.pyplot as plt
def generate_points_inside_unit_ball(num_points, p_norm):
    points_inside_ball = []

    for _ in range(num_points):
        # Generate random polar coordinates
        r = np.random.rand() ** (1 / p_norm)
        theta = np.random.uniform(0, 2 * np.pi)

        # Convert polar coordinates to Cartesian coordinates
        x = r * np.cos(theta)
        y = r * np.sin(theta)

        points_inside_ball.append([x, y])

    return np.array(points_inside_ball)


def plot_unit_ball(p_norm, points_inside_ball):
    # Plotting the unit ball
    theta = np.linspace(0, 2 * np.pi, 100)
    x = np.cos(theta)
    y = np.sin(theta)

    plt.plot(x, y, label=f'Unit Ball (p={p_norm})')

    # Plotting the points inside the unit ball
    plt.scatter(points_inside_ball[:, 0], points_inside_ball[:, 1], color='red', label='Points Inside Unit Ball')

    plt.title(f'Unit Ball for p-norm with p={p_norm}')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    plt.axis('equal')
    plt.show()


# Number of random points to generate
num_points = 1000

# List of p-norm values
p_norm_values = [1.25, 1.5, 3, 8]

# Generate and plot points for each p-norm
for p_norm in p_norm_values:
    points_inside_ball = generate_points_inside_unit_ball(num_points, p_norm)
    plot_unit_ball(p_norm, points_inside_ball)