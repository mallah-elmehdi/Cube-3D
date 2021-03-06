/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:28:06 by emallah           #+#    #+#             */
/*   Updated: 2020/10/24 20:26:53 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ERR -1
# define SZ 32
# define SPT 20
# define SZ_PY 1
# define W_S 10
# define T_S 10
# define AGL 30
# define PI 3.14159265358979323846

# define C_0 0x00F9F5
# define C_1 0xF94000
# define C_2 0x85C85C
# define C_PL 0xF10092

# define RT_ROT 124
# define LT_ROT 123
# define UP 13
# define DN 1
# define LT 0
# define RT 2
# define ESC 53

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_info
{
	char		*so_txt;
	char		*we_txt;
	char		*no_txt;
	char		*ea_txt;
	char		*s_txt;
	int			rsl[2];
	int			flr;
	int			cel;
}				t_info;

typedef struct	s_img
{
	int			rsl[2];
	int			bpp;
	int			sz_ln;
	int			e;
}				t_img;

typedef struct	s_ply
{
	float		x;
	float		y;
	float		wlk;
	float		trn;
	float		dgr;
}				t_ply;

typedef struct	s_ray
{
	int			r;
	int			l;
	int			u;
	int			d;
	int			v;
	int			x;
	int			y;
	float		agl;
}				t_ray;

typedef struct	s_hit
{
	float		x_v;
	float		y_v;
	float		x_h;
	float		y_h;
}				t_hit;

typedef struct	s_txt
{
	int			*g_no;
	int			*g_so;
	int			*g_ea;
	int			*g_we;
	int			*g_s;
}				t_txt;

typedef struct	s_fre
{
	char		*m1;
	char		*m2;
	char		*m3;
	char		*m4;
	char		*m5;
}				t_fre;

typedef struct	s_bmp
{
	char		*sgn;
	int			size;
	int			oft;
	int			bmh;
	int			pii;
	int			bpp;
	int			zr;
}				t_bmp;

typedef struct	s_spt
{
	int			t_x;
	int			t_y;
	int			m_x;
	int			m_y;
	int			w_x;
	int			w_y;
	int			dr;
	float		agl;
	float		ray;
	float		ln_h;
	int			st;
}				t_spt;

void			*g_mlx;
void			*g_mlx_win;
void			*g_mlx_img;
void			*g_param;
char			**g_map;
char			*g_file_name;
int				*g_mlx_str;
float			*g_lgst;
int				g_map_start;
int				g_map_height;
int				g_map_width;
int				g_gnl;
int				g_bmp;
int				g_bmp_fd;
float			g_ystp;
float			g_xstp;

int				g_hm_spt;
int				g_s;
int				g_res_x;
int				g_res_y;
int				g_scl;
int				g_fre_mem;

struct s_img	g_img;
struct s_info	g_info;
struct s_ply	g_ply;
struct s_ray	g_ray;
struct s_txt	g_txt;
struct s_hit	g_hit;
struct s_bmp	g_bmp_header;
struct s_spt	*g_spt_s;
struct s_fre	g_fre;

size_t			ft_strlen(char *str);
char			**ft_split(char *s, char c);
char			*ft_calloc(int type, int size);
void			free_it(char **s);
void			free_it_double(char **s, int counter);
void			ft_strtrim(char **line);
void			ft_strtrim_one_side(char **line);
void			ft_dimension(char *line, int *x, int *y);
void			ft_initilisation(char *file);
void			ft_game_var_init(void);
void			ft_ply_init(void);
void			ft_ray_dir(float agl);
void			ft_hit_init_v(float *x, float *y, int *add, float o);
void			ft_hit_init_h(float *x, float *y, int *add, float o);
void			ft_init_map_draw(void);
void			ft_rays(void);
void			ft_is_spt(void);
void			ft_spt(void);
void			ft_sort_spt(void);
void			ft_draw_help_1(int i, int w_x);
void			ft_draw_help_2(int i, int w_x);
void			ft_draw_spt(void);
void			ft_draw_cel_flr(void);
void			ft_draw_with_txt(int y, int x, int ln_h);
void			ft_bmp_header(void);
void			ft_draw_bmp(void);
void			ft_fill_map(char **map, char *line);
void			ft_free_mem(void);
void			ft_add_mem_free(char **str);
int				ft_update_img(int key_code);
int				check_out(char **str1, char **str2, int *i);
int				fill_it(char **string1, char **string2, int *h, int *s);
int				re_alloc(char **str);
int				len(char *s);
int				after_check(char **str1, char **str2, int *i);
int				get_next_line(int fd, char **line);
int				index_front(char *str);
int				index_back(char *str);
int				str_table_length(char *s, char c);
int				string_length(char *s, char c);
int				ft_atoi(char *s);
int				ft_strlen_trim(char *str);
int				ft_err(char *str);
int				ft_read_file(void);
int				ft_resolution_syntax(char *line);
int				ft_resolution_errors(char *line);
int				ft_resolution_add(char *line);
int				ft_resolution(char *line);
int				ft_info_reader(char **line);
int				ft_color_syntax(char *line);
int				ft_color_errors(char **rgb);
int				ft_color(char *line, char c);
int				ft_is_int(char c);
int				ft_texture(char *line);
int				ft_texture_str(char *line, char **texture, int start);
int				ft_texture_add(char *line, char *txt);
int				ft_is_info_done(void);
int				ft_is_player(char c);
int				ft_map_reader(char *line);
int				ft_read_map();
int				ft_read_info(void);
int				ft_is_whitespace(char c);
int				ft_is_map(char c);
int				ft_height_width_map(void);
int				ft_map_errors(void);
int				ft_is_map_has_empty_line(void);
int				ft_map_check_1(int i, int j);
int				ft_map_check_3(int i, int j);
int				ft_check_map(void);
int				ft_game(void);
int				ft_game_loop(void);
int				ft_quit(void);
int				ft_allowed_key(int key);
int				ft_is_wall(int x, int y);
int				ft_y(float i);
int				ft_collision(int spd);
int				ft_game_texture(void);
int				ft_check_input(int ac, char **av);
int				ft_bmp_init(void);
int				ft_has_spt(int i, int j);
float			ft_cos(float o);
float			ft_sin(float o);
float			ft_tan(float o);
float			ft_hit(float o);
float			ft_v_hit(float o);
float			ft_h_hit(float o);
float			ft_atan(float o);
float			ft_spt_agl(float x, float y, int *a);
void			ft_spt_utile(int i, int x, int a);
void			ft_ply_agl(char c);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int				ft_stridt(char *str);

#endif
