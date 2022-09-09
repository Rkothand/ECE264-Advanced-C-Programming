#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int countWord1(const char * s1, const char * w)
{
  int count = 0;
  while (strstr(s1, w) != NULL)
    {
      count ++;
    }
  return count;
}

int countWord2(const char * s1, const char * w)
{
  int count = 0;
  const char * p1 = s1;
  while (strstr(p1, w) != NULL)
    {
      count ++;
      p1 ++;
    }
  return count;
}

int countWord3(const char * s1, const char * w)
{
  int count = 0;
  const char * p1 = s1;
  while (strstr(p1, w) != NULL)
    {
      count ++;
      p1 += strlen(w);
    }
  return count;
}

int countWord4(const char * s1, const char * w)
{
  int count = 0;
  const char * p1 = s1;
  while (p1 != NULL)
    {
      p1 = strstr(p1, w);
      if (p1 != NULL)
	{
	  count ++;
	  p1 += strlen(w);
	}
    }
  return count;
}

int main(int argc, char * argv[])
{
  char * str = "ECE264 ECECECE Purdue ECECE";
  printf("strlen(str) = %ld\n", strlen(str)); // the answer is 27
  printf("countWord1 = %d\n", countWord1(str, "ECE"));
  printf("countWord2 = %d\n", countWord2(str, "ECE"));
  printf("countWord3 = %d\n", countWord3(str, "ECE"));
  printf("countWord4 = %d\n", countWord4(str, "ECE"));
  return EXIT_SUCCESS;
}
