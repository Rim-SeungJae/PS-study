# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a competitive programming study repository containing C++ solutions for algorithmic problems. The files are organized by problem numbers and algorithm types, primarily focusing on problems from online judges like Baekjoon.

## Build Commands

Since this is a C++ competitive programming repository:

- **Compile a single file**: `g++ -o filename filename.cpp`
- **Compile with optimizations**: `g++ -O2 -o filename filename.cpp`
- **Run a compiled program**: `./filename.exe` (Windows) or `./filename` (Unix)

## Code Structure and Patterns

### File Naming Convention
- Files are named by problem numbers (e.g., `1000.cpp`, `1001.cpp`)
- Some files include algorithm names for clarity (e.g., `1753_dijkstra.cpp`, `1197_unionfind.cpp`, `2629_knapsack.cpp`, `5052_Trie.cpp`)

### Common Algorithm Implementations
- **Graph algorithms**: Dijkstra's shortest path, Union-Find (Disjoint Set Union)
- **Dynamic Programming**: Knapsack problem variations
- **Data structures**: Trie for string processing
- **Tree algorithms**: Segment trees, binary indexed trees

### Code Style Patterns
- Uses `#include<cstdio>` for input/output (competitive programming style)
- Minimal use of standard library beyond essential containers
- Global arrays and variables are common
- Functions are typically short and problem-specific
- Uses `scanf/printf` for faster I/O instead of `cin/cout`

### Algorithm-Specific Notes
- Dijkstra implementations use priority queues with negative weights for max-heap behavior
- Union-Find implementations include path compression optimization
- Dynamic programming solutions often use 2D boolean arrays for state tracking
- Trie implementations use arrays instead of maps for better performance

When working with this codebase, focus on algorithm correctness and competitive programming best practices rather than software engineering patterns.