#include "../includes/fractol.h"

int handle_no_event(void *data)
{
    (void) data;
    return (0);
}

int key_press(int keysym, t_data *data)
{
    if (keysym == XK_Escape || keysym == XK_x)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    if (keysym == XK_m)
        draw_fractal(data, "mandelbrot", data->x, data->y);
    if (keysym == XK_j)
        draw_fractal(data, "julia", data->x, data->y);
    if (keysym == XK_s)
        draw_fractal(data, "burning_ship", data->x, data->y);
     if (keysym == XK_r)
        mlx_destroy_display(data->mlx_ptr);
    if (keysym == XK_Right)
        data->x++;
    if (keysym == XK_Left)
        data->x--;
    if (keysym == XK_Up)
        data->y++;
    if (keysym == XK_Down)
        data->y--;
    return (0);
}

int mouse_hook(int button, int x, int y, t_data *data)

{
     printf("Bouton: %d, Position: (%d, %d)\n", button, x, y);
    if (button == 4)
    {
        x++;
        y++;
    }
    else if (button == 5)
    {
        x--;
        y--;
    }
    else if(button == 1)
        draw_fractal(data, "julia", data->x, data->y);
    else if (button == 3)
        mlx_destroy_display(data->mlx_ptr);
    return (0);
}

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr,data->win_ptr );
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return(0);
}
void put_color_to_pixel(t_data *data, int x, int y, int color)
{
    int pixel_index;
    
    if (x < 0 || x >= data->w || y < 0 || y >= data->h)
        return;
    
    pixel_index = y * data->line_len + x * (data->bpp / 8);
    
    data->img_data[pixel_index + 0] = (color) & 0xFF;
    data->img_data[pixel_index + 1] = (color >> 8) & 0xFF; 
    data->img_data[pixel_index + 2] = (color >> 16) & 0xFF;
    data->img_data[pixel_index + 3] = 0;                    
}

