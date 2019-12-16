# Tic Tac Toe...


dsply_arr = [10]
display_val = ' '
print('\n ---------- :Tic Tac Toe:  ----------\n')
player1 = input("Enter Player1 name : ")
print(str(player1) + " will use 'X'")
player2 = input("Enter Player2 name : ")
print(str(player2) + " will use 'O'")

score1 = 0
score2 = 0

for a in range(10):
    a += 1
    dsply_arr.insert(a, ' ')


def body():
    print("  " + dsply_arr[1] + "|" + " " + dsply_arr[2] + " " + "|" + dsply_arr[3] + "  ")
    print("---" + "|" + "---" + "|" + "---")
    print("  " + dsply_arr[4] + "|" + " " + dsply_arr[5] + " " + "|" + dsply_arr[6] + "  ")
    print("---" + "|" + "---" + "|" + "---")
    print("  " + dsply_arr[7] + "|" + " " + dsply_arr[8] + " " + "|" + dsply_arr[9] + "  ")

    print("\n Score: ")
    print("      " + str(player1) + " = " + str(score1))
    print("      " + str(player2) + " = " + str(score2))


body()


def display(position, display_val):
    dsply_arr[int(position)] = str(display_val)


def check_winner():
    if dsply_arr[1] == dsply_arr[2] == dsply_arr[3] != ' ':
        return 1
    elif dsply_arr[4] == dsply_arr[5] == dsply_arr[6] != ' ':
        return 1
    elif dsply_arr[7] == dsply_arr[8] == dsply_arr[9] != ' ':
        return 1
    elif dsply_arr[1] == dsply_arr[4] == dsply_arr[7] != ' ':
        return 1
    elif dsply_arr[2] == dsply_arr[5] == dsply_arr[8] != ' ':
        return 1
    elif dsply_arr[3] == dsply_arr[6] == dsply_arr[9] != ' ':
        return 1
    elif dsply_arr[1] == dsply_arr[5] == dsply_arr[9] != ' ':
        return 1
    elif dsply_arr[3] == dsply_arr[5] == dsply_arr[7] != ' ':
        return 1
    else:
        return 0


p = 0
chance = 0
used_opt = []
range_var = 9
for ptr in range(range_var):
    print(range_var)
    if chance == 0:  # used to check the chance of the player
        position = input("\n" + str(player1) + "'s" + " Position : ")
        if position not in used_opt:
            used_opt.append(position)
            display_val = "X"
            display(int(position), str(display_val))
            chance += 1
            score1 = score1 + check_winner()
        else:
            print(" Oops..!!!,Please enter unused position...")
            range_var = range_var+1

    else:
        position = input("\n" + str(player2) + "'s" + " Position : ")
        if position not in used_opt:
            used_opt.append(position)
            display_val = "O"
            display(position, display_val)
            chance -= 1
            score2 = score2 + check_winner()
        else:
            print("\n Oops..!!!,Please enter unused position...\n")
            range_var = range_var + 1



    if score1 > score2:
        body()
        print('\n\n Congratulations!!!!!, ' + str(player1) + ' has WON the match.\n\n\n')
        break
    elif score2 > score1:
        body()
        print('\n\n Congratulations!!!!!, ' + str(player2) + ' has WON the match.\n\n\n')
        break
    else:
        body()


if score1 == score2:
    body()
    print("\n\n Draw!!!!....Better luck next time.")