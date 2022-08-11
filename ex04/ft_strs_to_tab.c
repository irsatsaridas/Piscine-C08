/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:43:25 by isaridas          #+#    #+#             */
/*   Updated: 2022/08/10 02:43:24 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*news;
	int		i;

	i = 0;
	news = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (src[i])
	{
		news[i] = src[i];
		i++;
	}
	news[i] = '\0';
	return (news);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;

	ptr = malloc(size(t_stock_str * (ac + 1)));
	if (ptr == NULL)
		return (NULL);
	ptr[ac--].str = 0;
	while (ac >= 0)
	{
		ptr[ac].size = ft_strlen(av[ac]);
		ptr[ac].str = av[ac];
		ptr[ac].copy = ft_strdup(av[ac]);
		ac--;
	}
	return (ptr);
}
