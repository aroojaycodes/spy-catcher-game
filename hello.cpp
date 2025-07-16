#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
class SpyGame {
private:
 int a; // initial position
 int b; // movement per turn
 int currentPosition;
 int timeStep;
 int guesses;
 bool caught;
public:
 SpyGame() {
 srand(time(0));
 a = (rand() % 201) - 100;
 do {
 b = (rand() % 21) - 10;
 } while (b == 0);
 currentPosition = a;
 timeStep = 0;
 guesses = 0;
 caught = false;
 }

 void printMap(int guess) {
 cout << CYAN "\nTime Step: " << timeStep << RESET << endl;
 cout << BLUE "Spy's movement pattern: position = a + b*t\n" RESET;
 cout << GREEN "Your guess: " << guess << RESET << endl;
 int minDisplay = min(currentPosition, guess) - 5;
 int maxDisplay = max(currentPosition, guess) + 5;
 cout << "\nArea: [";
 for (int i = minDisplay; i <= maxDisplay; i++) {
 if (i == currentPosition) {
 cout << RED "S" RESET;
 }
 else if (i == guess) {
 cout << GREEN "Y" RESET;
 }
 else if (i == 0) {
 cout << WHITE "|" RESET;
 }
 else {
 cout << ".";
 }
 }
 cout << "]\n";
 cout << YELLOW " S = Spy, Y = Your guess\n\n" RESET;
 }

 bool checkGuess(int guess) {
 currentPosition = a + b * timeStep;
 printMap(guess);
 if (guess == currentPosition) {
 caught = true;
 cout << BOLD GREEN "\nSUCCESS! You caught the spy!\n" RESET;
 cout << MAGENTA "\nSpy's movement was: position = " << a << " + " << b <<
"*t\n" RESET;
 cout << CYAN "Total guesses: " << guesses + 1 << RESET << endl;
 printwingame();
 return true;
 }

 cout << RED "Missed! The spy was at position: " << currentPosition << RESET <<
endl;
 return false;
 }

 void printgameover() {
 cout << BOLD RED R"(  _____                        ____
 / ____|                      / __ \
| | __ __ _ _   __ ___   ___ | |  | |_ _____ _ __
| | |_ |/ _` | '_ ` _ \ / _ \| |  | \ \ / / _ \ '__|
| |__| | (_| | | | | | | (_/_| |__| |\ V / __/ |
 \_____|\__,_|_| |_| |_|\__\ / \____/ \_/ \___|_|


)" << endl;
 }
 void printwingame() {
 cout << BOLD GREEN R"(
__     __                             _
\ \   / /                   (_)      | |
 \ \_/ /__  _  _ \ \ /\  / / _ _ __  | |
  \   / _\| | | | \ \/ \/ / | | '_ \ | |
   | |(_) | |_| |  \  /\ /  | | | | ||_|
   |_|\___/ \___|   \/ \/   |_| |_| |(_)

)" << endl;
 }

 void play() {
 cout << BOLD BLUE "============================================\n" RESET;
 cout << BOLD YELLOW "             SPY CATCHER GAME\n" RESET;
 cout << BOLD BLUE "============================================\n\n" RESET;
 cout << BOLD RED R"(...................:~~:.....................
..................:G&&G:....................
...................G@@G:.....:..............
...............:~7J5PG?...^~~~..............
...............P&&@&GY5BPG&7................
...............?&&&&&&B&###~................
................?&&&&&&&&&#^................
.................Y&&&#G&&BB!................
.................7@&&&&&&J..................
.................G&&&&&&&G..................
................7&&&&&&&&B:.................
................~B&&&&&&&B:.................
................^#&&&&&&&G..................
................?@&&#!B&&G..................
................G&&&! Y@&5..................
...............~&&@J..7&@5..................
...............Y@@G...^#@P..................
..............:B&#~...^#&G..................
..............!&@J....^&&#:.................
..............Y@&~....:B&#^.................
..............G@P......Y@&?.................
..............G@G......7#BB5J~..............
..............!?7......::::^^:..............)" << endl;
 cout << endl;
 cout << CYAN "A spy is moving on a number line!\n" RESET;
 cout << CYAN "At time 0, the spy was at position a\n" RESET;
 cout << CYAN "Each time step, the spy moves b units\n" RESET;
 cout << CYAN "Both a and b are unknown integers (b ≠ 0)\n\n" RESET;

 int minPos = -100;
 int maxPos = 100;

 while (!caught) {
 cout << BOLD MAGENTA "\n=== Time Step " << timeStep << " ===\n" RESET;
 currentPosition = a + b * timeStep;
 // Check if spy escaped the range
 if (currentPosition < minPos || currentPosition > maxPos) {
 cout << RED "\nGAME OVER! The spy escaped your search range!\n" RESET;
 printgameover();
 cout << RED "Final spy position: " << currentPosition << RESET << endl;
 cout << RED "Your search range was: [" << minPos << " to " << maxPos <<
"]\n" RESET;
 cout << MAGENTA "Spy's movement was: position = " << a << " + " << b <<
"*t\n" RESET;
 break;
 }

 cout << BLUE "Search range: [" << minPos << " to " << maxPos << "]\n" RESET;
 cout << BLUE "Spy must be between: " << minPos << " and " << maxPos << "\n"
RESET;
 int suggestedGuess = (minPos + maxPos) / 2;
 cout << GREEN "Suggested guess (midpoint): " << suggestedGuess << RESET <<
endl;
 int playerGuess;
 
 cout << YELLOW "Enter your guess: " RESET;
 while (!(cin >> playerGuess)) {
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 cout << RED "Invalid input. Please enter a number: " RESET;
 }

 if (checkGuess(playerGuess)) {
 break;
 }
 // Narrow the range based on the hint
 if (currentPosition < playerGuess) {
 maxPos = playerGuess - 1;
 cout << CYAN "Hint: Spy is to the LEFT (new max: " << maxPos << ")\n"
RESET;
 }
 else {
 minPos = playerGuess + 1;
 cout << CYAN "Hint: Spy is to the RIGHT (new min: " << minPos << ")\n"
RESET;
 }
 
 // Check for empty range
 if (minPos > maxPos) {
 cout << RED "\nGAME OVER! Your range collapsed!\n" RESET;
 printgameover();
 cout << RED "Spy's final position: " << currentPosition << RESET << endl;
 cout << MAGENTA "Spy's movement was: position = " << a << " + " << b <<
"*t\n" RESET;
 break;
 }
 guesses++;
 timeStep++;
 cout << "\nPress Enter to continue...";
 cin.ignore();
 cin.get();
 }
 }
};
int main() {
 SpyGame game;
 game.play();
 return 0;
}
