# 🕵️‍♀️ Spy Catcher Game (C++)

A terminal-based C++ game where you must **catch a moving spy** on a number line using intelligent guessing and logic.  
This was built as a **Design and Analysis of Algorithms** project by [Arooj Fatima](https://github.com/aroojaycodes).

---

## Objective

You’re a secret agent trying to catch a spy who moves across a number line.  
The spy's position is defined by a hidden linear equation:

position = a + b * t


Where:
- `a` is the starting position (random)
- `b` is the movement per turn (non-zero, random)
- `t` is the current time step

Your mission is to **guess the spy’s position** before they escape your search range!

---

## Concepts Used

- Object-Oriented Programming (OOP)
- Randomization using `rand()`
- Terminal-based input/output
- Search space narrowing (like binary search)
- Color-coded CLI with ANSI escape codes
- ASCII Art for game UI

---

## Game Preview

```bash
============================================
             SPY CATCHER GAME
============================================

A spy is moving on a number line!
At time 0, the spy was at position a
Each time step, the spy moves b units
Both a and b are unknown integers (b ≠ 0)

Search range: [-100 to 100]
Suggested guess (midpoint): 0
Enter your guess: 10

Time Step: 0
Your guess: 10
Area: [.....Y.....S.....]
Hint: Spy is to the RIGHT (new min: 11)

Press Enter to continue...

```

## How to Play
Compile the game using any C++ compiler:

g++ spy-catcher-game.cpp -o spygame
./spygame
Read the instructions on screen.

Use the hints (LEFT / RIGHT) to update your guesses.

Catch the spy before they escape the number line!

## File Info
File Name	Description
spy-catcher-game.cpp:	Main game logic with color output, ASCII UI, and game loop
README.md: Project documentation (you’re reading it!)

## Author
Arooj Fatima
🎓 5th Semester CS Student
📌 Islamabad, Pakistan
🌐 GitHub Profile

## Star This Repo!
If you liked this project, consider giving it a ⭐ to show support and help others find it!
