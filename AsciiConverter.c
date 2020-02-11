#include <stdio.h>
#include <math.h>
#include <bool.h>

#include "fileread.h"

int convert(char* string[], int size);

int main(int argc, const char* argv[]) {
  const char* names[] = {"NUL", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS",
  "TAB", "LF", "VT", "FF", "CR", "SO", "SI","DLE", "DC1", "DC2", "DC3", "DC4",
  "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US"};

  const char* parity[] = {"Even", "Odd"};

  FILE* fin;
  FILE* fout;
  int n;
  int code;

  char* asc = "01000001";
  int deci = convert(asc);

  /*
  bool ok = openfile(argc, argv, &fin, &fout, n);
  if (!ok) {exit(1);}

  char* s[n];

  while (fgets(s[], n, fin) != EOF) {
    code = convert(s);
  }
  */


  printf("Original\tASCII\tDcimal\t");
  printf("%s\t%c\t%\t%d\t%s",);


}


int convert(char* string[]) {
  int j = 0;
  int decimal = 0;
  int size = strlen(string);
  while(size-- >= 0) {
    int i = (string[size] - '0') * pow(2, size);
    decimal += i;
  }
  return decimal;
}
