#ifndef GLOBAL_H
#define GLOBAL_H

#define HALT 0x02D3012A
#define UNKNOWN_ERROR 0x18AF03D0
#include <stdio.h>
#define IRREPARABLE_MEMORY_ERROR \
fprintf(stderr, "Irreparable memory allocation error!"); \
exit(1)
#endif