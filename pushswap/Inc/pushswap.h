/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:26:52 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 10:13:49 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef	struct		s_stack_node
{
	int				data;
	struct	s_stack_node *prev;
	struct	s_stack_node	*next;
}					t_stack_node;

typedef	struct		s_stack
{
	int				cnt;
	struct	s_stack_node *top;
	struct	s_stack_node *bottom;
}					t_stack;

typedef	struct		s_mos
{
	int 			more;
	int 			less;
	int 			cn;
}					t_mos;

int			ft_atoi(const char *str);
int	        ft_isdigit(int c);
size_t	    ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void	ft_lstadd_back(t_stack **lst, t_stack *stack);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	init_stack(char *s, t_stack **stack);
void deletestack(t_stack *stack);
int	is_overlap(t_stack *stack, int data);
void ft_putstr();//에러출력, 실행 명령어 출력
void end_program(int flag);
int			cnt_element(t_stack *stack);
int is_sorted(t_stack *stack);
void push_stack();//스택에 푸시하기
void pop_stack();//스택에서 팝하기

void move_stackdata();//pa pb
void switch_top_two();// sa, sb
void rotate_data();// ra rb
void r_rotate_data();// rra rrb

void combine_instructions();// rr rrr

void check_top_two(); //  switch 해야하는 조건인지 확인


#endif
