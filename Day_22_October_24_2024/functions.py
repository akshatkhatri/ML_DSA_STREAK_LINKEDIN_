# Regular functions for arithmetic operations
def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    return a / b if b != 0 else None  # Handle division by zero

# Function to calculate square and cube of a number
def square(num):
    return num ** 2

def cube(num):
    return num ** 3

# Function to check if a number is prime
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

# Lambda functions for single-line calculations
power_four = lambda x: x ** 4
is_even = lambda x: x % 2 == 0
is_odd = lambda x: x % 2 != 0

# Nested function to apply different operations
def apply_operation(numbers, operation):
    return list(map(operation, numbers))

# Data
numbers = list(range(1, 11))
pairs = [(10, 5), (20, 4), (30, 0), (40, 8)]
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# Using map for various operations on numbers
squared_numbers = apply_operation(numbers, square)  # Using square function
cubed_numbers = apply_operation(numbers, cube)      # Using cube function
power_four_numbers = apply_operation(numbers, power_four)  # Lambda for x^4

# Using map with lambda for more flexibility
added_pairs = list(map(lambda pair: add(pair[0], pair[1]), pairs))
subtracted_pairs = list(map(lambda pair: subtract(pair[0], pair[1]), pairs))
multiplied_pairs = list(map(lambda pair: multiply(pair[0], pair[1]), pairs))
divided_pairs = list(map(lambda pair: divide(pair[0], pair[1]), pairs))

# Using filter to filter out prime, even, and odd numbers
prime_numbers = list(filter(is_prime, numbers))
even_numbers = list(filter(is_even, numbers))
odd_numbers = list(filter(is_odd, numbers))

# Flattening a 2D matrix using map and lambda
flattened_matrix = list(map(lambda row: [x for x in row], matrix))
flattened_list = [item for sublist in flattened_matrix for item in sublist]

# Advanced filter: Filter numbers greater than a threshold after squaring them
threshold = 20
filtered_squares = list(filter(lambda x: x > threshold, map(square, numbers)))

# Combined map and filter for strings (finding palindromic strings)
words = ["racecar", "hello", "madam", "world", "level"]
palindromic_words = list(filter(lambda word: word == word[::-1], words))

# Output results for different operations
print("Original numbers:", numbers)
print("Squared numbers:", squared_numbers)
print("Cubed numbers:", cubed_numbers)
print("Power-four numbers:", power_four_numbers)
print("\nPairs for arithmetic operations:", pairs)
print("Sum of pairs:", added_pairs)
print("Difference of pairs:", subtracted_pairs)
print("Product of pairs:", multiplied_pairs)
print("Division of pairs:", divided_pairs)
print("\nPrime numbers:", prime_numbers)
print("Even numbers:", even_numbers)
print("Odd numbers:", odd_numbers)
print("\nOriginal matrix:", matrix)
print("Flattened matrix:", flattened_list)
print(f"Numbers with squares > {threshold}:", filtered_squares)
print("Palindromic words:", palindromic_words)
