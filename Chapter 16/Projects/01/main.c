/*
Write a program that asks the user to enter an international dialing code and then looks it up
in the country_codes array (see Section 16.3). If it finds the code, the program should
display the name of the corresponding country; if not, the program should print an error
message.
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(x) ((int) (sizeof((x)) / sizeof((x)[0])))

const struct
{
    char *country;
    int code;
} country_codes[] =
{
    {"Argentina",            54}, {"Bangladesh",     889},
    {"Brazil",               55}, {"Burma (Myanmar)", 95},
    {"China",                86}, {"Colombia",        57},
    {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
    {"Ethiopia",            251}, {"France",          33},
    {"Germany",              49}, {"India",           91},
    {"Indonesia",            62}, {"Iran",            98},
    {"Italy",                39}, {"Japan",           81},
    {"Mexico",               52}, {"Nigeria",        234},
    {"Pakistan",             92}, {"Philippines",     63},
    {"Poland",               48}, {"Russia",           7},
    {"South Africa",         27}, {"South Korea",     82},
    {"Spain",                34}, {"Sudan",          249},
    {"Thailand",             66}, {"Turkey",          90},
    {"Ukraine",             380}, {"United Kingdom",  44},
    {"United States",         1}, {"Vietnam",         84}
};

int main(void)
{
    int code;

    printf("Enter a dialling code to lookup: ");
    scanf("%d", &code);

    int country_codes_len = ARRAY_LEN(country_codes);
    for (int i = 0; i < country_codes_len; ++i)
    {
        if (country_codes[i].code == code)
        {
            printf("Dialling code %d is for %s\n", code, country_codes[i].country);
            return EXIT_SUCCESS;
        }
    }

    printf("Error: %d is not a valid dialling code\n", code);
    return EXIT_FAILURE;
}