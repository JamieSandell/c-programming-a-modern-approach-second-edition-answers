/*
What will be the value of the string str after the following statements have been executed?

strcpy(str, "tire-bouchon");
strcpy(&str[4], "d-or-wi");
strcat(str, "red?");

After the first line, str = "tire-bouchon\0".
After the second line, str = "tired-or-wi\0".
After the third line, str = "tired-or-wired?\0".
*/