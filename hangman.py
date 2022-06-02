
def turn0():
    print("   ( )\n o--|--o \n   / \\" )

def turn1():
    print("   ( )\n    |--o \n   / \\" )

def turn2():
    print("   ( )\n    | \n   / \\" )

def turn3():
    print("   ( )\n    | \n   / " )

def turn4():
    print("   ( )\n    |" )

def turn5():
    print("   ( )")



def checkLetter(letter): 
    global guesses
    global solved
    global guessed_letters
    gotone = False
    new_solved = ""
    for i in range(0, len(word)):
        if (word[i] == letter):
            new_solved += letter
            guessed_letters += 1
            gotone = True
        else: 
            new_solved += solved[i]
    solved = new_solved
    if gotone: 
        print("You got a letter! Keep it up to keep your man alive.")
        to_print = ""
        for i in range(0,len(solved)): 
            to_print += solved[i] + " "
        print(to_print)
    else:
        print("Big mistake! He will pay for your ignorance.")
        to_print = ""
        for i in range(0,len(solved)): 
            to_print += solved[i] + " "
        print(to_print)
        guesses -= 1
        


play = "Y"
while play == "Y":
    print("Hello, welcome to the game of hangman, please enter a word for a friend to guess")

    valid = False
    while not valid:
        word = input("Enter a word for your friend to guess: ")
        for i in range(len(word)):
            if word[i].isalpha() != True:
                print("Really, you're playing hangman and trying to win by cheating, you don't deserve to play, but I guess I have to let you...")
                valid = False
                break
            else:
                valid = True
    word.lower()
    solved = ""
    for i in range(len(word)):
        solved += "_"

    for i in range(30):
        print("*")

    print("Lets Begin! Player 1 has selected the word, Player 2, don't let the man hang!")
    print("This is what you're dealing with...")
    turn0()
    to_print = ""
    for i in range(0,len(solved)): 
        to_print += solved[i] + " "
    print(to_print)
    guesses = 5
    guessed_letters = 0

    while guesses > 0: 
        proper = False
        while not proper: 
            guessed = input("Enter a letter if you dare: ")
            if len(guessed) > 1:
                print("Just one letter...")
            elif guessed.isalpha() != True:
                print("You have to enter a letter genuis!")
            else:
                proper = True

        guessed.lower()
        checkLetter(guessed)
        if guessed_letters == len(word):
            print("You saved the man player 2! Couldn't you think of a better word player 1? I wish he wouldn't have escaped...")
            guesses = -1
        elif guesses == 5:
            turn0()
        elif guesses == 4:
            turn1()
        elif guesses == 3: 
            turn2()
        elif guesses == 2:
            turn3()
        elif guesses == 1: 
            turn4()
        elif guesses == 0:
            turn5() 
            print("There's nothing left of him now... you should be ashamed of yourself.... in other words, YOU LOSE player 2")

    play_again = input("Do you want to play again? (Enter Y or N): ")
    if play_again == "N":
        play = play_again
        print("Can't say I blame you, I'm not even having fun and I'm just a computer. Goodbye.")
    elif play_again == "Y": 
        play = play_again
        print("Come crawling back have you?")
    elif play_again == "y":
        play = "Y"
        print("You didn't really follow the directions but you still want to play so I'll allow it.")
    elif play_again == "n": 
        play = "N"
        print("Not a surprise that you can't follow simple instructions, seeya nerd.")
    else:
        play = "N"
        print("You really can't follow directions can you? I'm going to take that as a no. Goodbye.")



# turn0()
# turn1()
# turn2()
# turn3()
# turn4()
# turn5()

