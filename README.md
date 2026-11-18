# 🐍 Snake Game - C++ OOP Project

A classic Snake Game developed using **C++** as an Object-Oriented Programming (OOP) course project.

The game runs in the Windows terminal and demonstrates fundamental OOP concepts through a simple interactive application.

## 🎮 Game Features

- Snake movement using keyboard controls.
- Food generation at random positions.
- Snake growth when eating food.
- Score system (10 points per food).
- Wall collision detection.
- Self-collision detection.
- Game Over screen.
- Restart and exit options.

## 🕹️ Controls

| Key | Action |
|---|---|
| W | Move Up |
| S | Move Down |
| A | Move Left |
| D | Move Right |
| Q | Quit |

## 🛠️ Technologies Used

- C++
- C++17
- CMake
- MinGW-w64
- Standard C++ Library
- Windows `conio.h` for keyboard input

## 📁 Project Structure

```text
SnakeGame/
│
├── include/
│   ├── GameObject.h
│   ├── Snake.h
│   ├── Food.h
│   ├── ScoreManager.h
│   └── Game.h
│
├── src/
│   ├── GameObject.cpp
│   ├── Snake.cpp
│   ├── Food.cpp
│   ├── ScoreManager.cpp
│   └── Game.cpp
│
├── main.cpp
└── README.md
```

## 🧠 Object-Oriented Programming Concepts

This project demonstrates several fundamental OOP concepts:

- **Classes and Objects:** Classes represent the game components, such as `Snake`, `Food`, `ScoreManager`, and `Game`.
- **Encapsulation:** Private data members are accessed and modified through public member functions.
- **Constructors and Destructors:** Used to initialize and manage objects.
- **Inheritance:** `Snake` and `Food` inherit from the abstract `GameObject` class.
- **Abstraction:** `GameObject` defines a pure virtual function named `draw()`.
- **Polymorphism:** Virtual functions and overriding provide the mechanism for dynamic dispatch.
- **Function Overloading:** `ScoreManager` provides two versions of `addPoints()` with different parameters.
- **Access Modifiers:** `private` and `public` control access to class members.

## ⚙️ Requirements

To build and run this project, you need:

- Windows operating system.
- A C++ compiler (MinGW-w64).
- CMake 3.20 or later.

## 🚀 Build and Run

Open PowerShell in the project directory and execute:

### 1. Configure the project

```powershell
cmake -S . -B build -G "MinGW Makefiles"
```

### 2. Build the project

```powershell
cmake --build build
```

### 3. Run the game

```powershell
.\build\SnakeGame.exe
```

## 📌 Notes

- This project is designed for educational purposes.
- The game uses terminal-based graphics.
- Keyboard input relies on Windows-specific `conio.h`.

## 👨‍💻 Author

Developed as a C++ Object-Oriented Programming course project.
