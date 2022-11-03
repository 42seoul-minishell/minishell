/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:09:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/11/02 14:10:52 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int	is_have(char *str, char sep)
{
	if (ft_strchr(str, sep))
		return TRUE;
	return FALSE;
}

/** 
	읽으면서 파이프 기준으로 자르고 앞에 있던 놈들 prev, 뒤에 놈들 next, 재귀
	뒤에 놈들 다시 들어와서 똑같은 짓하고 재귀

	echo asdoada | cat asdjiasbfdiua | echo asdasdjiasbd | ls -al 

	lst
	ls -al 
*/

void	tokenizing(t_doubly_list *lst, char *str)
{
	t_doubly_node	*node;

	// 토큰화가 필요없는 경우
	if (str[0] == '\0')
		return ;
	// 문자열 앞에 공백 제거
	while (*str == ' ')
		str++;
	// 파이프가 존재하는 경우
	if (is_have(str, '|'))
	{
		split(lst, str, '|');
		node = lst->header.next;
		// while(node)
		// {
			/*
				노드 내 값에 각각 '"', '(', ')' 존재하는지 확인하여 split
				doubly list 들을 모아두는 구조제를 사용한다고 할 때 얼마나 많은 doubly list가 생성될 지 모름
				또한 이를 관리를 어떻게 해야하는지에 대한 이슈도 존재
				==> 각각 나누어둔 것을 circular 가 아닌 linked로 생성하여 기존 circular 리스트에 추가하는 방식은 어떨지?
			*/
		// }
	}
	// quotes가 존재하는 경우
	if (is_have(str, '"'))
		split(lst, str, '"');
}
