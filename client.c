/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:17:46 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/02 15:57:42 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	return (j * m);
}

void	str_to_binary(char *str, int pid)
{
	unsigned char	mask;
	int				i;

	i = 0;
	if (str == NULL)
		exit(0);
	while (str[i])
	{
		mask = 0b10000000;
		while (mask)
		{
			if (mask & str[i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(2000);
			mask >>= 1;
		}
	i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	str_to_binary(str, pid);
}
