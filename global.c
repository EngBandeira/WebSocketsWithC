#include <bits/types.h>

#define LARGE_CONSTANT 100000


__uint8_t
comp (int buffer_id, int keyword_id, int bufferIndex)
{

    if (buffer_id != keyword_id)
        /*->*/ return 0;

    int buffer_sum = buffer_id % LARGE_CONSTANT;
    int buffer_lenght = buffer_id - buffer_sum;

    int keyword_sum = keyword_id % LARGE_CONSTANT;
    int keyword_lenght = keyword_id - keyword_sum;

    if (buffer_lenght != keyword_lenght)
        /*->*/ return 0;

    if (buffer_sum != keyword_sum)
        /*->*/ return 0;

    return 1;
}

__uint32_t
getStringID (char buffer[MAX_IDENTIFIER_LENGTH],int bufferIndex)
{
    __uint32_t id = 0;
    for (__uint8_t x = 0; x < bufferIndex; x++)
        {
            id += ((__uint8_t)buffer[x]);
        }
    id += (bufferIndex * LARGE_CONSTANT);
    return id;
}