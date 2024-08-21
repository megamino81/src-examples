import random

def generate_number():
    """
    Generates a three-digit number where each digit is unique.
    """
    numbers = []
    while len(numbers) < 3:
        new_number = random.randint(0, 9)
        if new_number not in numbers:
            numbers.append(new_number)
    return "".join(map(str, numbers))

def check_number(generated, guess):
    """
    Check the guess against the generated number and returns the result as a string.
    """
    # Convert the numbers to strings for easier comparison
    generated = str(generated)
    guess = str(guess)

    # Initialize the result
    result = ""

    # Check for strikes
    for i in range(3):
        if generated[i] == guess[i]:
            result += "strike "
        else:
            # Check for balls
            for j in range(3):
                if generated[i] == guess[j] and i != j:
                    result += "ball "
                    break
            else:
                # If no ball is found, add an out
                result += "out "

    return result.strip()

def play_game():
    """
    Play a game of number baseball.
    """
    # Generate the number to guess
    generated = generate_number()

    # Initialize the number of turns
    turns = 0

    # Start the game loop
    while True:
        # Get the user's guess
        guess = input("Enter your guess: ")

        # Check the guess and get the result
        result = check_number(generated, guess)

        # Print the result
        print(result)

        # Check for a win
        if "strike strike strike" == result:
            print("You won in {} turns!".format(turns))
            break

        # Increment the number of turns
        turns += 1

# Start the game
play_game()

