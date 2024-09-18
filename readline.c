#include "readline.h"
#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *file) {
  size_t buffer_size = 8, str_length = 0;

  char *buffer = malloc(buffer_size);

  while (!feof(file)) {
    buffer[str_length] = fgetc(file);
    str_length++;

    if (buffer[str_length - 1] == '\n') {
      break;
    }


    if (str_length >= buffer_size) {
      buffer_size <<= 1;

      buffer = realloc(buffer, buffer_size);
    }
  }

  buffer[str_length - 1] = '\0';

  return buffer;
}
