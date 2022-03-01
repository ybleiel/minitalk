/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:21:46 by ybleiel           #+#    #+#             */
/*   Updated: 2022/03/01 16:14:28 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	sigusr_input1()
{
	ft_putchar('1');
}

static void	sigusr_input0()
{
	ft_putchar('0');
}

int main()
{
	int pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, sigusr_input1);
	signal(SIGUSR2, sigusr_input0);
	while (1)
		pause();
}