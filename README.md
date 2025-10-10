# C++ Experiment

This is a tiny, object-oriented CLI quiz written in C++17.

The purpose is to find ways to use VS Code with C++ codebases with a lot of legacy code.

Because it's not possible to easily modify the codebase at our workplaces, using VS Code settings for formatting and linting is needed. This project aims to use a `.vscode/settings.json` file to make the `clangd` VS Code plugin work as intended.

We do not use the `C/C++` VS Code plugin from Microsoft because it's sluggish.

## Structure

- include/: C++ header files
- src/: C++ implementation and `main.cpp`

## Commands

Build the executable.

```shell
cmake -S . -B build
cmake --build build --config Release
```
