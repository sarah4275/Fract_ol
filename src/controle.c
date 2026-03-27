#include "../includes/fractol.h"

int handle_no_event(void *data)
{
    (void)data;
    return (0);
}

int key_press(int keysym, t_data *data)
{
    if (keysym == XK_Escape || keysym == XK_x)
        close_window(data);
    if (keysym == XK_m)
        draw_fractal(data, "mandelbrot", 0, 0);
    if (keysym == XK_j)
        draw_fractal(data, "julia", -0.7, 0.27015);
    if (keysym == XK_s)
        draw_fractal(data, "burning_ship", 0, 0);
    if (keysym == XK_r)
    {
        // Reset zoom
        data->zoom.zoom = 1.0;
        data->zoom.offset_x = 0;
        data->zoom.offset_y = 0;
        data->zoom.iter = 50;
        redraw_current_fractal(data);
    }
    return (0);
}
void	zoom(t_zoom *zoomer, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		zoomer->offset_x = (x / zoomer->zoom + zoomer->offset_x) - (x
				/ (zoomer->zoom  * zoom_level));
		zoomer->offset_y = (y / zoomer->zoom + zoomer->offset_y)  - (y
				/ (zoomer->zoom * zoom_level));
		zoomer->zoom  *= zoom_level;
	}
	else if (zoom == -1)
	{
		zoomer->offset_x = (x / zoomer->zoom + zoomer->offset_x) - (x
				/ (zoomer->zoom  / zoom_level));
		zoomer->offset_y = (y / zoomer->zoom + zoomer->offset_y)  - (y
				/ (zoomer->zoom / zoom_level));
		zoomer->zoom  /= zoom_level;
	}
	else
		return ;
}

int	mouse_hook(int button, int x, int y, t_data *data, t_zoom *zoomer)
{
	if (button == 4)
		zoom(zoomer, x, y, 1);
	else if (button == 5)
		zoom(zoomer, x, y, -1);
	redraw_current_fractal(data);
	return (0);
}
/*int mouse_hook(int button, int x, int y, t_data *data)
{
    t_zoom *zoomer;
    
    printf("Bouton: %d, Position: (%d, %d)\n", button, x, y);
    
    zoomer = &data->zoom;
    
    // Scroll UP (zoom in)
    if (button == 4)
    {
        zoomer->offset_x = (x / zoomer->zoom + zoomer->offset_x) 
                          - (x / (zoomer->zoom * 1.3));
        zoomer->offset_y = (y / zoomer->zoom + zoomer->offset_y) 
                          - (y / (zoomer->zoom * 1.3));
        zoomer->zoom *= 1.3;
        if (zoomer->iter < MAX_ITER)
            zoomer->iter++;
        redraw_current_fractal(data); 
    }
    // Scroll DOWN (zoom out)
    else if (button == 5)
    {
        zoomer->offset_x = (x / zoomer->zoom + zoomer->offset_x) 
                          - (x / (zoomer->zoom / 1.3));
        zoomer->offset_y = (y / zoomer->zoom + zoomer->offset_y) 
                          - (y / (zoomer->zoom / 1.3));
        zoomer->zoom /= 1.3;
        if (zoomer->iter > 10)
            zoomer->iter--;
        redraw_current_fractal(data); 
    }
    // Clic gauche - Change pour Julia
    else if (button == 1)
    {
        draw_fractal(data, "julia", -0.7, 0.27015);
    }
    // Clic droit - Reset
    else if (button == 3)
    {
        data->zoom.zoom = 1.0;
        data->zoom.offset_x = 0;
        data->zoom.offset_y = 0;
        redraw_current_fractal(data); 
    }
    
    return (0);
}*/

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return (0);
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