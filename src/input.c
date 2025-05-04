/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 05:52:18 by olopez-s          #+#    #+#             */
/*   Updated: 2025/05/03 01:57:26 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//parseo de argumentos
int	ft_parse(char *s)
{
	int	i;
	int	dot;
	int	flag;

	i = 0;
	dot = 0;
	flag = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '.')
		return (1);
	while (((s[i] >= '0' && s[i] <= '9') || s[i] == '.') && dot <= 1)
	{
		if (s[i] == '.')
			dot++;
		i++;
		flag = 1;
	}
	if ((s[i] == '\0' && flag == 1)
		&& (ft_atof(s) <= 3.4028235e+38 && ft_atof(s) >= -3.4028235e+38))
		return (0);
	return (1);
}

static int	ft_while_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (i);
}

//ascii to float => convierte una string en un número float
float	ft_atof(char *s)
{
	int		i;
	int		sign;
	float	div;
	float	num;
	float	ber;

	sign = 1;
	div = 10.0;
	num = 0.0;
	ber = 0.0;
	i = ft_while_space(s);
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		num = (s[i++] - '0') + (num * 10);
	if (s[i++] != '.')
		return (num * sign);
	while (s[i] >= '0' && s[i] <= '9')
	{
		ber += ((s[i++] - '0') / div);
		div *= 10;
	}
	return ((num + ber) * sign);
}

//comparar dos strings
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

//imprimir una string
void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	write(1, s, i);
}
