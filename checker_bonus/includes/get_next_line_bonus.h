#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "../libft/libft.h"

char			*ft_strjoin_free(char *s1, char *s2);
char			*get_next_line(int fd);

#endif
