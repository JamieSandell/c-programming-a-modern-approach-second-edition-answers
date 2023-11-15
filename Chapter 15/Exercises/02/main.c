/*
Which of the following should not be put into a header file? Why not?

(a) Function prototypes
(b) Function definitions
(c) Macro definitions
(d) Type definitions

(b)
You shouldn't define any functions in a header file, only declare their prototypes. If a
function is defined within a header file, then any source file that includes the header file
will need to compile that function. This would cause the function to be compiled multiple times
instead of once if it was listed in a source file. Compiling the same function multiple times
will cause an error at the linking stage, because a linker only expects each function to be 
defined once.
*/