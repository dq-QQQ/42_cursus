/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:26:52 by kyujlee           #+#    #+#             */
/*   Updated: 2022/01/26 11:24:28 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_stack
{
	int				data;
	struct	s_stack	*next;
}					t_stack;

typedef	struct		s_mos
{
	int 			more;
	int 			less;
	int 			cn;
}					t_mos;

t_stack	*ft_lstlast(t_stack *lst);
int			ft_atoi(const char *str);
int	        ft_isdigit(int c);
size_t	    ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void	ft_lstadd_back(t_stack **lst, t_stack *stack);

void check_overlap();//중복된 숫자 확인
void ft_putstr();//에러출력, 실행 명령어 출력



void push_stack();//스택에 푸시하기
void pop_stack();//스택에서 팝하기

void move_stackdata();//pa pb
void switch_top_two();// sa, sb
void rotate_data();// ra rb
void r_rotate_data();// rra rrb

void combine_instructions();// rr rrr

void check_top_two(); //  switch 해야하는 조건인지 확인


#endif
