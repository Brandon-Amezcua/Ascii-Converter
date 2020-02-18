#include <stdio.h>
#include <math.h>
#include <string.h>
//#include <bool.h>

#include "fileread.h"
#include "genbin.h"

int convert(const char* string);

int main(int argc, const char* argv[]) {

  const char* names[] = {"NUL", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS",
  "TAB", "LF", "VT", "FF", "CR", "SO", "SI","DLE", "DC1", "DC2", "DC3", "DC4",
  "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US"};

  const char* parity[] = {"Even", "Odd"};

  FILE* fin;
  FILE* fout;
  int n;
  char* code;

  char* asc = "01000001";
  int deci;
  char* nxt = "01000010";

  bool ok = openfile(argc, argv, &fin, &fout, n);
  if (!ok) {exit(1);}

  char* s[n];
  printf("Original\tASCII\tDcimal\tParity \n");

  while (fgets(s[], n, fin) != EOF) {
    code = convert(s);
    deci = convert(code) % 2;
    printf("%s\t%c\t%d\t%s\n", asc, convert(code), convert(code), parity[deci]);
  }



  printf("Original\tASCII\tDcimal\tParity \n");
  deci = convert(asc) % 2;
  printf("%s\t%c\t%d\t%s\n", asc, convert(asc), convert(asc), parity[deci]);
  deci = convert(nxt) % 2;
  printf("%s\t%c\t%d\t%s\n", nxt, convert(nxt), convert(nxt), parity[deci]);


  printf("%s is %d and %c\n", asc, convert(asc), convert(asc));

  printf("%s is %d and %c\n", nxt, convert(nxt), convert(nxt));


}


int convert(const char* string) {
  int j = 0;
  int decimal = 0;
  int size = strlen(string);
  while(size-- > 0) {
    int i = (string[size] - '0') * pow(2, j);
    decimal += i;
    j++;
  }
  return decimal;
}
