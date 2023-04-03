#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


size_t	ft_strlen(const char *str)
{
	int	aux;

	aux = 0;
	while (*str != '\0')
	{
		aux++;
		str++;
	}
	return (aux);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	aux;
	unsigned int	counter;

	aux = 0;
	counter = 0;
	while (src[counter] != '\0')
		counter++;
	if (size != 0)
	{
		while (src[aux] != '\0' && aux < (size - 1))
		{
			dest[aux] = src[aux];
			aux++;
		}
		dest[aux] = '\0';
	}
	return (counter);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	destl;
	unsigned int	srcl;
	unsigned int	initial;
	char			*aux;

	destl = ft_strlen(dest);
	initial = destl;
	srcl = ft_strlen(src);
	if (size == 0)
		return (srcl);
	if (destl >= size)
		return (srcl + size);
	aux = dest + destl;
	while (*src != '\0' && destl < (size - 1) && size >= 2)
	{
		*aux = *src;
		aux++;
		src++;
		destl++;
	}
	if (size != 0)
		*aux = '\0';
	return (initial + srcl);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * total + 1);
	if (str == 0)
		return (0);
	i = 0;
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, total + 1);
	return (str);
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(src);
	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == 0)
		return (dest);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int end(char *str){

    while (*str != '\0')
    {
        if (*str == '\n')
            return (0);
        str++;
    } 
    return (1);
}

char *cut(char *str){
    int i;

    i = 0;
    while (str[i] != '\0')
   {
    if (str[i] == '\n')
   {
    str[i + 1] = '\0';
    return (str); 
   } 
   i++;
   } 
   return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str = "";
	char		temp[10];
	char		*aux;
	int			bytes;
	char		*t;

	str = (str == NULL) ? ft_strdup("") : str;
	bytes = 1;
	if (!end(str))
	{
		str = ft_strchr(str, '\n');
		str++;
	}
	else
		str = ft_strchr(str, '\0');
	while (end(str) && bytes > 0)
	{
		bytes = read(fd, temp, 10);
		if (bytes == -1)
			break ;
		temp[bytes] = '\0';
		aux = ft_strjoin("", temp);
		str = ft_strjoin(str, aux);
		free(aux);
	}
	aux = ft_strdup(str);
	aux = cut(aux);
	return (aux);
}

int main(void)
{
    int fd;
    char *str;
	str = "hola";
    fd = open("texto.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str[0] == '\0')
			return (0);
    	printf("%s", str);
	}
    return 0;
}