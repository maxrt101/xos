#include <divmod.h>
#include <math.h>

// typedef struct divmod_result_t {
//   uint32_t quotient;
//   uint32_t remainder;
// } divmod_result_t;

// Signed 64-bit division with remainder
divmod_result_t ldivmod(int64_t numerator, int64_t denominator) {
  divmod_result_t result;

    if (denominator == 0) {
        // Handle division by zero error
        result.quotient = -1U;
        result.remainder = -1U;
        return result;
    }

    int64_t sign = (numerator < 0) ^ (denominator < 0) ? -1 : 1;
    numerator = abs(numerator);
    denominator = abs(denominator);

    result.quotient = 0;
    result.remainder = 0;

    for (int i = 63; i >= 0; i--) {
        result.remainder <<= 1;
        result.quotient <<= 1;

        if ((numerator >> i) & 1) {
            result.remainder |= 1;
        }

        if (result.remainder >= denominator) {
            result.remainder -= denominator;
            result.quotient |= 1;
        }
    }

    result.quotient *= sign;
    result.remainder *= sign;

    return result;
}

// Unsigned 64-bit division with remainder
divmod_result_t uldivmod(uint64_t numerator, uint64_t denominator) {
  divmod_result_t result;

    if (denominator == 0) {
        // Handle division by zero error
        result.quotient = -1U;
        result.remainder = -1U;
        return result;
    }

    result.quotient = 0;
    result.remainder = 0;

    for (int i = 63; i >= 0; i--) {
        result.remainder <<= 1;
        result.quotient <<= 1;

        if ((numerator >> i) & 1) {
            result.remainder |= 1;
        }

        if (result.remainder >= denominator) {
            result.remainder -= denominator;
            result.quotient |= 1;
        }
    }

    return result;
}
