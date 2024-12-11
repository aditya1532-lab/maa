# Function to perform quick sort on an array of floating point numbers
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        # Choose pivot (taking the last element in the list for simplicity)
        pivot = arr[-1]
        left = [x for x in arr[:-1] if x <= pivot]
        right = [x for x in arr[:-1] if x > pivot]
        # Recursively sort left and right subarrays
        return quick_sort(left) + [pivot] + quick_sort(right)

# Driver code
if __name__ == "__main__":
    # Array of first-year percentages of students
    percentages = [89.5, 72.3, 95.7, 85.4, 65.8, 78.9, 91.2, 88.0, 99.1, 76.4]

    print("Original Percentages:")
    print(percentages)

    # Sort the percentages using quick sort
    sorted_percentages = quick_sort(percentages)

    print("\nSorted Percentages in Ascending Order:")
    print(sorted_percentages)

    # Display the top 5 scores (last 5 elements in the sorted list)
    top_5_scores = sorted_percentages[-5:]
    print("\nTop 5 Scores:")
    for score in top_5_scores:
        print(score)