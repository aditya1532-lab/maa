
# Function to add two matrices
def matrix_addition(A, B):
    return np.add(A, B)

# Function to subtract two matrices
def matrix_subtraction(A, B):
    return np.subtract(A, B)

# Function to multiply two matrices
def matrix_multiplication(A, B):
    return np.dot(A, B)

# Function to compute transpose of a matrix
def matrix_transpose(A):
    return np.transpose(A)

# Driver code
if __name__ == "__main__":
    # Define two matrices
    A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    B = np.array([[9, 8, 7], [6, 5, 4], [3, 2, 1]])
    
    print("Matrix A:")
    print(A)
    
    print("Matrix B:")
    print(B)
    
    # Addition
    print("\nMatrix Addition (A + B):")
    print(matrix_addition(A, B))
    
    # Subtraction
    print("\nMatrix Subtraction (A - B):")
    print(matrix_subtraction(A, B))
    
    # Multiplication
    print("\nMatrix Multiplication (A * B):")
    print(matrix_multiplication(A, B))
    
    # Transpose of Matrix A
    print("\nTranspose of Matrix A:")
    print(matrix_transpose(A))
    
    # Transpose of Matrix B
    print("\nTranspose of Matrix B:")
    print(matrix_transpose(B))