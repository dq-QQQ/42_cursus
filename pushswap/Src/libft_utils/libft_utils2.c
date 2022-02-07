

#include "../../Inc/pushswap.h"

static int	cnt_word(char const *s, char c)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (*(s + i))
	{
		if (!ft_isdigit(*(s + i)))
			if (*(s + i) != c && *(s + i) != '-')
				return (-1);
		if (*(s + i) == c)
			i++;
		else
		{
			cnt++;
			while (*(s + i) != c && *(s + i))
				i++;
		}
	}
	return (cnt);
}

static void	free_malloc(char **ret, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(*(ret + i));
		i++;
	}
	free(ret);
}

static int	cut_str(char const *s, char c, char **ret, size_t word)
{
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	while (*(s + idx1))
	{
		if (*(s + idx1) == c)
			idx1++;
		else
		{
			idx2 = 0;
			while (*(s + idx1 + idx2) != c && *(s + idx1 + idx2))
				idx2++;
			*(ret + word) = (char *)malloc(idx2 + 1);
			ft_memcpy(*(ret + word), s + idx1, idx2);
			*(*(ret + word) + idx2) = 0;
			idx1 += idx2;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**ret;

	if (!s)
		return ((void *)0);
	cnt = cnt_word(s, c);
	if (cnt == -1)
		return ((void *)0);
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	*(ret + cnt) = 0;
	if (!cut_str(s, c, ret, 0))
		return (0);
	return (ret);
}