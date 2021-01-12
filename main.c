#include "libfts.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

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
	printf("test: %d\n", ft_strcmp("", ""));
	printf("test: %d\n", ft_strcmp("", ""));

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

void	test_write(void)
{
	ssize_t len;
	char buff[10];
	printf("*************** FT_WRITE ***************\n");
	printf("*************** FT_READ ****************\n");
	ft_write(0, "Bonjour! Quel est votre prenom?\n", 32);
	bzero(buff, 10);
	len = ft_read(0, buff, 9);
	buff[len - 1] = '\0';
	ft_write(0, buff, 10);
	ft_write(0, ", quel beau prenom!\nEt quel est votre nom?: ", 44);
	bzero(buff, 10);
	len = ft_read(0, buff, 9);
	buff[len - 1] = '\0';
	ft_write(0, buff, 10);
	ft_write(0, ", tres bien, merci beaucoup!\n", 29);
//	ssize_t b = ft_write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
//	perror("ft_write errno");
	ssize_t a = write(FOPEN_MAX + 1, "abcdefghijklmnopqrstuvwxyz\n", 27);
	perror("write errno");
    printf("return write = %zd\nreturn ft_write = \n", a);
	printf("\n");
}

void		test_list_push_front(void)
{
	t_list *tlist1 = malloc(sizeof(t_list));
	t_list *tlist2 = malloc(sizeof(t_list));
	t_list *tlist3 = malloc(sizeof(t_list));
	t_list *loop;

	printf("*************** FT_LIST_PUSH_FRONT ***************\n");
	printf("****************** FT_LIST_SIZE ******************\n");
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
		loop = loop->next;
	}
	printf("     ->    list_size = %i\n", ft_list_size(tlist1));
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

void		test_list_remove_if(void)
{
	t_list *tlist1 = malloc(sizeof(t_list));
	t_list *tlist2 = malloc(sizeof(t_list));
	t_list *tlist3 = malloc(sizeof(t_list));
	t_list *loop;

	printf("*************** FT_LIST_REMOVE_IF ***************\n");
	tlist1->data = "| 9 |";
	tlist1->next = tlist2;
	tlist2->data = "| 4 |";
	tlist2->next = tlist3;
	tlist3->data = "| 5 |";
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
	ft_list_remove_if(&tlist1, "| 4 |", strcmp);
	loop = tlist1;
	while (loop)
	{
		printf("%s", loop->data);
		loop = loop->next;
	}
	printf("\n\n");
	ft_list_remove_if(&tlist1, "| 9 |", strcmp);
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

void test_atoi_base(void)
{
	printf("*************** FT_ISSAPCE ***************\n");
	printf("%i | %i | %i\n\n", ft_isspace(32), ft_isspace(12), ft_isspace(60));

	printf("*************** FT_ATOI_BASE ***************\n");
	int i = ft_atoi_base("9", "0123456789");
	printf("%i\n", i);
	i = ft_atoi_base("-12", "0123456789");
	printf("%i\n", i);
	 i = ft_atoi_base("--123", "0123456789");
	printf("%i\n", i);
	 i = ft_atoi_base("---1234", "0123456789");
	printf("%i\n", i);
	 i = ft_atoi_base("----12345", "0123456789");
	printf("%i\n", i);


	printf("\n");

}

void test_atoi(void)
{
	printf("*************** FT_ATOI ***************\n");
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("13435675"), atoi("13435675"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("--42"), atoi("--42"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("-42"), atoi("-42"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("+42"), atoi("+42"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("2147483648"), atoi("2147483648"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("99999999999"), atoi("99999999999"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("\t\v \n123456789"), atoi("\t\v \n123456789"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("123456789abcdef"), atoi("123456789abcdef"));
	printf("ft_atoi = %i  |  atoi = %i\n", ft_atoi("\t\v \n1234567 89abcdef"), atoi("\t\v \n1234567 89abcdef"));
	printf("\n");
}

int			main(void)
{
//	test_strlen();
//	test_strcpy();
//	test_strcmp();
//	test_strdup();
//	test_write();

		/*		BONUS		*/
//	test_list_push_front();
//	test_list_sort();
//	test_list_remove_if();
//	test_atoi_base();
	test_toupper();
	test_tolower();
	test_bzero();
	test_atoi();
}