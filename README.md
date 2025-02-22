### CS-300 Analysis and Design Portfolio

## Overview
This repository contains my CS-300 Analysis and Design Portfolio project for SNHU. The project demonstrates data structures, algorithms, and program design principles.

## Project Details  
- Course: CS-300 Analysis and Design  
- Programming Language: C++  
- Project: Course Planner Program  
- Skills Demonstrated: File I/O, Data Structures, User Interaction  

## How to Run the Program  
1. Download `ProjectTwo.cpp`.  
2. Compile and run it in a **C++ IDE** (Visual Studio recommended).  
3. Follow the on-screen menu instructions.  


## Reflection  

Throughout this project, I tackled the problem of efficiently storing, retrieving, and displaying course information for a Computer Science advising system. The primary challenge was ensuring that course data, including prerequisites, could be organized and accessed seamlessly. The solution required designing a structured approach to file handling and implementing an efficient data storage method.

To address this, I utilized an unordered map (hash table) for fast lookup of courses. This allowed me to store course numbers as keys and their respective details as values. Understanding the importance of data structures was crucial in making design choices that enhanced efficiency, readability, and usability.

I encountered roadblocks while integrating file handling and ensuring the data loaded correctly from the provided CSV file. Debugging incorrect file paths and handling unexpected input formats were major challenges. I overcame these issues by implementing **error handling**, checking file existence before loading, and validating input at each step.

This project expanded my understanding of software design by reinforcing the importance of modular programming. Breaking the program into logical components, such as a `Course` class and a `CoursePlanner` class, allowed for better organization and code reuse. This experience also solidified my understanding of user driven menus and the role of sorting algorithms in presenting ordered information.

In terms of maintainability, readability, and adaptability, I focused on clear variable naming, proper commenting, and structured output formatting. Writing reusable functions and maintaining separation of concerns ensured that future modifications or expansions to the project would be straightforward. I now prioritize structuring programs in a way that makes debugging and scalability easier.

Overall, this project helped me develop better coding habits, improve my problem solving skills, and gain confidence in working with file handling, data structures, and interactive programs in C++.  
