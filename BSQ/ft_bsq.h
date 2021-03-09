/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dareias- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:19:24 by dareias-          #+#    #+#             */
/*   Updated: 2020/12/14 11:35:26 by dareias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 500000

typedef struct s_fline	t_fline;
struct	s_fline
{
	int		nbr_lines;
	char	empty;
	char	obstacle;
	char	full;
};

int		ft_basic_atoi(char *fl, int size);
void	ft_map_error(void);
int		ft_first_line(char *map, int fline_size, t_fline *fline);
char	*ft_map_wo_fline(char *fullmap, int fline_size);
int		ft_strlen(char *str);
int		ft_save_map(char *fullmap);
int		ft_fl_size(char *fullmap);
int		ft_map_is_valid(char *fieldmap, t_fline *fline);
int		ft_is_printable(char c);
int		**ft_map_to_arr(char *map, int nbr_lines, char empty);
int		**ft_find_solution(int **arr, int row_len);
int		ft_row_len(char *map);
void	ft_print_solution(int **arr, int *sol, int row_len, t_fline *fline);
int		*ft_bsq(int **arr, int row_len);
void	ft_sanitize(int **arr);
void	ft_stdin(void);
void	ft_file_input(char *filename);
char	*ft_file_to_str(char *filename);

#endif
