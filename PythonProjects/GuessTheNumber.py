import random
def Game(name):
    player = name
    print("The game we are going to play is really easy, I will choose a number and you will have to guess it within 5 attempts")
    print("Ahh and also I will guess the numbers based on your choice of difficulty :p")
    while(1):
        print("\tHow difficult do you want it?,"+player+" [Dummy/Easy/Medium/Hard/Impossible/Insane!]")
        difficulty = input("[Difficulty]~ ")
        if difficulty == 'Dummy' or difficulty == 'dummy':
            level = 20
            break
        elif difficulty == 'Easy' or difficulty == 'easy':
            level = 40
            break
        elif difficulty == 'Medium' or difficulty == 'medium':
            level = 50
            break
        elif difficulty == 'Hard' or difficulty == 'hard':
            level = 100
            break
        elif difficulty == 'Impossible' or difficulty == 'impossible':
            level = 1000
            break
        elif difficulty == 'Insane' or difficulty == 'insane':
            level = 10000
            break
        else:
            print("ehhhh that level of difficulty does not exist!!, Try again b-baka!")
    print("hmm Nice, you want to play with",difficulty," Nice choice!")
    print("I will guess a number between 1 to ",level)
    ScarletGuess = random.randint(1,level)
    attempt = 0
    while(attempt <=6):
        if(attempt == 5 and PlayerGuess != ScarletGuess):
            print("Well you lost :( ")
            print("Nevermind better luck next time!")
            print("By the way my guess was",ScarletGuess)
            print("Want to play again ?, trust me it was fun!")
            break
        print("Okay guess the number :D")
        attempt +=1
        print("You have ",(6-attempt)," attempts left!")
        PlayerGuess = int(input("[]:~  "))
        if PlayerGuess < ScarletGuess:
            print("Stupid, thats way toooo low!")
        elif PlayerGuess > ScarletGuess:
            print("Thats way tooo large baka!")
        elif PlayerGuess == ScarletGuess:
            print("Whoa! nice well played")
            print("That too in ",attempt,"attempts")
            print("Well Done!, wanna play again? ")
            break
        else:
            print("Strange this should not happen oopsie I forgot the number, I am sorry ;_; ")
    return 

##############################################################################################        
print("Hi I am Scarlet, I am the worlds most beautiful AI! what is your name?")
name = input("Name[]:~ ")
print("Nice name ",name,",Guess what I feel like playing!!! Wanna play a game with me? [Yes/yes/No/no/umm..]")
while(1):
    choice = input("[Wanna play a game? ]:~ ")
    if choice == 'Yes' or choice == 'yes':
        Game(name)
    elif choice == 'No' or choice == 'no':
        print(" Awww >_< I hate you meanie ;_; ")
        exit(1)
    else:
        print("C'mon Its going to be fun :D ")



