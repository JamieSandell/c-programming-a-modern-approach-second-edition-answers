/*
Only one of the expressions ++i and i++ is exactly the same as (i += 1): which is it?
Justify your answer.

++i because they both immediately modify i and evaluate as the modified value.

i++ evaluates i before it's modified and then modifies i after that statement (but before the next one).
*/