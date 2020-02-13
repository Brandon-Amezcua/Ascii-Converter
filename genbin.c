#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genbin.h"

#define BUFLEN 100

char* bin2a (size_t n) {
  static char buf[BUFLEN];
  memset(buf, 0, sizeof(buf));
  size_t idx = 0;

  while (n > 0) {
    buf[idx ++] = '0' + n % 2;
    n /= 10;
  }

  size_t len = strlen(buf);

  for (size_t i; i < 8 - len; ++i) {
    buf[len + i] = '0';
  }
strrev(buf);
  buf[strlen(buf)] = '\0';

  return buf;
}

char* strrev(char* s){
  char* p = s;
  size_t len = strlen(s);
  char* t = s + len - 1;
  len  /= 2;
  while (len-- > 0) {
    swap(s++, t--);
  }

  return p;
}

void swap(char*s, char*t) {
  char temp = *s;
  *s = *t;
  *t = temp;
}
