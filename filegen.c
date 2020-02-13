#include <stdio.h>

#include "fileread.h"
#include "genbin.h"

#define UPTO 127

int main(int argc, const char* argv[]) {
  FILE* fin;
  FILE* fout;
  int n;

  bool ok = openfiles(argc, argv, &fin, &fout, &n);
  if (!ok) {exit(1);}

  char* bi;

  for(size_t i = 0; i <= UPTO; i++) {
    bi = bin2a(i);
    fputs(bi, fout);
    if ((i % 8) == 0){
      fputc('\n', fout);
    } else {
      fputc('\t', fout);
    }
  }

  closefiles(fin, fout);

  return 0;
}
