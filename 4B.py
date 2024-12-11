# Function to perform sentinel search
def sentinel_search(roll_numbers, target_roll_number):
    # Store the last element as the sentinel value
    last = roll_numbers[-1]
    # Set the sentinel at the end of the list
    roll_numbers[-1] = target_roll_number
    
    i = 0
    # Search through the list until the target is found or the sentinel is reached
    while roll_numbers[i] != target_roll_number:
        i += 1
    
    # Restore the original value of the last element
    roll_numbers[-1] = last
    
    # Check if the target was found
    if i < len(roll_numbers) - 1 or roll_numbers[-1] == target_roll_number:
        return True  # Found the student
    else:
        return False  # Student not found

# Driver code
if __name__ == "__main__":
    # Array of roll numbers of students who attended the training program (random order)
    roll_numbers = [101, 202, 303, 404, 505, 606, 707, 808, 909, 1001]

    # Input roll number to search
    target_roll_number = int(input("Enter the roll number to check if the student attended the training program: "))

    # Search using sentinel search
    if sentinel_search(roll_numbers, target_roll_number):
        print(f"Student with roll number {target_roll_number} attended the training program.")
    else:
        print(f"Student with roll number {target_roll_number} did not attend the training program.")