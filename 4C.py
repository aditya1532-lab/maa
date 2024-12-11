# Function to perform binary search
def binary_search(roll_numbers, target_roll_number):
    low = 0
    high = len(roll_numbers) - 1
    
    while low <= high:
        mid = (low + high) // 2  # Find the middle index
        if roll_numbers[mid] == target_roll_number:
            return True  # Found the student
        elif roll_numbers[mid] < target_roll_number:
            low = mid + 1  # Target is in the right half
        else:
            high = mid - 1  # Target is in the left half
    
    return False  # Student not found

# Driver code
if __name__ == "__main__":
    # Array of roll numbers of students who attended the training program (sorted order)
    roll_numbers = [101, 202, 303, 404, 505, 606, 707, 808, 909, 1001]

    # Input roll number to search
    target_roll_number = int(input("Enter the roll number to check if the student attended the training program: "))

    # Search using binary search
    if binary_search(roll_numbers, target_roll_number):
        print(f"Student with roll number {target_roll_number} attended the training program.")
    else:
        print(f"Student with roll number {target_roll_number} did not attend the training program.")