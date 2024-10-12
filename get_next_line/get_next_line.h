
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*ft_getlines(int fd, char *src);
int		ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getline(char *dst);
char	*ft_getget(char *str);

#endif
