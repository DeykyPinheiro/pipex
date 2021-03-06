/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:26:33 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 19:46:41 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb * size > 2147483647)
		return (0);
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	ft_memset(result, 0, nmemb * size);
	return (result);
}
