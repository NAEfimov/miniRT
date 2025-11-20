#include "./parser/read.h"

int	read_uint8(uint8_t *num, char *word)
{
	int sign = 1;
	char *ptr = word;
	int result = 0;
	
	if (!word || !*word || !num) {
        return (1);  // Error: null or empty string
    }
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
    result *= sign;
	if (result < 0 || result > 255)
		return (1);
	*num = (uint8_t)result;
    return (0);
}
