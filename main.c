/*
** main.c for  in /home/gaonac_l/rendu/asm_minilibc
**
** Made by
** Login   <gaonac_l@epitech.net>
**
** Started on  Mon Mar  7 22:38:13 2016
** Last update Sun Mar 27 18:38:26 2016 
*/

#include <stdio.h>
#include <string.h>
/* #include <stdlib.h> */

/* extern int strlen(char *); */
/* extern char *rindex(char *, int); */
/* extern char *memmove(char *, char *, int); */
/* extern char *strchr(char *, int); */
/* extern void *memset(void *, int, size_t); */
/* extern void *memcpy(void *, void *, size_t); */
/* extern int strcmp(char *, char *); */
/* extern int strcasecmp(const char *, const char *); */
/* extern char *strstr(char *,char *); */
/* extern char *strpbrk(char *,char *); */
/* extern size_t strcspn(char *, char*); */
/* extern int strncmp(char *, char *, size_t); */

void cases(const char *s1, const char *s2)
{
  printf("strcasecmp = %d\n", strcasecmp(s1, s2));
}

/* void cases2(const char *s1, const char *s2) */
/* { */
/*   printf("strcasecmp = %d\n", strcasecmp(s1, s2)); */
/* } */

int	main(int ac, char **av)
{
  char s1[] = "memmove can be very useful......";
  /* char s2[] = "memmove can be very useful......"; */

  printf("%s\n", memmove(s1+20, s1+15, 11));
  printf("s1 = %s\n", s1);
  printf("rindex = %s\n", rindex(av[2], 'c'));
  printf("strlen = %i\n", strlen(av[1]));
  printf("strchr = %s\n", strchr(av[1], 't'));
  printf("memset = %s\n", memset(s1, 'a', 10));
  printf("memcpy = %s\n", memcpy(s1, av[1], 5));
  printf("strcasecmp2 = %d\n", strcasecmp(av[1], av[2]));
  printf("strcmp = %d\n", strcmp(av[1], av[2]));
  printf("strstr = %s\n", strstr(av[1], av[2]));
  printf("strpbrk = %s\n", strpbrk(av[1], av[2]));
  printf("strcspn = %d\n", strcspn(av[1], av[2]));
  printf("strncmp = %d\n", strncmp(av[1], av[2], 10));

  /* printf("\n\n"); */

  /*   printf("%s\n", memmove(s2+20, s2+15, 11)); */
  /*   printf("s2 = %s\n", s2); */
  /*   printf("rindex = %s\n", rindex(av[2], 'c')); */
  /*   printf("strlen = %i\n", strlen(av[1])); */
  /*   printf("strchr = %s\n", strchr(av[1], 't')); */
  /*   printf("memset = %s\n", memset(s1, 'a', 10)); */
  /*   printf("memcpy = %s\n", memcpy(s1, av[1], 5)); */
  /*   printf("strcmp = %d\n", strcmp(av[1], av[2])); */
  /*   cases2(av[1], av[2]); */
  /*   printf("strstr = %s\n", strstr(av[1], av[2])); */
  /*   printf("strpbrk = %s\n", strpbrk(av[1], &c)); */
  /*   printf("strcspn = %d\n", strcspn(av[1], av[2])); */
  /*   printf("strncmp = %d\n", strncmp(av[1], av[2], 10)); */
  return (0);
}
