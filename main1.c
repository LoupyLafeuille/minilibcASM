/*
** main.c for  in /home/engueh_a/rendu/ASM/asm_minilibc
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Tue Mar 08 01:50:11 2016 Galilee Enguehard
** Last update Sat Mar 26 23:20:37 2016 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* extern int		strcasecmpp(const char *s1, const char *s2); */

int		test_strlen(void);
int		test_memset(void);
int		test_memmove(void);
int		test_memcpy(void);
int		test_strchr(void);
int		test_strcmp(void);
int		test_strncmp(void);
int		test_strcasecmp(void);
int		test_rindex(void);
int		test_strpbrk(void);
int		test_strcspn(void);
int		test_strstr(void);

int		main()
{
  printf("---\tTest strlen\t---\n");
  test_strlen();
  //------------------------------------------------------------------------------
  printf("\n---\tTest memset\t---\n");
  test_memset();
  //------------------------------------------------------------------------------
  printf("\n---\tTest memcpy\t---\n");
  test_memcpy();
  //------------------------------------------------------------------------------
  printf("\n---\tTest memmove\t---\n");
  test_memmove();
  //------------------------------------------------------------------------------
  printf("\n---\tTest strchr\t---\n");
  test_strchr();
  //------------------------------------------------------------------------------
  printf("\n---\tTest strcmp\t---\n");
  test_strcmp();
  //------------------------------------------------------------------------------
  printf("\n---\tTest strncmp\t---\n");
  test_strncmp();
  //------------------------------------------------------------------------------
  printf("\n---\tTest strcasecmp\t---\n");
  test_strcasecmp();
  //------------------------------------------------------------------------------
  printf("\n---\tTest rindex\t---\n");
  test_rindex();
  //------------------------------------------------------------------------------
  printf("\n---\tTest strpbrk\t---\n");
  test_strpbrk();
  //------------------------------------------------------------------------------
  printf("\n---\tTest strcspn\t---\n");
  test_strcspn();
  //------------------------------------------------------------------------------
  printf("\n---\tTest strstr\t---\n");
  test_strstr();
  return (0);
}

int		test_strlen()
{
  printf("Taille de \"BonjourMonsieurLePoisson\"(chaine en dur) :%d\n",
	 strlen("BonjourMonsieurLePoisson"));
  char		*PoissonHorsDeLeau = strdup("LePoissonHorsDeLeauSuffoque");
  printf("Taille de \"LePoissonHorsDeLeauSuffoque\"(malloc) :%d\n",
	 strlen(PoissonHorsDeLeau));
  free (PoissonHorsDeLeau);
  return (0);
}

int		test_memset()
{
  char		tab[30];
  int		i = 0;

  while (i < 30)
    tab[i++] = 'a';

  printf("tab => %s\n", tab);
  printf("Filling the char array (but one) with 0, then filling 15 slots with 1\n");
  memset(tab, '0', 28);
  memset(tab, '1', 15);
  tab[29] = '\0';
  printf("output => %s\n", tab);
  printf("Filling a malloc'ed int array with 10s\n");
  int		*int_tab = malloc(sizeof(int) * 30);
  i = 0;
  while (i < 30)
    int_tab[i++] = 10;
  i = 0;
  printf("int_tab => ");
  while (i < 30)
    printf("%d\\", int_tab[i++]);
  printf("\n");
  return (0);
}

int		test_strchr()
{
  const char	*Poisson = "BonjourMonsieurLePoisson";
  char		*PoissonHorsDeLeau = strdup("LePoissonHorsDeLeauSuffoque");

  printf("strchr(Poisson, L) : %s\n", strchr(Poisson, (int)'L'));
  printf("strchr(PoissonHorsDeLeau, D) : %s\n", strchr(PoissonHorsDeLeau, (int)'D'));
  printf("strchr(Bite, Z) : %p\n", strchr("Bite", (int)'Z'));
  printf("strchr(Poisson, \\0) : %s\n", strchr(Poisson, (int)'\0'));
  free (PoissonHorsDeLeau);
  return (0);
}

int		test_memcpy()
{
  char		tab[40] = {'B','o','n','j','o','u','r','M','o','n','s','i','e',
			   'u','r','l','e','p','o','i','s','s','o','n',0};
  char		dest[40];
  char		*ret = malloc(sizeof(char) * 41);
  const char	*bite = strdup("Nique bien ta mere.");

  memset(dest, 0, 40);
  printf("START : src : %s\ndest : %s\n", tab, dest);
  ret = memcpy(dest, tab, 40);
  printf("END : src : %s\ndest : %s\n", tab, dest);
  printf("ret : %s\n", ret);
  memcpy(ret, bite, 10);
  printf("ret : %s\n", ret);
  return (0);
}

int		test_strcmp()
{
  printf("BMLP, Poisson : %d\n", strcmp("BonjourMonsieurLePoisson", "Poisson"));
  printf("Wesh, Wesh : %d\n", strcmp("Wesh", "Wesh"));
  printf("Yo, BonneJournee : %d\n", strcmp("Yo", "BonneJournee"));
  printf("\"\", \"\" : %d\n", strcmp("", ""));
  return (0);
}

int		test_strncmp()
{
  printf("BMLP, Poisson, 3 : %d\n", strncmp("BonjourMonsieurLePoisson", "Poisson",3));
  printf("Wesh, Wesh, 7 : %d\n", strncmp("Wesh", "Wesh", 7));
  printf("Yo, BonneJournee, 2 : %d\n", strncmp("Yo", "BonneJournee", 2));
  printf("\"\", \"\" : %d\n", strncmp("", "", 2));
  return (0);
}

int		test_strcasecmp()
{
  printf("Bonjour, BMLP: %d\n", strcasecmp("Bonjour", "BonjourMonsieurLePoisson"));
  printf("BMLP, Poisson : %d\n", strcasecmp("BonjourMonsieurLePoisson", "Poisson"));
  printf("Wesh, Wesh : %d\n", strcasecmp("Wesh", "Wesh"));
  printf("Yo, BonneJournee : %d\n", strcasecmp("Yo", "BonneJournee"));
  printf("\"\", \"\" : %d\n", strcasecmp("", ""));
  return (0);
}

int		test_rindex()
{
  const char	*str = strdup("Inchlalane");

  printf("rindex(\"Inchlalane\"), \'a\' : %s\n", rindex(str, 'a'));
  printf("rindex(\"\", \'a\') : %s\n", rindex("", 'a'));
  printf("rindex(\"BonjourMonsieurLePoisson\", \'z\') : %s\n", rindex("BonjourMonsieurLePoisson", 'z'));
  printf("rindex(\"Inchlalane\"), \'\\0\' : %s\n", rindex(str, '\0'));
  return (0);
}

int		test_strpbrk()
{
  char		c = 's';

  printf("strpbrk(\"Fils de pute basique\",\"&c (s)\") : %s\n", strpbrk("Fils de pute basique", &c));
  printf("strpbrk(\"\",\"\") : %s\n", strpbrk("", ""));
  printf("strpbrk(\"BonjourMonsieurLePoisson\",\"zxyam\") : %s\n", strpbrk("BonjourMonsieurLePoisson", "zxyam"));
  printf("strpbrk(\"Yoy\", \"yo\") : %s\n", strpbrk("Yoy","yo"));
  return (0);
}

int		test_strcspn()
{
  char		*s1 = strdup("groscul");

  printf("strcspn(\"groscul\", \"luc\") : %d\n", strcspn(s1, "luc"));
  printf("strcspn(\"groscul\", \"z\") : %d\n", strcspn(s1, "z"));
  printf("strcspn(\"\", \"\") : %d\n", strcspn("", ""));
  free(s1);
  return (0);
}

int		test_strstr()
{
  char		*s1 = strdup("needle");

  printf("strstr(\"needle in a haystack\", \"needle\") : %s\n", strstr("needle in a haystack", s1));
  printf("strstr(\"need a needy needlegfhn \", \"needle\") : %s\n", strstr("need a needy needlejksdfhsdf", s1));
  printf("strstr(\"zob\", \"needle\") : %s\n", strstr("zob", s1));
  printf("strstr(\"zob\", \"zob\") : %s\n", strstr("zob", "zob"));
  printf("strstr(\"\", \"\") : %s\n", strstr("", ""));
  free(s1);
  return (0);
}

int		test_memmove()
{
  char		tab1[60];
  char		tab2[30];

  memset(tab1, 'a', 60);
  tab1[59] = 0;
  memset(tab2, 'z', 30);
  tab2[29] = 0;
  printf("tab1 : %s\ntab2 : %s\n", tab1, tab2);
  memmove(&tab1[29], tab2, 30);
  printf("after memmove :\n tab1 : %s\ntab2 : %s\n", tab1, tab2);
  printf("Copying to addresses that overlap\n");

  char		*overlap = malloc(sizeof(char) * 100);
  memset(overlap, '9', 29);
  memset(&overlap[29], '7', 30);
  memset(&overlap[58], '5', 30);
  overlap[99] = 0;
  printf("overlap : %s\n", overlap);
  memmove(&overlap[9], overlap, 40);
  printf("after memmove :\noverlap : %s\n", overlap);

  printf("memove(zob, vide) %s\n", memmove(overlap, "", 30));
  free (overlap);
  return (0);
}
