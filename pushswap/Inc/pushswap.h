/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:26:52 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/14 17:50:40 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

typedef struct s_stack
{
	int					cnt;
	struct s_stack_node	*top;
	struct s_stack_node	*bottom;
}				t_stack;

typedef struct s_big_small
{
	int	big;
	int	small;
}				t_big_small;

/*
** libft_utils.c
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_atoi(const char *str, t_stack *stack);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

/*
** libft_utils2.c
*/
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

/*
** libft_utils3.c
*/
char	*ft_strdup(const char *s1);
void	ft_putstr(char *s);

/*
** ps_operation.c
*/
void	move_data(t_stack *from, t_stack *to);
void	switch_data(t_stack *stack);
void	rotate_data(t_stack *stack);// ra rb
void	reverse_rotate_data(t_stack *stack);// rra rrb
void	operation_flags(t_stack *a, t_stack *b, t_stack *inst, int flag);

/*
** stack_operation.c
*/
void	insert_front(t_stack *stack, int data);
void	insert_back(t_stack *stack, int data);
void	delete_front(t_stack *stack);
void	delete_back(t_stack *stack);

/*
** stack_operation2.c
*/
t_stack	*create_stack(void);
void	delete_stack(t_stack *stack);
void	clear_stack(t_stack *stack);

/*
** ps_init_stack.c
*/
t_stack	*init_stack(char **argv);

/*
** ps_utils.c
*/
int		is_overlap(t_stack *stack, int data);
void	end_program(int flag, t_stack *stack);
int		is_sorted(t_stack *stack);
void	display(int flag);
void	display_instruction(t_stack *stack);

/*
** ps_utils2.c
*/

void	init_big_small(t_big_small *bs, t_stack *stack);
void	until_three(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs);

/*
** ps_check_inst.c
*/
void	check_inst(t_stack *stack);
#endif
