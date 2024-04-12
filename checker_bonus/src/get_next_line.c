#include "../includes/get_next_line_bonus.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		++j;
		++i;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*read_one_line(char *str, int fd)
{
	char	str_read[BUFFER_SIZE + 1];
	int		count;

	count = -1;
	while (++count <= BUFFER_SIZE)
		str_read[count] = '\0';
	count = 1;
	while (!ft_strchr(str_read, '\n') && count)
	{
		count = read(fd, str_read, BUFFER_SIZE);
		if (count < 0 || (!count && !str))
			return (NULL);
		str_read[count] = '\0';
		if (str)
			str = ft_strjoin_free(str, str_read);
		else
			str = ft_strdup(str_read);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*tail_str;
	int			i;
	char		*str;
	char		*temp;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tail_str = read_one_line(tail_str, fd);
	if (!tail_str)
		return (NULL);
	while (tail_str[i] != '\n' && tail_str[i + 1])
		i++;
	str = ft_substr(tail_str, 0, i + 1);
	temp = tail_str;
	tail_str = ft_substr(tail_str, i + 1, ft_strlen(tail_str) - i - 1);
	free(temp);
	return (str);
}
