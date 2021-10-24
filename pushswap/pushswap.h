/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:26:52 by kyujlee           #+#    #+#             */
/*   Updated: 2021/10/24 17:46:02 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>


void ft_atoi();// 숫자 추출
void check_overlap();//중복된 숫자 확인
void ft_putstr();//에러출력, 실행 명령어 출력

void init_stack();//들어온 숫자 초기화

void push_stack();//스택에 푸시하기
void pop_stack();//스택에서 팝하기

void move_stackdata();//pa pb
void switch_top_two();// sa, sb
void rotate_data();// ra rb
void r_rotate_data();// rra rrb

void combine_instructions();// rr rrr

void check_top_two(); //  switch 해야하는 조건인지 확인
