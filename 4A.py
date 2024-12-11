# Function to perform linear search
def linear_search(roll_numbers, target_roll_number):
    for roll_number in roll_numbers:
        if roll_number == target_roll_number:
            return True  # Student attended the training program
    return False  # Student did not attend the training program

# Driver code
if __name__ == "__main__":
    # Array of roll numbers of students who attended the training program (random order)
    roll_numbers = [101, 202, 303, 404, 505, 606, 707, 808, 909, 1001]

    # Input roll number to search
    target_roll_number = int(input("Enter the roll number to check if the student attended the training program: "))

    # Search using linear search
    if linear_search(roll_numbers, target_roll_number):
        print(f"Student with roll number {target_roll_number} attended the training program.")
    else:
        print(f"Student with roll number {target_roll_number} did not attend the training program.")