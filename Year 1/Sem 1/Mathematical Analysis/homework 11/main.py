import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the quadratic function
def quadratic_function(matrix_A, vector_x):
    return 0.5 * vector_x.T @ matrix_A @ vector_x

# Create a grid of points
x_vals = np.linspace(-10, 10, 100)
y_vals = np.linspace(-10, 10, 100)
X_vals, Y_vals = np.meshgrid(x_vals, y_vals)

# Define the matrices matrix_A
A_min = np.array([[2, 0], [0, 2]])
A_max = np.array([[-2, 0], [0, -2]])
A_saddle = np.array([[2, 0], [0, -2]])

# Compute the function values
Z_min = np.array([quadratic_function(A_min, np.array([x, y])) for x, y in zip(np.ravel(X_vals), np.ravel(Y_vals))]).reshape(X_vals.shape)
Z_max = np.array([quadratic_function(A_max, np.array([x, y])) for x, y in zip(np.ravel(X_vals), np.ravel(Y_vals))]).reshape(X_vals.shape)
Z_saddle = np.array([quadratic_function(A_saddle, np.array([x, y])) for x, y in zip(np.ravel(X_vals), np.ravel(Y_vals))]).reshape(X_vals.shape)

# Compute the gradients
grad_min = np.gradient(Z_min)
grad_max = np.gradient(Z_max)
grad_saddle = np.gradient(Z_saddle)

# Create the figure
fig = plt.figure(figsize=(18, 12))

# Plot the 3D surfaces
ax1 = fig.add_subplot(231, projection='3d')
ax1.plot_surface(X_vals, Y_vals, Z_min, cmap='plasma')  # Changed colormap to 'plasma'
ax1.set_title('Unique Minimum')

ax2 = fig.add_subplot(232, projection='3d')
ax2.plot_surface(X_vals, Y_vals, Z_max, cmap='plasma')  # Changed colormap to 'plasma'
ax2.set_title('Unique Maximum')

ax3 = fig.add_subplot(233, projection='3d')
ax3.plot_surface(X_vals, Y_vals, Z_saddle, cmap='plasma')  # Changed colormap to 'plasma'
ax3.set_title('Unique Saddle Point')

# Plot the contour lines and gradients
ax4 = fig.add_subplot(234)
ax4.contour(X_vals, Y_vals, Z_min, cmap='plasma')  # Changed colormap to 'plasma'
ax4.quiver(X_vals[::5, ::5], Y_vals[::5, ::5], grad_min[1][::5, ::5], grad_min[0][::5, ::5])
ax4.set_title('Contour and Gradient - Unique Minimum')

ax5 = fig.add_subplot(235)
ax5.contour(X_vals, Y_vals, Z_max, cmap='plasma')  # Changed colormap to 'plasma'
ax5.quiver(X_vals[::5, ::5], Y_vals[::5, ::5], grad_max[1][::5, ::5], grad_max[0][::5, ::5])
ax5.set_title('Contour and Gradient - Unique Maximum')

ax6 = fig.add_subplot(236)
ax6.contour(X_vals, Y_vals, Z_saddle, cmap='plasma')  # Changed colormap to 'plasma'
ax6.quiver(X_vals[::5, ::5], Y_vals[::5, ::5], grad_saddle[1][::5, ::5], grad_saddle[0][::5, ::5])
ax6.set_title('Contour and Gradient - Unique Saddle Point')

# Add text to the plot
plt.text(1, 0, 'Borodi Bogdan - Group: 912', horizontalalignment='left', verticalalignment='top', transform=plt.gcf().transFigure)

plt.show()