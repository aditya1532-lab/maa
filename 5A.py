# Function to perform selection sort on an array of floating point numbers
def selection_sort(arr):
    n = len(arr)
    # Traverse through all elements of the array
    for i in range(n):
        # Find the minimum element in unsorted part of the array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        # Swap the found minimum element with the element at index i
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Driver code
if __name__ == "__main__":
    # Array of first-year percentages of students
    percentages = [89.5, 72.3, 95.7, 85.4, 65.8, 78.9, 91.2, 88.0, 99.1, 76.4]

    print("Original Percentages:")
    print(percentages)

    # Sort the percentages using selection sort
    selection_sort(percentages)

    print("\nSorted Percentages in Ascending Order:")
    print(percentages)

    # Display the top 5 scores
    top_5_scores = percentages[-5:]
    print("\nTop 5 Scores:")
    for score in top_5_scores:
        print(score)