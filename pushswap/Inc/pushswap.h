/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:26:52 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 13:29:00 by kyujlee          ###   ########.fr       */
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


/*
** stack_operation.c
*/
void insert_front(t_stack* stack, int data);
void insert_back(t_stack* stack, int data);
void delete_front(t_stack* stack);
void delete_back(t_stack* stack);

/*
** stack_operation2.c
*/
t_stack	*create_stack(void);
void delete_stack(t_stack *stack);

/*
** ps_init_stack.c
*/
t_stack* init_stack(char **argv);


/*
** libft_utils.c
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_atoi(const char *str, t_stack* stack);
int	       ft_isdigit(int c);
size_t	    ft_strlen(const char *s);

/*
** libft_utils2.c
*/
char		**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);


/*
** libft_utils3.c
*/
char	*ft_strdup(const char *s1);



/*
** ps_utils.c
*/
int	is_overlap(t_stack *stack, int data);
void end_program(int flag, t_stack *stack);
int is_sorted(t_stack *stack);





void move_stackdata();//pa pb
void switch_data(t_stack *stack);
void rotate_data();// ra rb
void reverse_rotate_data();// rra rrb

void combine_instructions();// rr rrr

void check_top_two(); //  switch 해야하는 조건인지 확인


#endif
