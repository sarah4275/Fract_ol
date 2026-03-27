#include "../includes/fractol.h"

int draw_fractal(t_data *data, char *query, double cx, double cy)
{
    int pixel_x;
    int pixel_y;
    t_complex c;
    enum fractal_type  ftype;

    if (ft_strncmp(query, "mandelbrot", 10) == 0)
        ftype = MANDELBROT;
    else if (ft_strncmp(query, "julia", 5) == 0)
        ftype = JULIA;
    else if (ft_strncmp(query, "burning_ship", 12) == 0)
        ftype = BURNING_SHIP;
    else 
    {
        ft_putendl_fd("AVAILABLE FRACTOL: MANDELBROT, JULIA, BURNING_SHIP", 1);
        close_window(data);
        return (0);
    }
    
    pixel_y = 0;
    while (pixel_y < data->h)
    {
        pixel_x = 0;
        while (pixel_x < data->w)
        {
            c = pixel_to_complex(pixel_x, pixel_y, data);
            calculate_mandelbrot(data, ftype, c, pixel_x, pixel_y, cx, cy);
            pixel_x++;
        }
        pixel_y++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0,0);
    return (0);
}
void redraw_current_fractal(t_data *data)
{
    if (data->current_fractal == MANDELBROT)
        draw_fractal(data, "mandelbrot", 0, 0);
    else if (data->current_fractal == JULIA)
        draw_fractal(data, "julia", data->julia_cx, data->julia_cy);
    else if (data->current_fractal == BURNING_SHIP)
        draw_fractal(data, "burning_ship", 0, 0);
}
/*int draw_fractal(t_data *data, char *query, double cx, double cy)
{
    int pixel_x;
    int pixel_y;
    t_complex c;
    enum fractal_type ftype;
    
    printf("Entering draw_fractal\n");
    
    // Détermine le type de fractale
    if (ft_strncmp(query, "mandelbrot", 10) == 0)
        ftype = MANDELBROT;
    else if (ft_strncmp(query, "julia", 5) == 0)
        ftype = JULIA;
    else if (ft_strncmp(query, "burning_ship", 12) == 0)
        ftype = BURNING_SHIP;
    else
    {
        ft_putendl_fd("AVAILABLE FRACTALS: mandelbrot, julia, burning_ship", 1);
        close_window(data);
        return (0);
    }
    
    printf("Fractal type determined: %d\n", ftype);
    printf("Width: %d, Height: %d\n", data->w, data->h);
    printf("Starting pixel loop...\n");
    
    // Boucle sur tous les pixels
    pixel_y = 0;
    while (pixel_y < data->h)
    {
        if (pixel_y % 100 == 0)  // Affiche la progression tous les 100 pixels
            printf("Line %d / %d\n", pixel_y, data->h);
        
        pixel_x = 0;
        while (pixel_x < data->w)
        {
            c = pixel_to_complex(pixel_x, pixel_y, data);
            calculate_mandelbrot(data, ftype, c, pixel_x, pixel_y, cx, cy);
            pixel_x++;
        }
        pixel_y++;
    }
    
    printf("Pixel loop done, displaying image...\n");
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
    printf("Image displayed!\n");
    
    return (0);
}*/

void calculate_mandelbrot(t_data *data, enum fractal_type ftype, t_complex c, int pixel_x, int pixel_y, double cx, double cy)
{

    int i;
    t_complex z;
    
    i = 0;
    if (ftype == MANDELBROT)
    {
        z.re = 0;
        z.im = 0;
        while (module_complex(z) < 4.0 && i < MAX_ITER)
        {
            z = suite_complexe(z, c);
            i++;
        }
    }
    else if (ftype == JULIA)
    {
        z = c;
        t_complex julia_constant;
        julia_constant.re = cx;
        julia_constant.im = cy;
        while (module_complex(z) < 4.0 && i <  MAX_ITER)
        {
            z = suite_complexe(z, julia_constant);
            i++;
        }
    }

    else if (ftype == BURNING_SHIP)
    {
        z = c;
        while (module_complex(z) < 4.0 && i <  MAX_ITER)
        {
            z = suite_complexebu(z, c);
            i++;
        }
    }
    if ( i == MAX_ITER)
    put_color_to_pixel(data, pixel_x, pixel_y, 0x000000);
    else
    put_color_to_pixel(data, pixel_x, pixel_y, (data->color *i));
    
}