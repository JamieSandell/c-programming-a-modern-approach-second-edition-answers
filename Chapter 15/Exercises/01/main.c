/*
Section 15.1 listed several advantages of dividing a program into multiple source files.

(a) Describe several other advantages.
(b) Describe some disadvantages.

(a)
Information hiding, clutter removal. Only necessary functions would be included in a project source file's header file, and only those necessary functions would be available.

Compilation, testing and debugging would be simpler. Only necessary compilations would take place rather than compiling everything, testing unneccessary things.

File size. Many small files are easier to manipulate over one large, memory consuming file.

(b)
Complexity. Smaller programs split into multiple files can cause unnecessary confusion.

Incorrect seperation of information. Programs could potentially be split in a chaotic way, making a program confusing to read, debug and test.

File count. At a certain point, managing a large list of small files can be more confusing to compile, link and remain consistent with the program's original philosophy.
*/