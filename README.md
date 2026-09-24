# 📝 Console To-Do List Manager

A lightweight, console-based To-Do List application built in C++. This project demonstrates core programming fundamentals, including object-oriented programming (OOP), file handling for data persistence, and automated timestamps.

## 🚀 Features
- **Persistent Storage:** Automatically saves tasks to a `tasks.txt` file and reloads them when the app starts.
- **Smart Timestamps:** Automatically captures the exact date and time a task was added using the `<chrono>` library.
- **Clean Interface:** A straightforward console menu for adding, viewing, and removing tasks.

## 🛠️ Built With
- **C++11** or higher
- Standard Libraries: `<vector>`, `<fstream>`, `<chrono>`, `<iomanip>`,`<sstream>`
- System Specifics: Uses Windows-specific `<conio.h>` for instant menu selections (`_getch()`).
