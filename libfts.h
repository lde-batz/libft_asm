/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:00:00 by lde-batz          #+#    #+#             */
/*   Updated: 2020/10/20 11:30:34 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char *s);

char	*ft_strcpy(char *dest, const char *src);

int		ft_strcmp(const char *s1, const char *s2);

ssize_t	ft_write(int fd, const void *buf, size_t count);

ssize_t	ft_read(int fd, void *buf, size_t count);

char	*ft_strdup(const char *s);

void	ft_list_push_front(t_list **begin_list, void *data);

int		ft_list_size(t_list *begin_list);

void	ft_list_sort(t_list **begin_list, int (*cmp)());

void	ft_bzero(void *s, size_t n);

int		ft_tolower(int c);

int		ft_toupper(int c);

#endif