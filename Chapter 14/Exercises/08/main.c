/*
Suppose we want a macro that expands into a string containing the current line number and
file name. In other words, we'd like to write

const char *str = LINE_FILE;

and have it expand into

const char *str = "Line 10 of file foo.c";

where foo.c is the file containing the program and 10 is the line on which the invocation
of LINE_FILE appears. Warning: This exercise is for experts only. Be sure to read the
Q&A section carefully before attempting!

// Macro to stringize the values of the macro __LINE__
#define STRINGIZE(x) #x

// We need to expand the __LINE__ macro to its integer value first before stringizing it,
//   otherwise STRINGIZE would only convert the macro name __LINE__ to string
#define EXPAND_TO_STRING(x) STRINGIZE(x)

// We can now call EXPAND_TO_STRING on __LINE__ (we do not need to do this with __FILE
// because the __FILE__ macro expands to a string). We could however invoke
// EXPAND_TO_STRING on the __FILE__ macro if we wanted quotes around the filename.

#define LINE_FILE "Line " EXPAND_TO_STRING(__LINE__) " of file " __FILE__
*/