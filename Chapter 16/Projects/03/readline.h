#ifndef READLINE_H
#define READLINE_H

/// @brief Skips leading white-space characters, then
///        reads the remainder of the input line and
///        stores it in str. Truncates the line if its
///        length exceeds n.
/// @param str Buffer to read into.
/// @param n Max line length.
/// @return The number of characters stored.
int read_line(char str[], int n);

#endif