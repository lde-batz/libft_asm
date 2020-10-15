#include "libfts.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

#define FILE_TEST	"Makefile"

int			main(void)
{
	int		i;
	size_t	c;

	/* FT_STRLEN */
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


		/* FT_STRCPY */
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

		/* FT_STRCMP */
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


    /* FT_ISPRINT */
/*   printf("*************** FT_ISPRINT ***************\n");
   c = 0;
   for ((i = -1000000); i < 1000000; i++)
   {
       if (ft_isprint(i) != isprint(i))
       {
           printf("ft_isprint error at i=%d [%d/%d]\n", i, ft_isprint(i), isprint(i));
           c++;
       }
   }
   if (!c)
       printf("ft_isprint: OK !\n\n");

	 /* FT_ISALPHA */
/*	 printf("*************** FT_ISALPHA ***************\n");
	 c = 0;
	 for ((i = -1000000); i < 1000000; i++)
	 {
	     if (ft_isalpha(i) != isalpha(i))
	     {
	         printf("ft_isalpha error at i=%d [%d/%d]\n", i, ft_isalpha(i), isalpha(i));
	         c++;
	     }
	 }
	 if (!c)
	     printf("ft_isalpha: OK !\n\n");

    /* FT_ISDIGIT */
/*  printf("*************** FT_ISDIGIT ***************\n");
    c = 0;
    for ((i = -1000000); i < 1000000; i++)
    {
        if (ft_isdigit(i) != isdigit(i))
        {
            printf("ft_isdigit error at i=%d [%d/%d]\n", i, ft_isdigit(i), isdigit(i));
            c++;
        }
    }
    if (!c)
        printf("ft_isdigit: OK !\n\n");

 //    /* FT_ISASCII */
/*   printf("*************** FT_ISASCII ***************\n");
   c = 0;
   for ((i = -1000000); i < 1000000; i++)
   {
       if (ft_isascii(i) != isascii(i))
       {
           printf("ft_isascii error at i=%d [%d/%d]\n", i, ft_isascii(i), isascii(i));
           c++;
       }
   }
   if (!c)
       printf("ft_isascii: OK !\n\n");//

    /* FT_ISALNUM */
/*   printf("*************** FT_ISALNUM ***************\n");
   c = 0;
   for ((i = -1000000); i < 1000000; i++)
   {
       if (ft_isalnum(i) != isalnum(i))
       {
           printf("ft_isalnum error at i=%d [%d/%d]\n", i, ft_isalnum(i), isalnum(i));
           c++;
       }
   }
   if (!c)
       printf("ft_isalnum: OK !\n\n");

 //    /* FT_TOUPPER */
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

    /* FT_TOLOWER */
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
       printf("ft_tolower: OK !\n\n");//

   /* FT_PUTS */
/*   printf("*************** FT_PUTS ***************\n");
   c = 0;
   ft_puts("ft_puts: Hello"); 
   puts("puts: Hello");
  ft_puts(NULL );
   if (!c)
       printf("ft_puts: OK !\n\n");

    char    str[20] = "Hello";
   /* FT_STRCAT */
/*   printf("*************** FT_STRCAT ***************\n");
   printf("%p\n", str);
   printf("\"Hello\" + \" world !\": %s\n", ft_strcat(str, " world !"));
   printf("\"Hello world !\" + \"\": %s\n", ft_strcat(str, ""));
   printf("%p\n\n", str);

*/	char	str2[14] = "Hello world !";
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

    /* FT_STRLEN */
/*   printf("*************** FT_STRLEN ***************\n");
   c = 0;
   if (ft_strlen(str) != strlen(str))
   {
       printf("ft_strlen error [%ld/%ld]\n", ft_strlen(str), strlen(str));
       c++;
   }
   if (ft_strlen(str2) != strlen(str2))
   {
       printf("ft_strlen error [%ld/%ld]\n", ft_strlen(str2), strlen(str2));
       c++;
   }
   if (ft_strlen("1") != strlen("1"))
   {
       printf("ft_strlen error [%ld/%ld]\n", ft_strlen("1"), strlen("1"));
       c++;
   }
   if (ft_strlen("\0") != strlen("\0"))
   {
       printf("ft_strlen error [%ld/%ld]\n", ft_strlen("\0"), strlen("\0"));
       c++;
   }
   if (!c)
       printf("ft_strlen: OK !\n\n");//

   char    str3[14] = "Hello world !";
   /* FT_MEMSET */
/*   printf("*************** FT_MEMSET ***************\n");
   printf("%p\n", str3);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str3[0], str3[1], str3[2], str3[3], str3[4], str3[5], str3[6],
           str3[7], str3[8], str3[9], str3[10], str3[11], str3[12], str3[13]);
   ft_memset(str3, 'X', 0);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str3[0], str3[1], str3[2], str3[3], str3[4], str3[5], str3[6],
           str3[7], str3[8], str3[9], str3[10], str3[11], str3[12], str3[13]);
   ft_memset(str3, 'X', 6);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str3[0], str3[1], str3[2], str3[3], str3[4], str3[5], str3[6],
           str3[7], str3[8], str3[9], str3[10], str3[11], str3[12], str3[13]);
   ft_memset(str3, 'X', 13);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str3[0], str3[1], str3[2], str3[3], str3[4], str3[5], str3[6],
           str3[7], str3[8], str3[9], str3[10], str3[11], str3[12], str3[13]);
   printf("%p\n\n", str3);//

   char    str4[14] = "Hello world !";
   /* FT_MEMCPY */
/*  printf("*************** FT_MEMCPY ***************\n");
   printf("%p\n", str4);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str4[0], str4[1], str4[2], str4[3], str4[4], str4[5], str4[6],
           str4[7], str4[8], str4[9], str4[10], str4[11], str4[12], str4[13]);
   ft_memcpy(str4, "Bonjour monde", 0);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str4[0], str4[1], str4[2], str4[3], str4[4], str4[5], str4[6],
           str4[7], str4[8], str4[9], str4[10], str4[11], str4[12], str4[13]);
   ft_memcpy(str4, "Bonjour monde", 5);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str4[0], str4[1], str4[2], str4[3], str4[4], str4[5], str4[6],
           str4[7], str4[8], str4[9], str4[10], str4[11], str4[12], str4[13]);
   ft_memcpy(str4, "Bonjour monde", 13);
   printf("[%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c][%c]\n",
           str4[0], str4[1], str4[2], str4[3], str4[4], str4[5], str4[6],
           str4[7], str4[8], str4[9], str4[10], str4[11], str4[12], str4[13]);
   printf("%p\n\n", str4);//

   char    str5[14] = "Hello world !";
   char    *str6;
   /* FT_STRDUP */
/*   printf("*************** FT_STRDUP ***************\n");
   printf("%p\n", str5);
   str6 = ft_strdup(str5);
   printf("%s\n", str5);
   printf("%s\n", str6);
   printf("%p\n", str5);
   printf("%p\n", str6);
   free(str6);//

   int     fd;
   /* FT_CAT */
/*   printf("*************** FT_CAT ***************\n");
   printf("Standard Input (CTRL + D to quit):\n");
   ft_cat(0);
   fd = open(FILE_TEST, O_RDONLY);
   ft_cat(fd);
   close(fd);
   ft_cat(-42);
   */
}