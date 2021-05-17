#include <stdio.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return ((void *)0);
	while (n-- > 0)
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	return (dst);
}


char	*my_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if ((ret = (char *)malloc(len_1 + len_2 + 1)) == 0)
		return (0);
	*(ret + len_1 + len_2) = 0;
	ft_memcpy(ret, s1, len_1);
	ft_memcpy(ret + len_1, s2, len_2);
	return (ret);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char		*join_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	free((char *)s1);
	return (rtn);
}

int main(){
	char const a[] = "hello";
	char const b[] = "my name";
	char const c[] = "hello";
	char const d[] = "my name";
	printf("my: %s\n\n", my_strjoin(a,b));
	printf("nomy: %s\n\n", join_str(a,b));
}
