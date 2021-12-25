#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
 std::cout << "\n\nYou're alone in a city where no one knows your name.\n";
 std::cout << "You suddenly think to call " << Difficulty;
 std::cout << " of your relatives for help, but you forget their home phone number.\n";
}

bool PlayGame(int Difficulty) {
  
     PrintIntroduction(Difficulty);

    // declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

   

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print sum and product to terminal
    std::cout << std::endl;
    std::cout << "+ There are three numbers missing in the number.";
    std::cout << "\n+ The numbers add up to: " << CodeSum;
    std::cout << "\n+ The numbers multiply to give: " << CodeProduct << std::endl;

    // store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n***The number starts dialing and you reach your relative, but he can't help you. Try calling another relative!***" ;
        return true;
    } else {
        std::cout << "\n***The operator starts talking, 'We're sorry, the number you have dialed is not in service. Please dial again.'***";
        return false;
    }  
}

int main () {

    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) { // loop until all levels are completed
        bool bLevelComplete = PlayGame(LevelDifficulty);
        // avoids the endless loop
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            // increase difficulty
            ++LevelDifficulty;
         }
    }
    
    std::cout << "\n***You finally reach a relative that can help bring you home! You win!***";
    return 0;
}

