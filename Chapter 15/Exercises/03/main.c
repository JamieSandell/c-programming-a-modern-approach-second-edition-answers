/*
We saw that writing #include <file> instead of #include "file" may not work if file is
one that we've written. Would there by any problem with writing #inlude "file" instead
of #include <file> if file is a system header?

Potentially. As the user defined header file would overwrite the system header for that program.
If that's desired that's fine, but it can have undesirable consequences such as redefining functions and macros.
*/