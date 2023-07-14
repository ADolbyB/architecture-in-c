/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. BAssem Alhalabi
 * Lab 2-1:
 *      Write a C program that creates 3 processes (1 parent & 2 children). The process will relay information to 
 *      each other in the following fashion:
 *      - The first process (parent) reads a text file "input.txt" line by line.
 *      - The second process reads from the first pipe and reverse letters (Capital to small & small to Capitals).
 *      - The third process reads from the second pipe and outputs to a file e.g. ``output.txt''.
 *      Note that you need to use `pipe()` and `fork()` to create this pipelining assignment. Also, create a text 
 *      file which contains several text lines. The file will be used as an input for your program.
*/