def check_winner(board):
    # Check rows for a winner
    for row in board:
        if row == "XXX":
            return "Skander wins"
        elif row == "OOO":
            return "Amen wins"
    # Check columns for a winner
    for j in range(3):
        column = board[0][j] + board[1][j] + board[2][j]
        if column == "XXX":
            return "Skander wins"
        elif column == "OOO":
            return "Amen wins"
    # Check diagonals for a winner
    diagonal1 = board[0][0] + board[1][1] + board[2][2]
    diagonal2 = board[0][2] + board[1][1] + board[2][0]
    if diagonal1 == "XXX" or diagonal2 == "XXX":
        return "Skander wins"
    elif diagonal1 == "OOO" or diagonal2 == "OOO":
        return "Amen wins"
    # Check if the board is full
    if "." not in "".join(board):
        return "Draw"
    # If none of the above conditions are met, the game is not over
    return None

def solution(board):
    # Count the number of Xs and Os on the board
    num_X = sum(row.count("X") for row in board)
    num_O = sum(row.count("O") for row in board)
    # Check if the game is over
    winner = check_winner(board)
    if winner is not None:
        return winner
    # Determine whose turn it is
    if num_X == num_O:
        return "Skander to play"
    elif num_X == num_O + 1:
        return "Amen to play"
    else:
        return "Invalid board configuration"
