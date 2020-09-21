#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *disemVStr=disemvowel((char*) "");
  ASSERT_STREQ("", disemVStr);
  free(disemVStr);
}

TEST(Disemvowel, HandleNoVowels) {
  char *disemVStr=disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", disemVStr);
  free(disemVStr);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *disemVStr=disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", disemVStr);
  free(disemVStr);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *disemVStr=disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst",
		      disemVStr);
  free(disemVStr);
}

TEST(Disemvowel, HandlePunctuation) {
  char *disemVStr=disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", 
		      disemVStr);
  free(disemVStr);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char *disemVStr=disemvowel(str);
  ASSERT_STREQ("xyz", disemVStr);
  free(disemVStr);

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
