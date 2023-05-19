/*
What will be the value of the string s1 after the following statements have been executed?

strcpy(s1, "computer");
strcpy(s2, "science");
if (strcmp(s1, s2) < 0)
    strcat(s1, s2);
else
    strcat(s2, s1);
s1[strlen(s1)-6] = '\0';

After the first line, s1 = "computer\0".
After the second line, s2 = "science\0".
After the if/else, s1 = "computerscience\0".
After the last line, s1 = "computers\0".
*/