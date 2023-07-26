/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:18:55 by mrony             #+#    #+#             */
/*   Updated: 2023/07/26 12:41:01 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "printf.h"

/////////////////////////////////
///          STRINGS          ///
/////////////////////////////////

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strccmp(const char *s1, const char *s2, char c);
char			*last_word(char *str, char c);

////////////////////////////////
///          MEMORY          ///
////////////////////////////////

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/////////////////////////////////////
///          CONVERSIONS          ///
/////////////////////////////////////

int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_itoa(int n);
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
int				ft_atoi_base(char *str, char *base);
int				ft_atoi_hexa(char *str);

/////////////////////////////////
///          INTEGER          ///
/////////////////////////////////

int				ft_abs(int nb);
int				ft_sgn(int nb);
int				ft_smaller(int a, int b);
int				ft_bigger(int a, int b);

////////////////////////////////
///          OUTPUT          ///
////////////////////////////////

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

//////////////////////////////
///          READ          ///
//////////////////////////////

unsigned int	ft_strlen_gnl(char *str);
void			*ft_memmove_gnl(void *dest, const void *src, size_t n);
char			*get_next_line(int fd);
char			*ft_strchr_gnl(const char *s, int c);
char			*ft_strjoin_gnl(char *s1, char *s2);

///////////////////////////////
///          LISTS          ///
///////////////////////////////

typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}				t_list;

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_lstsize(t_list *lst);


#endif
