#include "./parser/read.h"

int	read_double(double *num, char *word)
{
	 if (!word || !*word || !num) {
        return (1);  // Error: null or empty string
    }
    const char *ptr = word;
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
    double result = 0.0;
    // Parse integer part
    while (*ptr >= '0' && *ptr <= '9') {
        result = result * 10.0 + (*ptr - '0');
        ptr++;
    }
    // Parse fractional part if '.'
    if (*ptr == '.') {
        ptr++;
        double frac = 0.0;
        double div = 1.0;
        while (*ptr >= '0' && *ptr <= '9') {
            frac = frac * 10.0 + (*ptr - '0');
            div *= 10.0;
            ptr++;
        }
        result += frac / div;
    }
    // Ensure end of string (no exponent or extra chars)
    if (*ptr != '\0') {
        return (1);
    }
    *num = sign * result;
	return (0);
}
