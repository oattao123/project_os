# Importing the required modules
import pandas as pd
import numpy as np

# Creating the NumPy array
array = np.array([[1, 1, 1], [2, 4, 8], [3, 9, 27], [4, 16, 64], [5, 25, 125], [6, 36, 216], [7, 49, 343]])

# Creating lists for index names and column names
index_values = ['first', 'second', 'third', 'fourth', 'fifth', 'sixth', 'seventh']
column_values = ['number', 'squares', 'cubes']

# Creating and displaying the DataFrame
df = pd.DataFrame(data=array, index=index_values, columns=column_values)

# Print the DataFrame
print(df)
