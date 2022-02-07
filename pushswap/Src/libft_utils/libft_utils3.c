#include "../../Inc/pushswap.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	if ((ret = (char *)malloc(len + 1)) == 0)
		return (0);
	*(ret + len) = 0;
	while (i < len)
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	return (ret);
}