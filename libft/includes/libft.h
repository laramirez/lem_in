/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:02:13 by lramirez          #+#    #+#             */
/*   Updated: 2018/02/10 18:15:40 by lramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define GNL_BUFF_SIZE 100
# define GNL_SEPARATOR '\n'

# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <wchar.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*data;
	size_t			data_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_fd
{
	int				fd;
	char			*stock;
	struct s_fd		*next;
}					t_fd;

typedef	struct		s_arg
{
	char			*format_code;
	char			*flags;
	char			*width;
	char			*prec;
	char			*mod;
	char			*conv;
	char			*type;
	char			*wildcard_1;
	char			*wildcard_2;
	char			*print;
	size_t			print_len;
	char			is_null;
	struct s_arg	*next;
}					t_arg;

/*
** ---MEMORY MANIPULATION---
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** ---STRING MANIPULATION---
*/
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
size_t				ft_countwords(char const *str, char c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long				ft_atoi(const char *str);
unsigned long		ft_atoui(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t n);
char				*ft_strsubfree(char *s, unsigned int start, size_t len);
char				*ft_append_before(char *s1, char *s2);
char				*ft_append_after(char *s1, char *s2);
char				*ft_insert_in_str(char *s1, char *s2, size_t pos);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_strnjoinfree(char *s1, char *s2,
						size_t len_1, size_t len_2);
char				*ft_strtrim(char const *s);
char				*ft_strdup(const char *s1);
char				*ft_strdupfree(char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				**ft_strsplit(char const *s, char c);
int					ft_putstr_fd_count(char *str, int fd);
int					ft_putnstr_fd_count(char *str, size_t n, int fd);
int					ft_put_partial_str_count(char *start, char *end);
char				*ft_hex_prefix(char upper);
char				*ft_bin_prefix(char upper);
char				*ft_oct_prefix(void);
int					ft_match(const char *check, char *against);
char				*ft_create_padding(char c, int size);
char				*ft_create_null_string(void);
char				*ft_create_zero_string(void);
int					ft_is_empty_str(char const *s);
size_t				ft_wcslen(wchar_t *wcs);
char				*ft_wcstombs(wchar_t *wcs, size_t size);

/*
** ---CHARACTER MANIPULATION---
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
size_t				ft_wclen(wint_t wc);
char				*ft_wctomb(wint_t wc);

/*
** ---NUMBER MANIPULATION---
*/
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_intlen(unsigned int n);
size_t				ft_longlen(unsigned long n);
size_t				ft_longlonglen(unsigned long long n);
size_t				ft_intmaxlen(uintmax_t n);
unsigned int		ft_abs(int n);
unsigned long		ft_abs_long(long n);
unsigned long long	ft_abs_longlong(long long n);
uintmax_t			ft_abs_intmax(long n);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ultoa(unsigned long n);
char				*ft_imtoa(intmax_t n);
char				*ft_uimtoa(uintmax_t n);
char				*ft_lltoa_base(long long n, int base, short upper);
char				*ft_ultoa_base(unsigned long n, int base, short upper);
char				*ft_dtoa(double nbr, size_t afterpoint);
double				ft_pow(double base, double exponent);
float				ft_fmod(float x, float y);

/*
** ---TABLE MANIPULATION---
*/
char				**ft_strtabnew(size_t size);
void				ft_tab_quicksort(int *tab, int start, int end);
int					*ft_tabcpy(const int *tab, size_t size);

/*
** ---LIST MANIPULATION---
*/
t_list				*ft_lstnew(void const *data, size_t data_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstdup(t_list *lst);

/*
** ---ERROR HANDLING---
*/
void				ft_kill(void);

/*
** ---GET_NEXT_LINE---
*/
int					get_next_line(const int fd, char **line);

/*
** ---FT_PRINTF---
*/
int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);
int					ft_asprintf(char **ret, const char *restrict format, ...);
int					count_args(char *format);
void				lstdel(t_arg **list);
int					is_modifier(char c);
int					is_specifier(char c);
void				get_flags(t_arg *arg);
void				get_mod(t_arg *arg);
int					signed_conversion(char *conv);
t_arg				**populate_list(char *format);
void				add_arg(t_arg **list, t_arg *new_arg);
t_arg				*create_arg(char *format_code);
void				get_specs_1(t_arg *arg);
void				get_specs_2(char **ptr, char **ptr_2,
						char *tmp, t_arg *arg);
t_arg				*determine_type(t_arg *arg);
t_arg				*determine_mod_type_1(t_arg *arg);
t_arg				*determine_mod_type_2(t_arg *arg);
t_arg				*determine_mod_type_3(t_arg *arg);
void				get_arg(t_arg *arg, va_list ap);
void				get_arg_2(t_arg *arg, va_list ap);
void				get_s_arg(t_arg *arg, va_list ap);
void				get_arg_opt(t_arg *arg, va_list ap);
void				special_case(t_arg *arg);
void				compute_arg(t_arg *arg);
void				compute_pbox_args(t_arg *arg, char is_null,
					char up, char *to_free);
char				*add_precision(char *print, char *value);
char				*add_width(t_arg *arg, char c);
void				add_width_2(t_arg *arg, char **padding);
int					print_with_args(char *format, t_arg **list, int fd);
int					print_and_free(char *format, int fd, t_arg **list, long n);
void				format_part(char **ptr, char **print_result,
						long *n, char **format);
void				arg_part(char **ptr, char **print_result,
						long *n, t_arg *tmp);
int					error(char *to_free, char *print_result,
						int fd, t_arg **list);
int					create_str_with_args(char *format,
						t_arg **list, char **ret);
int					create_str_free(char *format, char **ret,
						t_arg **list, long n);
int					error_as(char *to_free, char *print_result,
						char **ret, t_arg **list);

#endif
