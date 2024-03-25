# animatedBar-chart
Project 3 visualizes population changes of major cities (1500-2018) through C++ animations. Emphasizing data parsing, memory management, and testing, it highlights the skills in crafting dynamic visual applications.
# Project 3: Bar Chart Animation

## Overview
This project involves creating an animated visualization of the most populous cities in the world from 1500 to 2018. Each frame of the animation represents a single year, with cities displayed as bars whose length corresponds to their population. The project requires extensive use of C++ for data processing, dynamic memory management, and animation in the terminal.

## Set-Up Requirements
- **IDE:** Codio IDE (mandatory for this project due to specific tool requirements).
- **Tools:** Valgrind is used extensively for memory leak detection and management.

## Implementation Details
- **Classes:** The project is structured around three main classes: `Bar`, `BarChart`, and `BarChartAnimate`, along with supporting functions for animation and data handling.
- **Data Source:** The population data comes from various sources, including SEDAC, the United Nations, and Demographia, spanning the years 1500 through 2018.
- **Animation:** The `BarChartAnimate` class handles the animation, displaying each frame to represent data for a specific year.

## Getting Started
1. **Clone the Project:** Start by cloning the repository to your local machine or Codio workspace.
2. **Data Preparation:** Ensure you have the data file `cities.txt` placed in the correct directory.
3. **Compilation and Running:**
   - Compile the project using `make build`.
   - Run the project with `make run`.
   - For memory leak testing, use `make valgrind`.

## Contribution Guidelines
- **Testing:** All contributions should include thorough tests, verified by running `make build_tests` and `make run_tests`.
- **Memory Management:** Pay close attention to memory allocation and deallocation to prevent leaks.
- **Creative Component:** Feel free to enhance the user interface or add features, provided the core functionality remains intact.


Good luck!
