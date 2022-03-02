/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:21:46 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/02 16:11:01 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	number;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long long int	nb;

	nb = n;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 2147483648)
		write(1, "2147483648", 11);
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
		else
			ft_putchar(nb + '0');
	}
}

void	bin_to_str(int signal)
{
	int			i;
	static int	counter;
	static int	n;

	i = 0;
	if (!n)
		n = 128;
	if (signal == SIGUSR1)
	{
		i = 1;
		counter++;
	}
	if (signal == SIGUSR2)
		counter++;
	if (i == 1)
		number += n;
	n = n / 2;
	if (counter == 8)
	{
		ft_putchar(number);
		number = 0;
		counter = 0;
		n = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, bin_to_str);
	signal(SIGUSR2, bin_to_str);
	while (1)
		pause();
}
