# Student Roster C++

This C++ application manages a student roster, designed to add, remove, and display student information, including their degree program and average days in courses. **Currently, the application is under development and certain features, such as user interaction through the command line, are planned but not yet implemented.**

## Prerequisites

- **C++ compiler** (supporting C++14 or later)
- **CMake** (version 3.10 or later)
- **Git** (for cloning the repository)

## Getting Started

### Clone the Repository

First, clone the repository to your local machine:

```bash
git clone https://github.com/menezmethod/StudentRosterLG_CPP.git
cd StudentRosterLG_CPP
```

### Build the Project

To build the project, follow these steps:

1. Create a build directory and navigate into it:

   ```bash
   mkdir build
   cd build
   ```

2. Configure the project with CMake:

   ```bash
   cmake ..
   ```

   This command configures the project and prepares it for compilation, generating the necessary makefiles.

3. Compile the project:

   ```bash
   make
   ```

   This will compile all the source files and link them to create the executable. If you have set up your `CMAKE_RUNTIME_OUTPUT_DIRECTORY`, check the specified directory for the executable.

### Run the Application

After building the project, you can run the executable to see the current functionality:

```bash
./bin/StudentRosterLG_CPP
```

This command assumes that the executable is located in the `bin` directory within the build directory. Adjust the path according to where your executable is generated.

## Planned Features

- **User Interactivity**: Ability to add, remove, and display student entries through user input at the command line.
- **Database Integration**: Implement persistent storage for student data.
- **Extended Validation**: Enhance data validation during student data entry.

## Contributing

This project is in the early stages of development. Contributors are welcome to propose new features, report issues, and submit pull requests.