#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  int len, i;
  int n = 0;
  len = strlen(str);
  char *disemVStr;
  disemVStr = (char*) calloc(1, sizeof(char));

  for (i=0; i<len; ++i) {
    if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
    } else {
      disemVStr = (char *) realloc(disemVStr, (n+2)*sizeof(char));
      disemVStr[n] = str[i];
      ++n;
    }
  }

  disemVStr[(n)] = '\0';

  return (char*) disemVStr;

}
