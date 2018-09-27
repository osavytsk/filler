/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:32:00 by osavytsk          #+#    #+#             */
/*   Updated: 2018/06/22 17:32:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# define BUFF_SIZE 1

/*
** First main part of Libft functions
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Second main part of Libft functions
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_strdel(char **as);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);

/*
** Bonus part
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Additional bonus part
*/

char				*ft_strrev(char *s);
double				ft_power(double n, int pow);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);

/*
**	GNL part
*/

int					get_next_line(const int fd, char **line);



/*
**	Ft_printf part
*/

typedef struct		s_flag
{
	int				precision;
	int				prec;
	int				width;
	int				plus;
	int				minus;
	int				sharp;
	int				zero;
	int				space;
	enum
	{
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				e_size;
}					t_flags;

/*
**	Ft_printf part spec functions
*/

int					ft_printf(const char *format, ...);
int					pars(char **format, t_flags *flag, va_list *arg);
int					take_specifier(char **format, t_flags *flag, va_list *arg);
int					low_s(va_list *arg, t_flags *flag);
int					up_s(va_list *arg, t_flags *flag);
int					low_i(va_list *arg, t_flags *flag);
int					low_d(va_list *arg, t_flags *flag);
int					up_d(va_list *arg, t_flags *flag);
int					low_p(va_list *arg, t_flags *flag);
int					low_o(va_list *arg, t_flags *flag);
int					up_o(va_list *arg, t_flags *flag);
int					low_u(va_list *arg, t_flags *flag);
int					up_u(va_list *arg, t_flags *flag);
int					low_x(va_list *arg, t_flags *flag);
int					up_x(va_list *arg, t_flags *flag);
int					low_c(va_list *arg, t_flags *flag);
int					up_c(va_list *arg, t_flags *flag);
int					percent(va_list *arg, t_flags *flag);
int					undef(char c, t_flags *flag);

/*
**	Ft_printf part tab and width
*/

void				take_options(char **str, t_flags *flag, va_list *arg);
void				take_flag(char **str, t_flags *flag, va_list *arg);
void				take_width(char **str, t_flags *flag, va_list *arg);
void				take_precision(char **str, t_flags *flag, va_list *arg);
void				take_length(char **str, t_flags *flag, va_list *arg);

/*
**	Ft_printf part utils functions
*/

uintmax_t			take_utype(va_list *arg, t_flags *flag);
intmax_t			take_type(va_list *arg, t_flags *flag);
void				null_flags_struct(t_flags *flag);
void				put_nstr(char *str, int n);
int					str_nlen(char *str, int n);
int					wchar_len(wchar_t c);
int					wstr_len(wchar_t *s);
int					wstr_nlen(wchar_t *s, int n);
void				put_wchar(wchar_t c);
void				put_nwstr(wchar_t *s, int n);
void				put_space(int width, int strlen);
void				put_zero(int width, int strlen);
void				take_int(intmax_t nb);
int					take_len(intmax_t nb);
int					take_flag_len(intmax_t nb, t_flags *flag);
void				take_ui(uintmax_t nb, char *str, int base);
int					take_ui_len(uintmax_t nb, int base);
int					take_ui_flag_len(uintmax_t nb, t_flags *flag, int base);
void				put_int_left_space(t_flags *flag, int len, intmax_t nb);
void				put_uint_left_space(t_flags *flag, int len,
					uintmax_t nb, int type);
void				put_str_left_space(t_flags *flag, int len);
#endif
