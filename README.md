# Final Project for C++

For the C++ course you will have to build a nice app/game on your own.

**DEADLINE: 4th of January.** Doesn't mean you should build the app in december. Final touches can be made then.

All code should be placed inside this git project and be accompanied by a README and Makefile.

Choose 1 of the assignment options and inform your teacher about your choice.

## Snake game

Build a Snake clone. Make sure the player's score is tracked in a scoreboard (save as json file for example). Allow the map that is played to be loaded from a file (make up your own format).

Extra could be a map editor to create maps.

## General

- The whole app/game should be object oriented. No global stuff. Main should also be clean.
- Code should be your own. You can research techniques and such but no code copy pasting. If teacher finds out (and he/she does 9 out of 10 times), the other guy/girl gets the grades and not you.
- Decent GIT history so teacher can track your progress through time. This means committing often and committing small. This is also part of proving your code is your own.
- Provide a decent README explaining your project, how it is structured, what fancy techniques you used, how someone can build your app and how to run it. Also add a couple of screenshots in your README off how your app looks.
- A makefile so the user only needs to use `make` to build your app.
- Check if your application runs on other systems (Windows vs Linux). If not, no problem, but make sure to document this inside your README.

## Intro Snake Game

Welcome to Snake Game!!

This game is easy to install and fun to play but also unique: you can decide how the map looks like, there are leaderboards, 
the snake that can go faster and so much more!
Follow the steps below or watch the instruction video's in order to install the game.
The instructions of how to play the game can be found in the game itself.

Have fun!!

## How to run Snake Game?

First you need to clone the repository from github to your Linux pc (Windows is not compatible to play the game).
Open your terminal (e.g. Powershell) and type this command:

```bash
git clone git@github.com:vives-oop2-2020/challenges-cpp-final-app-TimonClaerhout.git
```

Then open the project with Visual Studio Code and open a new terminal.
Type in the terminal this command:

```bash
make
```

If project is build type:

```bash
cd bin/
```

```bash
./snake
```

Or you can also follow the steps of this instruction video: 

![Demo of snake game](./img/snake-game.gif)

## How to change map symbols?

Go to the src directory and open the symbol.json file, you will see this window:

![Window of symbol.json file](./img/mapeditor_window.png)

You can change the symbols that is displayed on the map but dont forget to rebuild your project again.

Follow the steps of "How to run Snake Game?" again but pay attention that you aren't in the bin directory anymore.
If that's the case, enter this command:

```bash
cd ..
```

Or you can follow the steps of this instruction video to change the map symbols:

![Demo of map settings](./img/map-settings.gif)
