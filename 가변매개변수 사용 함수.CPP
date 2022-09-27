#include <iostream>
#include <cstring>
#include <cstdarg>

#define STR_LEN_MAX 512
void TRACE(const char* strFormat, ...)
{
#ifdef _DEBUG
    static char char_tmp[STR_LEN_MAX];
    memset(char_tmp, 0x00, STR_LEN_MAX);
    va_list ap;
    va_start(ap, strFormat);
    vsnprintf(char_tmp, STR_LEN_MAX, strFormat, ap);
    va_end(ap);
    std::cout << char_tmp;
#endif
}

int main()
{
    for (size_t i = 0; i < 10; i++ )
        TRACE("index : %d, %d\n", i, i*i);

    return EXIT_SUCCESS;
}