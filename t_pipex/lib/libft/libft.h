/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:32:51 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/12 14:37:17 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h> 
# include <stdint.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_printf
{
	va_list		args;
	char		c_spc;
	const void	*ptr;
}	t_printf;

/*
** Check if a character is from the alphabet , 
** ASCII code between [65, 90] && [97, 122]
*/
int			ft_isascii(int ch);
/*
** The isprint() function tests for any printing character, 
** including space (` ').
** ASCII code between [32, 126]
*/
int			ft_isprint(int ch);
/*
** Check if a character is from the alphabet , 
** ASCII code between [65, 90] && [97, 122]
*/
int			ft_isalpha(int ch);
/*
** Converts a lowercase alphabetic letter to uppercase
** ASCII code between [97, 122] to [65, 90]
*/
int			ft_toupper(int ch);
/*
** Converts a uppercase alphabetic letter to lowercase
** ASCII code between [65, 90] to [97, 122]
*/
int			ft_tolower(int ch);
/*
** Check if a character is a digit [0 - 9] , 
** ASCII code between [48, 57]
*/
int			ft_isdigit(int ch);
/*
** Check if a character is from the alphanumeric, 
** ASCII code between [65, 90], [97, 122] && [48, 57]
*/
int			ft_isalnum(int ch);
/*
** Computes the length of the string s before '\0'.
*/
size_t		ft_strlen(const char *str);
/*
** The memset() function fills the first n bytes of the 
** memory area pointed to by s with the constant byte c 
** (converted to an unsigned char.
*/
void		*ft_memset(void *s, int c, size_t n);
/*
**  The bzero() function writes n zeroed bytes to the 
** string s.  If n is zero, bzero() does nothing.
*/
void		ft_bzero(void *s, size_t n);
/*
** The memcmp() function returns zero if the two strings are
** identical, otherwise returns the difference between the 
** first two differing bytes
*/
int			ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** Copies "n" bytes from address "src" to address "dest"
** void * memcpy(void *to, const void *from, size_t numBytes); 
*/
void		*ft_memcpy(void *dest, const void *src, size_t n);
/*
** The memmove() function copies len bytes from string src to string dst.
*/
void		*ft_memmove(void *dest, const void *src, size_t n);
/*
** The memchr() function locates the first occurrence of 
** c (converted to  an unsigned char) in string s.
*/
void		*ft_memchr(const void *s, int c, size_t n);
/*
** DESCRIPTION
** The strchr() function locates the first occurrence of c (converted to a 
** char) in the string pointed to by s.  The terminating null character is 
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/
char		*ft_strchr(const char *s, int c);
/*
** The strrchr() function locates the last occurrence of c.
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the
** located character, or NULL if the character does not appear 
** in the string.
*/
char		*ft_strrchr(const char *s, int c);
/*
** The strlcpy() function copies at most dstsize−1 characters 
** (dstsize being the size of the string buffer dst) from src
** to dst, truncating src if necessary. The result is always 
** null-terminated. The function returns strlen(src). 
** RETURN VALUES
** strlcpy() function return the total length of the string 
** they tried to create.  For strlcpy() that means the length
** of src.
*/
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
/*
** The strlcat() fappends string src to the end of dst.  It 
** will append at most dstsize - strlen(dst) - 1 characters.
** It will then NUL-terminate, unless dstsize is 0 or the 
** original dst string was longer than dstsize (in practice 
** this should not happen as it means that either dstsize is 
** incorrect or that dst is not a proper string).
** If the src and dst strings overlap, the behavior is undefined. 
** RETURN VALUES
** strlcat() functions return the total length of the string 
** they tried to create. For strlcat() that means the initial 
** length of dst plus the length of src.
** If the return value is >= dstsize, the output string has 
** been truncated.  It is the caller's responsibility to handle this.
*/
size_t		ft_strlcat(char *dest, const char *src, size_t n);
/*
** DESCRIPTION
** The strncmp() functions lexicographically compare the 
** null-terminated strings s1 and s2.
** The strncmp() function compares not more than n characters.  
** Because strncmp() is designed for comparing strings rather 
** than binary data, characters that appear after a `\0'
**  character are not compared.
** RETURN VALUES
** The strncmp() functions return an integer greater than, 
** equal to, or less than 0, according as the string s1 is 
** greater than, equal to, or less than the string s2.  
** The comparison is done using unsigned characters, so that 
** `\200' is greater than `\0'.
*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
/*
** DESCRIPTION
** The strnstr() function locates the first occurrence of the 
** null-terminated string needle in the string haystack, where 
** not more than len characters are searched.  Characters that 
** appear after a `\0' character are not searched. 
** RETURN VALUES
** If needle is an empty string, haystack is returned; if 
** needle occurs nowhere in haystack, NULL is returned; 
** otherwise a pointer to the first character of the first 
** occurrence of needle is returned.
*/
char		*ft_strnstr(const char *hs, const char *nd, size_t len);
/*
** DESCRIPTION
** The atoi() function converts the initial portion of the 
** string pointed to by str to int representation.
*/
int			ft_atoi(const char *s);
/*
** DESCRIPTION
** The atoi() function converts the initial portion of the 
** string pointed to by str to long int representation.
*/
long int	ft_atol(const char *s);
/*
** DESCRIPTION
** The calloc() function contiguously allocates enough space 
** for count objects that are size bytes of memory each and 
** returns a pointer to the allocated memory.  The allocated
** memory is filled with bytes of value zero.
** RETURN VALUES
** If successful, it returns a pointer to allocated memory.  If 
** there is an error, it returns a NULL pointer.
*/
void		*ft_calloc(size_t count, size_t size);
/*
** DESCRIPTION
** The strdup() function allocates sufficient memory for a copy
** of the string s1, does the copy, and returns a pointer to 
** it. The pointer may subsequently be used as an argument to 
** the function free(3).
** If insufficient memory is available, NULL is returned. 
** The strndup() function copies at most n characters from 
** the string s1 always NUL terminating the copied string.
*/
char		*ft_strdup(const char *s1);
/*
** Outputs the character ’c’ to the given file descriptor.
*/
void		ft_putchar_fd(char c, int fd);
/*
** Outputs the string ’s’ to the given file descriptor.
*/
void		ft_putstr_fd(char *s, int fd);
/*
** Outputs the string ’s’ to the given file descriptor 
** followed by a newline.
*/
void		ft_putendl_fd(char *s, int fd);
/*
** Outputs the integer ’n’ to the given file descriptor.
*/
void		ft_putnbr_fd(int n, int fd);
/*
** Applies the function ’f’ on each character of the 
** string passed as argument, passing its index as first
** argument. Each character is passed by address to ’f’ 
** to be modified if necessary.
*/
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
/*
** Applies the function ’f’ to each character of the 
** string ’s’, and passing its index as first argument 
** to create a new string (with malloc(3)) resulting 
** from successive applications of ’f’.
*/
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
** Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
*/
char		*ft_itoa(int n);
/*
** Allocates (with malloc(3)) and returns an array of 
** strings obtained by splitting ’s’ using the character 
** ’c’ as a delimiter. The array must end with a NULL pointer.
*/
char		**ft_split(char const *s, char c);
/*
** Allocates (with malloc(3)) and returns a copy of ’s1’ 
** with the characters specified in ’set’ removed from
** the beginning and the end of the string.
*/
char		*ft_strtrim(char const *s1, char const *set);
/*
** Allocates (with malloc(3)) and returns a new string,
** which is the result of the concatenation of ’s1’ and ’s2’.
*/
char		*ft_strjoin(char const *s1, char const *s2);
/*
** Allocates (with malloc(3)) and returns a substring 
** from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
*/
char		*ft_substr(char const *s, unsigned int start, size_t len);

/****** GET NEXT LINE *******/
char		*get_next_line(int fd);
/* linked list functions*/
//t_list	*create_empty_list(void);
void		add_node_to_list(t_list **list, char *new_str, int ret);
void		free_node_list(void **list);
/*	libft utils functions	*/
char		*ft_strjoin_gnl(char const *s1, char const *s2, int free_str);
/* Copies n charactarcters from s1 */
char		*ft_strdup_len(char *s1, size_t n);
void		search_line(t_list **list, char **line_read);
void		search_line_ext(t_list **list, char **line, char *ptr);

/****** FT_PRINTF *******/
int			ft_printf(const char *format, ...);
void		ft_printf_str(t_printf **content, int *ret);
void		ft_printf_int(t_printf **content, int *ret);
void		ft_printf_char(t_printf **content, int *ret);
void		ft_printf_upx(t_printf **content, int *ret, int base);
int			ft_get_strsize(unsigned long num, int base);
void		ft_convert2base(char *str, int len, int base, unsigned long num);
void		ft_putstr(char *s);
void		ft_putchar(char c);
/* ft_utils.c */
void		ft_free(char **str);
void		ft_error(char *str1, char *str2, pid_t pid);
#endif