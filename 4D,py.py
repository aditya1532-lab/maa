# Function to perform Fibonacci search
def fibonacci_search(roll_numbers, target_roll_number):
    n = len(roll_numbers)
    # Initialize Fibonacci numbers
    fib_m_minus_2 = 0  # (m-2)'th Fibonacci number
    fib_m_minus_1 = 1  # (m-1)'th Fibonacci number
    fib_m = fib_m_minus_1 + fib_m_minus_2  # m'th Fibonacci number
    
    # Find the smallest Fibonacci number greater than or equal to n
    while fib_m < n:
        fib_m_minus_2 = fib_m_minus_1
        fib_m_minus_1 = fib_m
        fib_m = fib_m_minus_1 + fib_m_minus_2

    # Initializing the range
    offset = -1
    
    # Start searching using the Fibonacci search technique
    while fib_m > 1:
        i = min(offset + fib_m_minus_2, n - 1)
        
        # If target_roll_number is greater than the value at index i
        if roll_numbers[i] < target_roll_number:
            fib_m = fib_m_minus_1
            fib_m_minus_1 = fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
            offset = i
        # If target_roll_number is less than the value at index i
        elif roll_numbers[i] > target_roll_number:
            fib_m = fib_m_minus_2
            fib_m_minus_1 = fib_m_minus_1 - fib_m_minus_2
            fib_m_minus_2 = fib_m - fib_m_minus_1
        # Element found
        else:
            return True
    
    # Comparing the last element
    if fib_m_minus_1 and roll_numbers[offset + 1] == target_roll_number:
        return True

    return False

# Driver code
if __name__ == "__main__":
    # Array of roll numbers of students who attended the training program (sorted order)
    roll_numbers = [101, 202, 303, 404, 505, 606, 707, 808, 909, 1001]

    # Input roll number to search
    target_roll_number = int(input("Enter the roll number to check if the student attended the training program: "))

    # Search using Fibonacci search
    if fibonacci_search(roll_numbers, target_roll_number):
        print(f"Student with roll number {target_roll_number} attended the training program.")
    else:
        print(f"Student with roll number {target_roll_number} did not attend the training program.")