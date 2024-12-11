# Function to perform bubble sort on an array of floating point numbers
def bubble_sort(arr):
    n = len(arr)
    # Traverse through all elements in the array
    for i in range(n):
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Driver code
if __name__ == "__main__":
    # Array of first-year percentages of students
    percentages = [89.5, 72.3, 95.7, 85.4, 65.8, 78.9, 91.2, 88.0, 99.1, 76.4]

    print("Original Percentages:")
    print(percentages)

    # Sort the percentages using bubble sort
    bubble_sort(percentages)

    print("\nSorted Percentages in Ascending Order:")
    print(percentages)

    # Display the top 5 scores (last 5 elements in the sorted list)
    top_5_scores = percentages[-5:]
    print("\nTop 5 Scores:")
    for score in top_5_scores:
        print(score)