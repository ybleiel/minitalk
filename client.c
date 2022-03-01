/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:17:46 by ybleiel           #+#    #+#             */
/*   Updated: 2022/02/28 16:57:54 by ybleiel          ###   ########.fr       */
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
	int len;
	char *binary;
	int i;
	int j;
	char c;

    len = strlen(str);
    binary = malloc(len*8 + 1);
	i = 0;
    binary[0] = '\0';
	if(str == NULL)
		exit(0);
	while (++i < len)
	{
		c = str[i];
		while (j >= 0)
		{
			if (c & (1 << j))
				kill(pid, SIGUSR1);
			else 
				kill(pid, SIGUSR2);
		}
	}
}

int main(int argc, char **argv)
{
	int pid;
	char *str;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	str_to_binary(str, pid);
}
