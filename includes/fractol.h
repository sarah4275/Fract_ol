#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *img_data;
    int     bpp;
    int     line_len;
    int     endian;
    int     w;
    int     h;
    int     x;
    int     y;
    int     color;
    
    // Paramètres du plan complexe
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
}   t_data;

typedef struct s_complex
{
    double re;
    double im;
}   t_complex;

enum fractal_type { MANDELBROT, JULIA, BURNING_SHIP };

int     handle_no_event(void *data);
int     key_press(int keysym, t_data *data);
int     mouse_hook(int button, int x, int y, t_data *data);
int     close_window(t_data *data);

t_complex add_complex(t_complex c1, t_complex c2);
t_complex mult_complex(t_complex c1, t_complex c2);
double  module_complex(t_complex c);
t_complex suite_complexe(t_complex z, t_complex c);
t_complex suite_complexebu(t_complex z, t_complex c);
t_complex pixel_to_complex(int x, int y, t_data *data);

int     draw_fractal(t_data *data, char *query, double cx, double cy);
void    calculate_mandelbrot(t_data *data, enum fractal_type ftype,
                             t_complex c, int pixel_x, int pixel_y,
                             double cx, double cy);
void    put_color_to_pixel(t_data *data, int x, int y, int color);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
void        ft_putendl_fd(char *s, int fd);

#endif