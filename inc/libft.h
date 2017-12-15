/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:42:48 by mdamesto          #+#    #+#             */
/*   Updated: 2016/02/14 18:09:34 by mdamesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <wchar.h>
# include <stdarg.h>
# include <locale.h>

# define BUFF_SIZE 16
# define FLAG_LETTERS "0-+ #*"
# define PAD_LETTERS "0123456789"
# define PRECISION_LETTERS ".0123456789"
# define MODIFIER_LETTERS "hljz"
# define TYPE_LETTERS "sSpdDioOuUxXcC%"
# define NUMBER_TYPES "dDiouUxX"
# define BYPASS_UNDEFINED_BEHAVIOR 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_struct
{
	int				i;
	int				r;
	char			*tmpbuf;
}					t_struct;

typedef struct		s_printf_flags
{
	int zero;
	int minus;
	int plus;
	int space;
	int hashtag;
}					t_printf_flags;

typedef struct		s_printf_format
{
	struct s_printf_flags	flags;
	int						pad_size;
	int						precision_size;
	int						modifier;
	char					type;
	int						hide_print;
	int						nwcard;
}					t_printf_format;

int					ft_istrlen(int *istr);
int					ft_itab_len(int **tab);
int					**ft_itab_set(int size);
int					*ft_istr_set(int size);
char				**ft_tab_set(int y, int x);
void				ft_tab_print(char **tab);
void				ft_tab_free(char **tab);
int					ft_tab_len(char **tab);
char				**ft_tab_realloc(char **tab, int size);
int					get_next_line(int const fd, char **line);
int					ft_str_isdigit(char *str);
char				*ft_itoa_base_u(unsigned long long int n, int base);
char				*ft_itoa_base(long long int n, int base);
void				ft_putnbr_base(int n, int base);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memset(void*b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char*src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char*s1, const char*s2);
char				*ft_strncat(char *s1, const char*s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_ishex(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strupper(char *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
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
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strcut_beg(char *str, int n);
char				*ft_rmv_space(char *str);
int					ft_isspace(char c);
char				**ft_strsplit_space(char *s);
char				*ft_strcut_end(char *str, int n);
char				*ft_tab_join(char **tab);
char				*convert_hex_octnb(int nb, size_t oct_nb);
char				*fill_hex(char *tmp, size_t oct_nb);
char				*fill_hex_be(char *str, size_t oct_nb);
void				ft_tab_trim(char **tab);
int					ft_bin_to_int(char *str);
int					ft_is_label_char(char c);
char				*ft_strjoin_f(char *s1, char *s2, int code);
char				*ft_strget(char *str, int s, int e);
char				*ft_strget_f(char *str, int s, int e);
char				*ft_strcut(char *str, int s, int e);
char				*ft_strcut_f(char *str, int s, int e);
char				*ft_rmv_space_f(char *str);
void				*ft_print_memory(void *addr, size_t size);
int					ft_atoi_hex(const char *str);
char				*ft_strtrim_f(char *s);
unsigned char		*ft_strnew_uchar(size_t size);
int					utf_byte_size(unsigned int c);
int					ft_size_long(long n);
int					ft_ispos(long n);
char				*ft_itoa_long(long n);
void				ft_strrev(char *str);
int					ft_strlen_uchar(unsigned char *s);
int					ft_strlen_ls(const wint_t *ls);
int					ft_size_ulong(unsigned long n);
char				*ft_itoa_ulong(unsigned long n);
unsigned char		*ft_strcat_uchar(unsigned char *s1, unsigned char *s2);
int					ft_isint(char *s);
long				ft_atoi_long(const char *str);
int					ft_printf(char *input_string, ...);
int					parser_c(t_printf_format format, va_list varlist);
int					parser_s(t_printf_format format, va_list varlist);
int					parser_o(t_printf_format format, va_list varlist);
int					parser_x(t_printf_format format, va_list varlist);
int					parser_u(t_printf_format format, va_list varlist);
int					parser_d(t_printf_format format, va_list varlist);
int					parser_p(t_printf_format format, va_list varlist);
int					print_x(t_printf_format format, unsigned long x);
int					print_u(t_printf_format format, unsigned long u);
int					print_d(t_printf_format *format, long d);
int					print_o(t_printf_format format, unsigned long o);
int					print_c(t_printf_format format, unsigned char c);
int					print_s(t_printf_format format, char *s);
int					print_p(t_printf_format format, void *p);
int					print_ls(t_printf_format *format, wint_t *ls);
int					print_lc(t_printf_format *format, wint_t c);
int					print_utf_char(unsigned int c);
int					ft_binary_size(int c);
void				print_pad(int pad_size, int zpad, int nwcard);
void				print_precision(int precision_size);
void				print_flags(t_printf_format format, int d);
char				ft_printf_hexa_table(int i, char type);
char				*string_parser(char *s, t_printf_format *format,
								va_list varlist);
char				hexa_ascii_table(unsigned long ipt);
void				ftprintf_struct_init(t_printf_format *format);
void				get_pad(int pad_size, int zpad, char **str);
void				get_precision(int precision_size, char **str);
void				get_flags(t_printf_format *format, int pos, char **str);
void				get_utf_char(unsigned int c, unsigned char **str);
int					test_next_arg(char *ipt_string, va_list varlist);
short				ft_atoi_short(const char *str);

#endif
