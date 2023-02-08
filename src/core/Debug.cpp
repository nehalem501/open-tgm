/* Debug.cpp */

#ifdef DEBUG

#include <Debug.h>
#include <Position.h>

static void printd_num(const size_t value, const size_t base) {
    char str[32];
    const char* fmt = "0123456789ABCDEF";
    str[31] = '\0';

    int current = 31;
    size_t number = value;
    while (current > 0) {
        current--;
        size_t digit = number % base;
        number = number / base;
        str[current] = fmt[digit];
        if (number == 0)
            break;
    }
    printd_str(str + current);
}

void printd_internal(const char* str) {
    printd_str(str);
}

void printd_internal(const bool value) {
    printd_str(value ? "true" : "false");
}

void printd_internal(void* pointer) {
    printd_str("0x");
    printd_num((size_t) pointer, 16);
}

void printd_internal(const void* pointer) {
    printd_str("0x");
    printd_num((size_t) pointer, 16);
}

void printd_internal(char value) {
    #if CHAR_MIN < 0
    if (value < 0) {
        value = -value;
        printd_str("-");
    }
    #endif

    printd_num((size_t) value, 10);
}

void printd_internal(short value) {
    if (value < 0) {
        value = -value;
        printd_str("-");
    }

    printd_num((size_t) value, 10);
}

void printd_internal(int value) {
    if (value < 0) {
        value = -value;
        printd_str("-");
    }

    printd_num((size_t) value, 10);
}

void printd_internal(long value) {
    if (value < 0) {
        value = -value;
        printd_str("-");
    }

    printd_num((size_t) value, 10);
}

void printd_internal(long long value) {
    if (value < 0) {
        value = -value;
        printd_str("-");
    }

    printd_num((size_t) value, 10);
}

void printd_internal(unsigned char value) {
    printd_num((size_t) value, 10);
}

void printd_internal(unsigned short value) {
    printd_num((size_t) value, 10);
}

void printd_internal(unsigned int value) {
    printd_num((size_t) value, 10);
}

void printd_internal(unsigned long value) {
    printd_num((size_t) value, 10);
}

void printd_internal(unsigned long long value) {
    printd_num((size_t) value, 10);
}

//void printd_internal(int8_t value);
//void printd_internal(uint8_t value);

void printd_internal(const Position& position) {
    printd_internal("Position(x=", position.x, ", y=", position.y, ")");
}

static bool all_categories[(unsigned int) DebugCategory::NB_CATEGORIES] = { true, false /* ... */ };

void printd_set_category_state(DebugCategory category, bool state) {
    all_categories[(unsigned int) category] = state;
}

bool printd_active_category(DebugCategory category) {
    return all_categories[(unsigned int) category];
}

#endif // DEBUG
