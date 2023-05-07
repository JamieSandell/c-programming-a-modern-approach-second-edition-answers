/*
Write the following function:

void split_date(int day_of_year, int year,
                int *month, int *day);

day_of_year is an integer between 1 and 366, specifying a particular day within the year
designated by year. month and day point to variables in which the function will store the
equivalent month (1-12) and day within that month (1-31).

void split_date(int day_of_year, int year, int *month, int *day)
{
    bool found_month = false;

    // find the month
    for (int i = 1; i <= 12 && !found_month; i++)
    {
        switch (i)
        {
            case 1: // fall-through
            case 3: // fall-through
            case 5: // fall-through
            case 7: // fall-through
            case 8: // fall-through
            case 10: // fall-through
            case 12:
            {
                if (day_of_year <= 31)
                {
                    found_month = true;
                }
                else
                {
                    day_of_year -=31;
                }

                break;
            }
            case 4: // fall-through
            case 6: // fall-through
            case 9: // fall-through
            case 11:
            {
                if (day_of_year <= 30)
                {
                    found_month = true;
                }
                else
                {
                    day_of_year -= 30;
                }

                break;
            }
            case 2:
            {
                if (year % 4 == 0) // leap year
                {
                    if (day_of_year <= 29)
                    {
                        found_month = true;
                    }
                    else
                    {
                        day_of_year -=29;
                    }
                }
                else if(day_of_year <= 28)
                {
                    found_month = true;
                }
                else
                {
                    day_of_year -= 28;
                }

                break;
            }
            default:
            {
                printf("Error, unhandled switch case.\n");
                return exit(ERROR_FAILURE);
            }
        }
    }

    *month = i - 1;
    *day = day_of_year;
}
*/