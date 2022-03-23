/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_maps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:59:09 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:16:46 by lucasmar         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chek_map(t_sl *sl)
{
	ft_create_string_map(sl);
	if (sl->map.line < 3)
		ft_error_map(6);
	if (sl->map.columns < 3)
		ft_error_map(7);
	if ((sl->map.columns * sl->map.line) != ft_strlen(sl->map.string))
		ft_error_map(8);
	ft_count_char_map(sl);
	ft_valid_char_map(sl);
	ft_valid_wall_map(sl);
	//ft_map(sl);
	ft_printf("	▥ Valid map ✓\n\n");
	close(sl->fd);
}

void	ft_create_string_map(t_sl *sl)
{
	char	*line;
	char	*temp;

	sl->map.line = 0;
	sl->map.columns = 0;
	sl->map.string = ft_strdup("");
	if (sl->map.string == NULL)
		ft_error_map(5);
	while (1)
	{
		line = get_next_line(sl->fd);
		if (!line)
			break ;
		sl->map.line ++;
		if (sl->map.line == 1)
			sl->map.columns = ft_strlen(line) - 1;
		temp = sl->map.string;
		sl->map.string = *ft_split(ft_strjoin(temp, line), '\n');
		free (temp);
		temp = NULL;
		if (sl->map.string == NULL)
			ft_error_map(5);
	}
	free(line);
}

void	ft_count_char_map(t_sl *sl)
{
	int	count;

	count = 0;
	while (sl->map.string[count])
	{
		if (!(ft_strchr(D_VALID_CHAR, sl->map.string[count])))
					ft_error_map(10);
		if (sl->map.string[count] == '1')
			sl->map.char_1 ++;
		if (sl->map.string[count] == '0')
			sl->map.char_0 ++;
		if (sl->map.string[count] == 'C')
			sl->map.char_c ++;
		if (sl->map.string[count] == 'E')
			sl->map.char_e ++;
		if (sl->map.string[count] == 'P')
			sl->map.char_p ++;
		count++;
	}
}

void	ft_valid_char_map(t_sl *sl)
{
	if (sl->map.char_1 < 1)
		ft_error_map(9);
	if (sl->map.char_0 < 1)
		ft_error_map(9);
	if (sl->map.char_c < 1)
		ft_error_map(9);
	if (sl->map.char_e < 1)
		ft_error_map(9);
	if (sl->map.char_p < 1)
		ft_error_map(9);
}

void	ft_valid_wall_map(t_sl *sl)
{
	size_t	count_line;
	size_t	count;

	count_line = 1;
	count = 0;
	while (count_line <= sl->map.line)
	{
		while ((count) < (sl->map.columns * count_line))
		{
			if ((count_line == 1) & (sl->map.string[count] != '1'))
				ft_error_map(11);
			if ((count_line == sl->map.line) & (sl->map.string[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line - sl->map.columns))
				& (sl->map.string[count] != '1'))
				ft_error_map(11);
			if ((count == (sl->map.columns * count_line -1))
				& (sl->map.string[count] != '1'))
				ft_error_map(11);
			count ++;
		}
		count_line ++;
	}
}

void	ft_map(t_sl *sl)
{
	size_t	x;
	size_t	y;
	int	c;

	y = 1;
	c = 0;
	printf("\ncheguei\n");
	while(y <= sl->map.line)
	{
		x = 1;
		while(x <= sl->map.columns)
		{
			printf("\ncheguei\n");
			sl->map.map[x][y] = sl->map.string[c];
			printf("%c",sl->map.map[x][y]);
			x++;
		}
		y++;
		printf("\n");
	}

}
