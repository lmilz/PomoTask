```
  _____                   _______        _    
 |  __ \                 |__   __|      | |   
 | |__) |__  _ __ ___   ___ | | __ _ ___| | __
 |  ___/ _ \| '_ ` _ \ / _ \| |/ _` / __| |/ /
 | |  | (_) | | | | | | (_) | | (_| \__ \   < 
 |_|   \___/|_| |_| |_|\___/|_|\__,_|___/_|\_\
                                              
```

# PomoTask

A lightweight and efficient command-line application that combines the Pomodoro technique with a built-in to-do list manager. Stay productive and organized directly from your terminal!

## Features

- **Pomodoro Timer**: Focus on tasks using the proven Pomodoro technique.
- **Customizable Durations**: Adjust work and break durations to fit your needs.
- **User-Friendly Interface**: Clean and simple CLI design.

## Work in Progress

- [ ] **To-Do Manager**: Create, update, and delete tasks easily.
- [ ] **Database connection**: Save and fetch all data within a database.
- [ ] **Progress Tracking**: Monitor completed Pomodoros for each task.
- [ ] **Markdown export**: Export Pomodoros into markdown notes.

## Getting Started

### Prerequisites

- A C++ compiler supporting C++20 or higher.
- Make.
- Test Framework cpputest

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/lmilz/PomoTask.git
   cd PomoTask
   ```

2. Build the project:
   ```bash
   make
   ```

3. Run the application:
   ```bash
   ./PomoTask
   ```

### Usage

#### Start a Pomodoro Session
```bash
./PomoTask --pomodoro <focustime> <effect>
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.