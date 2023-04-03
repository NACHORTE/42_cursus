/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:20:37 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/02 20:20:37 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *x, int size)
{
	int	tmp;

	if (size >= 2)
	{
		tmp = x[0];
		x[0] = x[1];
		x[1] = x[0];
	}
}

void	push(int *x, int *y, int sizex, int sizey)
{
	int	tmp;
	int	pos;

	pos = 0;
	if (sizey != 0)
	{
		tmp = y[0];
		while (pos != (sizey - 1))
		{
			y[pos] = y[pos + 1];
			pos++;
		}
		pos = 0;
		while (pos != sizex)
		{
			x[pos + 1] = x[pos];
			pos++;
		}
		x[0] = tmp;
	}
}

void	rotate(int *x, int sizex)
{
	int	pos;
	int	tmp;

	pos = 0;
	tmp = x[0];
	while (pos < sizex - 1)
	{
		x[pos] = x[pos + 1];
		pos++;
	}
	x[sizex - 1] = tmp;
}

void	reverse(int *x, int sizex)
{
	int	pos;
	int	tmp;

	sizex--;
	pos = sizex;
	tmp = x[pos];
	while (pos != 0)
	{
		x[pos] = x[pos - 1];
		pos--;
	}
	x[0] = tmp;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
