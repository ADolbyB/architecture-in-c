<div align=center>

# Computer Architecture in C

[![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=C&logoColor=white)](https://en.cppreference.com/w/c)
[![UNIX](https://img.shields.io/badge/UNIX-0078D6?style=for-the-badge)](https://www.opengroup.org/membership/forums/platform/unix)
[![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.linux.org/)
[![License](https://img.shields.io/github/license/ADolbyB/architecture-in-c?label=License&style=for-the-badge)](https://github.com/ADolbyB/architecture-in-c/blob/main/LICENSE.md)
[![GitHub repo size](https://img.shields.io/github/repo-size/ADolbyB/architecture-in-c?label=Repo%20Size&logo=Github&style=for-the-badge)](https://github.com/ADolbyB/architecture-in-c)

</div>

A collection of code, lecture notes, and lab work from a **Computer Architecture** hardware and applications class. This repo covers Unix process management in C, x86_64 assembly fundamentals, low-level memory concepts, file I/O, and debugging with GDB — all grounded in the classic systems programming curriculum.

## Course Overview

A major topic in this course is [**Unix Processes in C**](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY), for which a full YouTube tutorial playlist is linked.

The primary textbook for this course is [**Computer Systems: A Programmer's Perspective, 3/E**](http://csapp.cs.cmu.edu/) — all programming assignments use the C language.

## Repository Structure

```
architecture-in-c/
├── Examples/       # Standalone C code examples for key concepts
├── Labs/           # Lab assignments and solutions
├── Lectures/       # Code written alongside lecture material
├── .gitattributes
├── .gitignore
└── README.md       # This file
```

## Other Textbook Resources

Another excellent reference for Computer Architecture is [**Structured Computer Organization**](https://www.pearson.com/en-us/subject-catalog/p/structured-computer-organization/P200000003183/9780137618446) — this book focuses more on hardware concepts and does not include C programming assignments.

## C Language Reference

### Printf / Scanf Placeholders

- [C Language Placeholders](https://en.m.wikibooks.org/wiki/C_Programming/Simple_input_and_output) — list and usage examples
- ⚠️ Remember: `scanf()` is vulnerable to buffer overflow — use `fgets()` instead, as discussed in the article above
- ⚠️ Remember in C: **DON'T FORGET TO CLEAR THE INPUT BUFFER**: [Stack Overflow Reference](https://stackoverflow.com/questions/44943622/getchar-function-to-clear-input-buffer-outside-of-while-condition)

### File Handling

- [C File Handling](https://www.w3schools.blog/c-file-handling) — reference with examples
- [C File Handling Examples](https://www.w3schools.in/c-programming/file-handling)
- [C Files](https://www.w3schools.com/c/c_files.php) — from W3 Schools
- [C Program to Copy One File to Another File](https://www.sanfoundry.com/c-program-copy-file/)

## x86_64 Architecture Reference

- [x86_64 Reference Sheet](https://web.stanford.edu/class/cs107/resources/x86-64-reference.pdf) — Stanford (x86-64 is the target architecture for this course)
- [X86_64 Register and Instruction Quick Start](https://wiki.cdot.senecacollege.ca/wiki/X86_64_Register_and_Instruction_Quick_Start) — Seneca College Wiki
- [x86 Assembly / X86 Architecture](https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture) — Wikibooks

## GDB Debugging Resources

### Tutorials & Videos

- [Harvard CS50 GDB Tutorial](https://www.youtube.com/watch?v=sCtY--xRUyI) — a great introduction to GDB
- [Low Level Learning](https://www.youtube.com/watch?v=Dq8l1_-QgAc) — an excellent GDB walkthrough example
- [CppCon 2022 Back To Basics](https://www.youtube.com/watch?v=YzIBwqWC6EM) — Debugging Strategies and Intro to GDB
- [GDB MasterClass](https://www.youtube.com/watch?v=MTkDTjdDP3c) by Mike Shah
- [GDB Quick Reference Guide](https://beej.us/guide/bggdb/#qref) by Beej
- [Debugging With GDB](https://sourceware.org/gdb/current/onlinedocs/gdb.html/) — 10th Edition HTML Web Reference Manual
- [Debugging With GDB](https://sourceware.org/gdb/current/onlinedocs/gdb.pdf) — 10th Edition Reference Manual PDF

### GDB Quick Reference

A comprehensive GDB command reference used throughout this course (subject to change):

```bash
# ── Manual Pages ─────────────────────────────────────────────────────────────
info                                    # GDB Manual Pages

# ── Program Execution ────────────────────────────────────────────────────────
run                                     # (short: r) Start the program
start                                   # Synonymous to (b main && run). Puts temporary breakpoint at main()
next                                    # (short: n) Next Line of Code / Step OVER: Goto Next Line & Execute current line
nexti                                   # Next Instruction: Goto Next Line of ASSEMBLY & Execute current line of ASM.
step                                    # (short: s) Step INTO function call at current line
stepi                                   # Step a single assembly instruction
finish                                  # (short: fin) Finish the execution of current function
continue                                # (short: c) Resume execution (After a breakpoint)
refresh # (short: ref or Ctrl+l)        # Repaint the interface
quit                                    # (short: q) Quit

# ── Code Listing ─────────────────────────────────────────────────────────────
list                                    # (short: l) List/Print 10 lines of code next to currently executing line of code

# ── Breakpoints ──────────────────────────────────────────────────────────────
break funcName                          # (short: b funcName) Set breakpoint at function funcName
b file::line                            # Set breakpoint at line in file
delete                                  # Delete all breakpoints
delete breakpoint_no                    # Delete breakpoint breakpoint_no
disable                                 # Disable all breakpoints
break _exit                             # Breakpoint at exit of program
info b                                  # List all breakpoints
command breakpoint_no                   # Run user listed commands when breakpoint is hit (End commands with 'end')

# ── Watchpoints ──────────────────────────────────────────────────────────────
watch var                               # Stop when var is modified
watch -l foo                            # Watch foo location
rwatch foo                              # Stop when foo is read
watch foo if foo>10                     # Watch foo conditionally

# ── Variables & Types ────────────────────────────────────────────────────────
print var                               # (short: p) Print the value of variable / object var
p var = value                           # Force set value to the var (short for print)
set variable expression                 # Set a variable to value, e.g. `set variable x=20`
set (expression)                        # Works like set variable
ptype expr                              # Detailed print of datatype of expr
whatis expr                             # Print datatype of expr
info locals                             # Variables in local scope
info variables                          # Variables declared outside current scope
info functions                          # Names and datatypes of all defined functions

# ── Registers ────────────────────────────────────────────────────────────────
info registers                          # Dump integer registers / View Register Values at time of crash
info all-registers                      # Dump all registers to screen

# ── Stack & Call History ─────────────────────────────────────────────────────
backtrace                               # (short: bt) Print backtrace: Call stack history
where                                   # Same as backtrace

# ── TUI / Layout ─────────────────────────────────────────────────────────────
refresh                                 # (short: ref or Ctrl+l) Repaint the interface
layout type                             # Set the window layout ("src", "asm", "split", or "reg")
tui reg type                            # Set the register window layout ("general", "float", "system", or "next")
lay next                                # Cycle through the layouts of gdb
tui disable                             # Disable TUI display mode
tui enable                              # Enable TUI display mode
tui reg                                 # TUI command to control the register window

# ── Misc ─────────────────────────────────────────────────────────────────────
make binaryName                         # Recompile binaryName (useful to test after 'p var = value' changes)
shell cmd                               # Run shell command cmd from gdb prompt
python gdb.execute(cmd)                 # Run a gdb command cmd from python prompt
set print pretty on                     # Enable pretty printing (Put in ~/.gdbinit)
file executable                         # Load the executable for debugging from inside gdb
info                                    # GDB Manual Pages
$ gdb -c core.num                       # Examine the dumped core file from a SIGSEGV (shell command)

# ── Examine Function: Used After Crashes like 'Segmentation Faults' ──────────
x/nfu addr                              # General examine: n=count, f=format, u=unit size
x addr                                  # Examine memory at addr
x/                                      # Examine function: used to examine registers and see what address they point to

# ── Output format examples ───────────────────────────────────────────────────
x/x $eip                                # examine the value of eip in hexadecimal
x/o $eip                                # examine the value of eip in octal
x/u $eip                                # examine the value of eip in unsigned base-10 decimal
x/t $eip                                # examine the value of eip in binary
x/i $eip                                # examine the instruction
x/i $pc                                 # examine the instruction at the program counter (before the crash)
x/2xb $eip                              # examine first 2 bytes in hexadecimal for address eip
x/1xh $eip                              # gives the same amount of bytes but in one line ('h' = half-word = short = 2 bytes)
x/x $esp                                # examine the value of esp in hexadecimal
x/o $ebp                                # examine the value of ebp in octal
x/u $eip                                # examine the value of eip in unsigned decimal Base-10
x/t $edi                                # examine the value of edi in binary
print $eip                              # will make a variable for it and display the value and address
x/2xw $1                                # examine first 2 words in hexadecimal for address 1

# ── Number Base / Radix ──────────────────────────────────────────────────────
o : octal
u : unsigned decimal
t : binary
x : hexadecimal

# ── Unit Sizes ───────────────────────────────────────────────────────────────
g : giant     (8 bytes)                 # 64-bit word: 8 bits per byte * 8 bytes
w : word      (4 bytes)                 # 32-bit word: 8 * 4 = 32
dw : dword    (4 bytes)                 # 32-bit word: 8 * 4 = 32
h : half-word (2 bytes)                 # 16-bit word: 8 * 2 = 16
b : byte      (1 byte)                  # 1 byte = 8 bits

# ── NOTE: GDB uses LITTLE ENDIAN format — bytes are reversed, for example:
x/4xb $eip: 0x7c , 0x4f , 0x45 , 0x64
x/1xw $eip: 0x64454f7c
```
---

### Topics

`c` `c-programming` `architecture` `computer-hardware` `gdb` `gdb-commands` `debugging` `x86-64` `unix` `systems-programming`