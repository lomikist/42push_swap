#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, const char *s2);

#endif