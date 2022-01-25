/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/01/25 19:24:47 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"


t_stack *init_stack(char *str)
{
	char *tmp_ptr;
	char *tmp_str;
	int i;
	t_stack *ret;
	t_stack tmp;

	ret = (t_stack *)malloc(sizeof(t_stack));
	while (str){
		if (ft_isdigit(*str)){//숫자면 1 아니면 0(숫자면)
			tmp_ptr = str;
			while (ft_isdigit(*tmp_ptr))// 숫자 아닐때까지 가서
				tmp_ptr++;
			tmp_str = (char *)malloc(tmp_ptr - str + 1);
			tmp_str[tmp_ptr - str] = '\0';
			i = 0;
			while (tmp_ptr != str)//복사
				tmp_str[i++] = *(str++);
			tmp.data = ft_atoi(tmp_str);
			ft_lstadd_back(&ret, &tmp);
			free(tmp_str);
		}
		else
			str++;
	}
	return (ret);
}


int				main(int argc, char **argv)
{
	t_mos ms;
	t_stack *st;

	ms.less = 0;
	ms.more = 0;
	ms.cn = 0;
	st = 0;
	if (argc < 2)
		return (0);
	st = init_stack(argv[1]);
	write (1, "ho", 2);
}