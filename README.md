# CS50 Way

This repository documents my journey through Harvard's CS50 course.

The purpose of this project is to organize my studies, exercises, problem sets, and experiments while I build a strong foundation in computer science and programming.

## Repository Structure

- `lecture_1/` — Introduction to C, basic syntax, loops, and conditionals
- `lecture_2/` — Arrays, strings, and introductory problem solving
- `lecture_3/` — Algorithms, searching, sorting, and voting systems
- `lecture_4/` — Memory, pointers, files, and low-level programming
- `lecture_5/` — Data structures such as linked lists, stacks, and queues
- `sandbox/` — Personal experiments, small tests, and extra practice files

## Learning Approach

This repository is not only a storage space for course files, but also a record of my learning process.

I use it to:

- keep official CS50 problem sets organized
- separate practice files from course assignments
- document my progress as I move through the course
- build a portfolio that reflects my growth in programming

## Current Progress

- [x] Lecture 0
- [x] Lecture 1
- [x] Lecture 2
- [x] Lecture 3
- [x] Lecture 4
- [x] Lecture 5
- [ ] Lecture 6
- [ ] Lecture 7
- [ ] Artificial Intelligence Lecture
- [ ] Lecture 8
- [ ] Lecture 9
- [ ] Lecture 10

## Goal

My goal with this journey is to strengthen my fundamentals in computer science, improve my problem-solving skills, and gradually transition into the technology field with a solid portfolio of projects and studies.


## Lecture Notes

### Lecture 0
First of all, I was impressed by Professor David Malan's enthusiasm, mastery, and teaching skills; he made my eyes light up with excitement for the world of computer science!

In the initial lesson, I learned the basic concepts of IDEs, compilers, problem-solving, going through the ASCII table, Unicode, RGB, and other interpretations that can be applied to memory bits. Furthermore, I also gained a better understanding of algorithms and their implementations using pseudocode and variations in different existing languages. Within Scratch, we explored concepts such as loops, abstractions, and conditionals.

### Lecture 1
In the first lesson, we covered the basics of the C programming language, where I learned more about source code and its conversion to machine code (0 and 1) using a compiler. We explored how to use the VS Code IDE, pre-configured by the CS50 team, and finally, we created our first code, the famous "Hello World." Here, we learned about special characters, the use of libraries, and their ready-to-use functions and methods. We also explored some Linux command-line interface (CLI) commands, covered the main aspects of C, such as conditionals, variable types, variable formatting, and how to use the main operators. We practiced with some C code and finally, understood the concepts of code correctness, design, and style.

### Lecture 2
In the second lesson, the concept of Arrays was explored, where I learned more about debugging techniques, such as the simple use of printf, as well as better techniques like using debug50, which I found fantastic for observing the code at each iteration or line read. We also saw a bit more about source code compilation, where the steps involved in the compilation process were shown: preprocessing, compiling, assembling, and linking. The concept of arrays was introduced, which are simply values ​​stored sequentially in memory, one after the other. The concept of strings was also explored; they are "almost" like arrays, but store values ​​of type char and are necessarily terminated with a special terminator '\0'. I learned about some string functions and their conversions via ASCII tables. We also learned about command-line arguments, which can be entered when calling functions in the terminal, serving as inputs for the function to be called. Finally, we saw that there are exit statuses, which can be very useful when dealing with various functions and other needs.

### Lecture 3
In the third lesson, they further explored the concepts of algorithms and some of the main ones, such as search and lookup algorithms. Exploring the issue of execution time and complexity using Big O notation, they also showed that at certain times the existing variables may be insufficient; for this, there are structs that can be used to create specific types of data structures for each demand. At the end of the lesson, the concept of recursion was presented and how it can be useful, also showing its elegance from a code design point of view and how algorithms can benefit from its use.

### Lecture 4
In the fourth lesson, the various and complex concepts of memory in binary machines were explored, where issues such as Pixel Art were presented, as well as the use of a new way to represent variables called Hexadecimal, which is nothing more than a way to "compact" large numbers using fewer characters to represent them. Following this, they showed how the memory dynamics of the machines work and that their addresses are named with hexadecimal numbers (because there are many addresses). Then, the infamous pointers were introduced... ah... Here I really struggled to understand them even minimally to continue... They explored how pointers interact with variables, strings, and arrays, showing how to operate with pointers and their basic arithmetic. From this point on, comparing strings is not trivial, and it was demonstrated how it can be done (thankfully, there are ready-made functions that help us with these issues)... They also explored how the dynamics of copying variables and allocating space for them can be less practical than in high-level functions (like Python), where we learned about new functions such as malloc, realloc, the memory protector Valgrind (like a Valkyrie) to show the possible leaks that the code is generating, also learning more about garbage values. They also showed about Heap and Stack and the possibilities of Overflow in these memory structures.

### Lecture 5
In the fifth lesson, we explored the main data structures that can be created to make programmers' lives easier (or more difficult). The main data structures explored were: Queues, which function like queues where the first in is the first out (FIFO); Stacks, which function like stacks where the last in is the first out (LIFO); we reviewed Arrays and their potential for garbage collection, as well as the difficulty of increasing the size of an array so easily. This led to the concept of linked lists to overcome this type of problem, and methods for creating and handling linked lists were presented. Trees were also introduced, along with the concepts of Hashing and Hash Tables, and finally Tries, always highlighting the advantages and disadvantages of each structure.

Understanding the structures wasn't as difficult as applying them in the week's problem set exercises. It required considerable effort to minimally consolidate these concepts and apply them to solve the Inheritance and Speller problems.

### Lecture 6

