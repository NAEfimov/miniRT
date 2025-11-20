#include "./parser/read.h"

int	read_int(int *num, char *word)
{
	 if (!word || !*word || !num) {
        return (1);  // Error: null or empty string
    }
    char *ptr = word;
    int sign = 1;
    // Handle sign
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    } else if (*ptr == '+') {
        ptr++;
    }
    // Must have at least one digit
    if (*ptr < '0' || *ptr > '9') {
        return (1);
    }
    int result = 0;
    // Parse digits
    while (*ptr >= '0' && *ptr <= '9') {
        result = result * 10 + (*ptr - '0');
        ptr++;
        // Basic overflow check (optional, for int range)
        if (result < 0) {  // Overflow occurred
            return (1);
        }
    }
    // Ensure end of string
    if (*ptr != '\0') {
        return (1);
    }
    *num = sign * result;
    return (0);
}
