📚 Introduction

This repository contains my journey into learning C++ using the C++98 standard.
The project is part of the 42 School curriculum and represents my first steps into object-oriented programming in C++.
The main goals of this project were:
	learning basic C++ syntax,
	understanding classes, objects, and encapsulation,
	working without dynamic memory allocation,
	writing clean, modular, and C++98-compliant code.
Each exercise focuses on different core concepts and helped me build solid foundations in C++.


📌 How to Run
1. Navigate to the folder of the exercise you want to run.
2. Run make in the terminal.
3. Execute the program, e.g. ./megaphone.

Each project folder also contains my personal notes related to the exercise, written in Polish.
If you do not understand Polish, using a translator is recommended.

📚 Module Overview & Learning Outcomes

Module 00 – First Steps in C++ 💻
Built simple console applications.
Learned basic C++ syntax, class design, and data encapsulation.
Focused on clean, modular code without dynamic memory.
Transitioned from procedural to object-oriented thinking.

Module 01 – Pointers & Memory 🧠
Explored memory management using pointers and references.
Learned stack vs heap allocation and destructors.
Gained experience in file handling and structured program logic.
Understood the role of references and pointers in class design.

Module 02 – Fixed Point Numbers 🔢
Implemented a custom numeric type (fixed-point numbers).
Used operator overloading and the Orthodox Canonical Class Form.
Learned precision handling and class design mimicking built-in types.

Module 03 – Inheritance & Class Relationships 🏗️
Extended base classes with derived classes implementing unique behavior.
Studied constructor and destructor call order and inheritance chaining.
Learned code reuse, method overriding, and polymorphic behavior.

Module 04 – Polymorphism & Abstract Classes 🎭
Implemented virtual functions and safe dynamic memory management.
Worked with composed classes and deep copies.
Strengthened understanding of interfaces, inheritance, and safe memory handling.

Module 05 – Exceptions & Design Patterns ⚠️
Built classes with robust error handling using exceptions.
Designed abstract base classes and managed interactions between classes safely.
Improved architecture design for scalable and maintainable code.

Module 06 – Type Conversion & Serialization 🔄
Explored safe type casting, pointer-to-integer conversions, and serialization.
Implemented functions detecting real object types without typeinfo.
Reinforced pointers, references, and static methods usage in C++.

Module 07 – Templates 🛠️
Implemented function templates: swap, min, max, and iter.
Built a template Array class with dynamic memory and bounds checking.
Learned reusable generic code, exception handling, and memory management.

Module 08 – STL Containers & Iterators 📦
Implemented easyfind to locate values in containers.
Built a Span class to compute shortest and longest spans of numbers.
Created a MutantStack – a stack with iterators.
Learned iterators, generic algorithms, and exception-safe container handling.

Module 09 – STL Algorithms & Performance 🚀

Exercise 00 – Bitcoin Exchange 💰
Program btc reads dates and bitcoin amounts, calculates value in USD using a CSV database.
Handles invalid dates, negative or too large values.
Uses closest previous date if the exact one is missing.
Learned STL containers, data lookup, input validation, and exception handling.

Exercise 01 – Reverse Polish Notation (RPN) ➗
Evaluates expressions in Reverse Polish Notation using operators + - * /.
Implemented with a stack (std::stack).
Learned sequential data processing, container-based algorithms, and runtime exception handling.

Exercise 02 – PmergeMe 📊
Implements merge-insert sort (Ford-Johnson) for positive integer sequences.
Uses at least two different STL containers and measures execution time for each.
Learned custom sorting, handling large datasets, performance analysis, and comparing container efficiency.

All Module 09 exercises emphasized robust data validation, exception handling, and careful testing.