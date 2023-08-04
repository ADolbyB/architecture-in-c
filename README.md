# Computer Architecture in C

A Collection of Code from CDA-4102: Computer Architecture.

A major topic in this course is: [Unix Processes in C](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY), so there is a YouTube tutorial playlist.

The book following this course is [Computer Systems: A Programmer's Perspective, 3/E](http://csapp.cs.cmu.edu/)
 - This book uses programming in C language for assignments.

## Other Sources:

Another good book for Computer Architecture is: [Structured Computer Organization](https://www.pearson.com/en-us/subject-catalog/p/structured-computer-organization/P200000003183/9780137618446)
 - This book is more about hardware and does not include programming.

[C Language Placeholders](https://en.m.wikibooks.org/wiki/C_Programming/Simple_input_and_output) List and examples of usage.
 - Remember that `scanf()` is vulnerable to buffer overflow, to use `fgets()` instead, as discussed in the article.
 - Remember in C: DON'T FORGET TO CLEAR THAT INPUT BUFFER: [Stack Overflow](https://stackoverflow.com/questions/44943622/getchar-function-to-clear-input-buffer-outside-of-while-condition)

C File Handling:

 - Reference for [C File Handling](https://www.w3schools.blog/c-file-handling) with examples.
 - [C File Handling](https://www.w3schools.in/c-programming/file-handling) examples.
 - [C Files](https://www.w3schools.com/c/c_files.php) from W3 Schools.
 - [C Program to Copy One File to Another File](https://www.sanfoundry.com/c-program-copy-file/)

GDB Debugging:

 - [Harvard CS50 GDB Tutorial](https://www.youtube.com/watch?v=sCtY--xRUyI): A Great Introduction to GDB.
 - [Low Level Learning](https://www.youtube.com/watch?v=Dq8l1_-QgAc): An Excellent GDB Walkthrough Example.
 - [CppCon 2022 Back To Basics](https://www.youtube.com/watch?v=YzIBwqWC6EM): Debugging Strategies and Intro to GDB.
 - [GDB MasterClass](https://www.youtube.com/watch?v=MTkDTjdDP3c) by Mike Shah.
 - [Debugging With GDB](https://sourceware.org/gdb/current/onlinedocs/gdb.html/) 10th Edition HTML Web Reference Manual.
 - [Debugging With GDB](https://sourceware.org/gdb/current/onlinedocs/gdb.pdf) 10th Edition Reference Manual PDF.

## Status:

![GitHub repo size](https://img.shields.io/github/repo-size/ADolbyB/architecture-in-c?label=Repo%20Size&logo=Github)

## GDB Quick Reference (subject to change):

```bash
run                             # Start the program (short: r)
start                           # Synonymous to (b main && run). Puts temporary breakpoint at main()
next                            # Next Line of Code / Step OVER: Goto Next Line & Execute current line (short: n)
nexti                           # Next Instruction: Goto Next Line of ASSEMBLY & Execute current line of ASM.
list                            # List/Print 10 lines of code next to currently executing line of code (short: l)
step                            # Step INTO function call at current line (short: s)
finish                          # Finish the execution of current function (short: fin)
continue                        # Resume execution (After a breakpoint) (short: c)
refresh                         # Repaint the interface (short: ref) Also: Ctrl+l
quit                            # Quit (short: q)
break funcName                  # Set breakpoint at function funcName (short: b funcName)
b file::line                    # Set breakpoint at line in file
delete                          # Delete all breakpoints
delete breakpoint_no            # Delete breakpoint breakpoint_no
disable                         # Disable all breakpoints
make binaryName                 # recompile binaryName (useful to test after 'p var = value' changes)
lay next                        # Cycle through the layouts of gdb
print var                       # Print the value of variable / object var (short: p)
p var = value                   # Force set value to the var (short for print)
ptype expr                      # Detailed print of datatype of expr
info locals                     # Variables in local scope
info variables                  # Variables declared outside current scope
info functions                  # Names and datatypes of all defined functions
info registers                  # View Register Values ar time of crash
info b                          # List all breakpoints
whatis expr                     # Print datatype of expr
backtrace                       # Print backtrace: Call stack history (short 'bt')
shell cmd                       # Run shell command cmd from gdb prompt
python gdb.execute(cmd)         # Run a gdb command cmd from python prompt
set print pretty on             # Enable pretty printing (Put in ~/.gdbinit)
$ gdb -c core.num               # Examine the dumped core file from a SIGSEGV(shell command)
break _exit                     # Breakpoint at exit of program
watch var                       # Stop when var is modified
watch -l foo                    # Watch foo location
rwatch foo                      # Stop when foo is read
watch foo if foo>10             # Watch foo conditionally
command breakpoint_no           # Run user listed commands when breakpoint is hit (End list of commands with 'end')
file executable                 # Load the executable for debugging from inside gdb
info                            # GDB Manual Pages

# Examine Function: Used After Crashes like 'Segmentation Faults'
x/                              # Examine function: used to examine registers and see what address they point to

# different output examples:
x/x $eip                        # examine the value of eip in hexadecimal 
x/o $eip                        # examine the value of eip in octal
x/u $eip                        # examine the value of eip in unsigned base-10 decimal
x/t $eip                        # examine the value of eip in binary
x/i $eip                        # examine the instruction ... and you can choose the size for example:
x/i $pc                         # examine the instruction at the program counter (before the crash)
x/2xb $eip                      # examine first 2 bytes in hexadecimal  
x/1xh $eip                      # gives the same amount of bytes but in one line ('h' stands for half-word which is a short (2 bytes))
x/x $esp                        # examine the value of esp in hexadecimal 
x/o $ebp                        # examine the value of ebp in octal 
x/u $eip                        # examine the value of eip in unsigned decimal Base-10 
x/t $edi                        # examine the value of edi in binary
print $eip                      # will make a variable for it and display the value and address
x/2xw $1                        # Needs Description...

# Number Base / Radix:
o : octal
u : unsigned decimal
t : binary
x : hexadecimal

# Sizes:
g : giant (8 bytes)             # 64-bit word: 8 bits per byte * 8 bytes
w : word (4 bytes)              # 32-bit word: 8 * 4 = 32
dw : double word (4 bytes)      # 32-bit word: 8 * 4 = 32
h : half word (2 bytes)         # 16-bit word: 8 * 2 = 16
b : byte (1 byte)               # 1 byte = 8 bits

# and and by the way gdb uses LITTLE ENDIAN format
# so the bytes will be reversed for example:
x/4xb $eip: 0x7c , 0x4f , 0x45 , 0x64
x/1xw $eip: 0x64454f7c
```