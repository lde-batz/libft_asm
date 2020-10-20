#include "libfts.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#define FILE_TEST	"Makefile"

void		test_strlen(void)
{
	size_t	c;

	c = 0;
	printf("*************** FT_STRLEN ***************\n");
	char	str_len[100] = "";
	if (ft_strlen(str_len) != strlen(str_len))
	{
		printf("ft_strlen error1:  %zu   |   %lu\n", ft_strlen(str_len), strlen(str_len));
		c++;
	}
	char	str_len1[100] = "Hello world !";
	if (ft_strlen(str_len1) != strlen(str_len1))
	{
		printf("ft_strlen error2:  %zu   |   %lu\n", ft_strlen(str_len1), strlen(str_len1));
		c++;
	}
	char	str_len2[100] = "Hello worldidjhgdfhdjfkljgfherkjfhe !";
	if (ft_strlen(str_len2) != strlen(str_len2))
	{
		printf("ft_strlen error3:  %zu   |   %lu\n", ft_strlen(str_len2), strlen(str_len2));
		c++;
	}
	char	str_len3[100] = "Hello worldkjhrfblre\n\tskjhfgrfhghjefbferjbfqbfefb  hbfqfb fhb rf jf !";
	if (ft_strlen(str_len3) != strlen(str_len3))
	{
		printf("ft_strlen error4:  %zu   |   %lu\n", ft_strlen(str_len3), strlen(str_len3));
		c++;
	}
	if (!c)
		printf("ft_strlen: OK !\n\n");
}

void		test_strcpy(void)
{
	size_t	c;

	printf("*************** FT_STRCPY ***************\n");
	c = 0;
	char	cpy_src[100] = "jfhgejrfgjehrfgj";
	char	*ft_cpy_dest = malloc(sizeof(char) * 100);
	char	*cpy_dest = malloc(sizeof(char) * 100);
	bzero(ft_cpy_dest, 100);
	bzero(cpy_dest, 100);
	if (strcmp(ft_strcpy(ft_cpy_dest, cpy_src), strcpy(cpy_dest, cpy_src)) != 0)
	{
		printf("ft_strcpy error1:  \"%s\"   |   \"%s\"\n", ft_strcpy(ft_cpy_dest, cpy_src), strcpy(cpy_dest, cpy_src));
		c++;
	}
	if (strcmp(ft_cpy_dest, cpy_dest) != 0)
	{
		printf("ft_strcpy error2:  \"%s\"   |   \"%s\"\n", ft_cpy_dest, cpy_dest);
		c++;
	}
	char	cpy_src2[100] = "";
	bzero(ft_cpy_dest, 100);
	bzero(cpy_dest, 100);
	if (strcmp(ft_strcpy(ft_cpy_dest, cpy_src2), strcpy(cpy_dest, cpy_src2)) != 0)
	{
		printf("ft_strcpy error3:  \"%s\"   |   \"%s\"\n", ft_strcpy(ft_cpy_dest, cpy_src2), strcpy(cpy_dest, cpy_src2));
		c++;
	}
	if (strcmp(ft_cpy_dest, cpy_dest) != 0)
	{
		printf("ft_strcpy error4:  \"%s\"   |   \"%s\"\n", ft_cpy_dest, cpy_dest);
		c++;
	}
	char	cpy_src3[100] = "wjesvhbrhjv\tn\neriufhrfherjherh\\erjhfgegfbf";
	bzero(ft_cpy_dest, 100);
	bzero(cpy_dest, 100);
	if (strcmp(ft_strcpy(ft_cpy_dest, cpy_src3), strcpy(cpy_dest, cpy_src3)) != 0)
	{
		printf("ft_strcpy error5:  \"%s\"   |   \"%s\"\n", ft_strcpy(ft_cpy_dest, cpy_src3), strcpy(cpy_dest, cpy_src3));
		c++;
	}
	if (strcmp(ft_cpy_dest, cpy_dest) != 0)
	{
		printf("ft_strcpy error6:  \"%s\"   |   \"%s\"\n", ft_cpy_dest, cpy_dest);
		c++;
	}
	if (!c)
		printf("ft_strcpy: OK !\n\n");
}

void		test_strcmp(void)
{
	size_t	c;

	printf("*************** FT_STRCMP ***************\n");
	c = 0;
	char	*cmp1 = malloc(sizeof(char) * 100);
	char	*cmp2 = malloc(sizeof(char) * 100);
	bzero(cmp1, 100);
	bzero(cmp2, 100);
	sprintf(cmp1, "");
	sprintf(cmp2, "");
	if (ft_strcmp(cmp1, cmp2) != strcmp(cmp1, cmp2))
	{
		printf("ft_strcmp error1:  %i   |   %i\n", ft_strcmp(cmp1, cmp2), strcmp(cmp1, cmp2));
		c++;
	}
	bzero(cmp1, 100);
	bzero(cmp2, 100);
	sprintf(cmp1, "");
	sprintf(cmp2, "rththvrvhgvgc");
	if (ft_strcmp(cmp1, cmp2) != strcmp(cmp1, cmp2))
	{
		printf("ft_strcmp error2:  %i   |   %i\n", ft_strcmp(cmp1, cmp2), strcmp(cmp1, cmp2));
		c++;
	}
	bzero(cmp1, 100);
	bzero(cmp2, 100);
	sprintf(cmp1, "cwgwhehyrhyjuterc");
	sprintf(cmp2, "");
	if (ft_strcmp(cmp1, cmp2) != strcmp(cmp1, cmp2))
	{
		printf("ft_strcmp error3:  %i   |   %i\n", ft_strcmp(cmp1, cmp2), strcmp(cmp1, cmp2));
		c++;
	}
	bzero(cmp1, 100);
	bzero(cmp2, 100);
	sprintf(cmp1, "dskclguhrw");
	sprintf(cmp2, "dskclguhrw");
	if (ft_strcmp(cmp1, cmp2) != strcmp(cmp1, cmp2))
	{
		printf("ft_strcmp error4:  %i   |   %i\n", ft_strcmp(cmp1, cmp2), strcmp(cmp1, cmp2));
		c++;
	}
	bzero(cmp1, 100);
	bzero(cmp2, 100);
	sprintf(cmp1, "cdgrrhtgyhrtcg");
	sprintf(cmp2, "cdgrrhtgyrtcg");
	if (ft_strcmp(cmp1, cmp2) != strcmp(cmp1, cmp2))
	{
		printf("ft_strcmp error5:  %i   |   %i\n", ft_strcmp(cmp1, cmp2), strcmp(cmp1, cmp2));
		c++;
	}
	bzero(cmp1, 100);
	bzero(cmp2, 100);
	sprintf(cmp1, "cd\tgr\nrhtgyhrtcg");
	sprintf(cmp2, "cd\tgr\nrhtgyrtcg");
	if (ft_strcmp(cmp1, cmp2) != strcmp(cmp1, cmp2))
	{
		printf("ft_strcmp error6:  %i   |   %i\n", ft_strcmp(cmp1, cmp2), strcmp(cmp1, cmp2));
		c++;
	}
	if (!c)
		printf("ft_strcmp: OK !\n\n");
}

void		test_strdup(void)
{
	size_t	c;

	printf("*************** FT_STRDUP ***************\n");
	c = 0;
	char	*dup1;
	char	*dup2;
	dup1 = ft_strdup("coucou");
	dup2 = strdup("coucou");
	if (strcmp(dup1, dup2) != 0)
	{
		printf("ft_strdup error1:  %s   |   %s\n", dup1, dup2);
		c++;
	}
	free(dup1);
	free(dup2);
	dup1 = ft_strdup("kjhgfdsdfghuioiuytr");
	dup2 = strdup("kjhgfdsdfghuioiuytr");
	if (strcmp(dup1, dup2) != 0)
	{
		printf("ft_strdup error2:  %s   |   %s\n", dup1, dup2);
		c++;
	}
	free(dup1);
	free(dup2);
	dup1 = ft_strdup("");
	dup2 = strdup("");
	if (strcmp(dup1, dup2) != 0)
	{
		printf("ft_strdup error3:  %s   |   %s\n", dup1, dup2);
		c++;
	}
	free(dup1);
	free(dup2);
	dup1 = ft_strdup("kjhgfd\nkjhgfd\ttfgrad   ");
	dup2 = strdup("kjhgfd\nkjhgfd\ttfgrad   ");
	if (strcmp(dup1, dup2) != 0)
	{
		printf("ft_strdup error4:  %s   |   %s\n", dup1, dup2);
		c++;
	}
	free(dup1);
	free(dup2);
	if (!c)
		printf("ft_strdup: OK !\n\n");
}


void	ft_list_sort2(t_list **lst, int (*cmp)())
{
	void	*tempo;
	t_list	*parcour;

	parcour = *lst;
	while (parcour->next)
	{
		if (((*cmp)(parcour->data, parcour->next->data)) > 0)
		{
			tempo = parcour->data;
			parcour->data = parcour->next->data;
			parcour->next->data = tempo;
			parcour = *lst;
		}
		else
			parcour = parcour->next;
	}
}

void		test_list_push_front(void)
{
	t_list *tlist1 = malloc(sizeof(t_list));
	t_list *tlist2 = malloc(sizeof(t_list));
	t_list *tlist3 = malloc(sizeof(t_list));
	t_list *loop;

	printf("*************** FT_LIST_PUSH_FRONT ***************\n");
	tlist1->data = "Coucou";
	tlist1->next = tlist2;
	tlist2->data = " les ";
	tlist2->next = tlist3;
	tlist3->data = "gens!";
	tlist3->next = NULL;

	loop = tlist1;
	while (loop)
	{
		printf("%s", loop->data);
		loop = loop->next;
	}
	printf("     ->    list_size = %i\n", ft_list_size(tlist1));
	ft_list_push_front(&tlist1, "à tous! ");
	loop = tlist1;
	while (loop)
	{
		printf("%s", loop->data);
		loop = loop->next;
	}
	printf("     ->    list_size = %i\n", ft_list_size(tlist1));

	ft_list_push_front(&tlist1, "Bonjour ");
	loop = tlist1;
	while (loop)
	{
		printf("%s", loop->data);
		printf("     ->    list_size = %i\n", ft_list_size(loop));
		loop = loop->next;
	}
	printf("\n");
}

void		test_list_sort(void)
{
	t_list *tlist1 = malloc(sizeof(t_list));
	t_list *tlist2 = malloc(sizeof(t_list));
	t_list *tlist3 = malloc(sizeof(t_list));
	t_list *loop;

	printf("*************** FT_LIST_SORT ***************\n");
	tlist1->data = "| 5 |";
	tlist1->next = tlist2;
	tlist2->data = "| 4 |";
	tlist2->next = tlist3;
	tlist3->data = "| 9 |";
	tlist3->next = NULL;
	ft_list_push_front(&tlist1, "| 3 |");
	ft_list_push_front(&tlist1, "| 9 |");
	loop = tlist1;
	while (loop)
	{
		printf("%s", loop->data);
		loop = loop->next;
	}
	printf("\n\n");
	ft_list_sort(&tlist1, strcmp);
	loop = tlist1;
	while (loop)
	{
		printf("%s", loop->data);
		loop = loop->next;
	}
	printf("\n\n");
}

void		test_toupper(void)
{
	int		i;
	size_t	c;

   printf("*************** FT_TOUPPER ***************\n");
   c = 0;
   for ((i = -1000000); i < 1000000; i++)
   {
       if (ft_toupper(i) != toupper(i))
       {
           printf("ft_toupper error at i=%d [%d/%d]\n", i, ft_toupper(i), toupper(i));
           c++;
       }
   }
   if (!c)
		printf("ft_toupper: OK !\n\n");
}

void		test_tolower(void)
{
	int		i;
	size_t	c;

   printf("*************** FT_TOLOWER ***************\n");
   c = 0;
   for ((i = -1000000); i < 1000000; i++)
   {
       if (ft_tolower(i) != tolower(i))
       {
           printf("ft_tolower error at i=%d [%d/%d]\n", i, ft_tolower(i), tolower(i));
           c++;
       }
   }
   if (!c)
       printf("ft_tolower: OK !\n\n");
}

void		test_bzero(void)
{
	char	str2[14] = "Hello world !";
	/* FT_BZERO */
	printf("*************** FT_BZERO ***************\n");
	printf("%p\n", str2);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
			str2[0], str2[1], str2[2], str2[3], str2[4], str2[5], str2[6],
			str2[7], str2[8], str2[9], str2[10], str2[11], str2[12], str2[13]);
	ft_bzero(str2, 0);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
			str2[0], str2[1], str2[2], str2[3], str2[4], str2[5], str2[6],
			str2[7], str2[8], str2[9], str2[10], str2[11], str2[12], str2[13]);
	ft_bzero(str2, 6);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
			str2[0], str2[1], str2[2], str2[3], str2[4], str2[5], str2[6],
			str2[7], str2[8], str2[9], str2[10], str2[11], str2[12], str2[13]);
	ft_bzero(str2, 13);
	printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
			str2[0], str2[1], str2[2], str2[3], str2[4], str2[5], str2[6],
			str2[7], str2[8], str2[9], str2[10], str2[11], str2[12], str2[13]);
	printf("%p\n\n", str2);
}

int			main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_strdup();

		/*		BONUS		*/
	test_list_push_front();
	test_list_sort();
	test_toupper();
	test_tolower();
	test_bzero();
}