import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # Needed for 3D plotting

# Load the CSV data into a DataFrame
df = pd.read_csv('../offline/simulation_results.csv')

# Extract the position data (PosX, PosY, PosZ)
x = df['PosX']
y = df['PosY']
z = df['PosZ']

# Create a 3D plot
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Plot the missile trajectory in 3D
ax.plot(x, y, z, label='Trajectory', color='b')

# Add labels and title
ax.set_xlabel('X Position (m)')
ax.set_ylabel('Y Position (m)')
ax.set_zlabel('Z Position (m)')
ax.set_title('Missile Trajectory')

# Optionally, add a grid and legend
ax.grid(True)
ax.legend()

# Show the plot
plt.show()

