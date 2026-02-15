#include "../includes/fractol.h"

/*int main(void)
{
    t_data  data;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Test affichage");
    if (!data.win_ptr)
    {
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
        free(data.mlx_ptr);
        return(1);
    }

     // Hooks d'événements
    mlx_string_put(data.mlx_ptr, data.win_ptr, 80, 40, 0xFF0000, "Bonjour");
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_press, &data);
    mlx_hook(data.win_ptr, DestroyNotify, 0, close_window, &data);
    
    // Affiche l'image (vide pour l'instant)
    //mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
    
    mlx_loop(data.mlx_ptr);
    return (0);

}*/

#include "../includes/fractol.h"

void init_fractal_params(t_data *data)
{
    printf("Init params...\n");  // ← DEBUG
    data->w = 800;
    data->h = 600;
    data->min_re = -2.5;
    data->max_re = 1.0;
    data->min_im = -1.25;
    data->max_im = 1.25;
    data->color = 0x001188;
    data->x = 0;
    data->y = 0;
    printf("Init params OK\n");  // ← DEBUG
}

int main(int argc, char **argv)
{
    t_data data;
    
    printf("Début du programme\n");  // ← DEBUG
    
    if (argc < 2)
    {
        printf("Usage: ./fractol <type>\n");
        printf("Types: mandelbrot, julia, burning_ship\n");
        return (1);
    }
    
    printf("MLX init...\n");  // ← DEBUG
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        printf("MLX init failed!\n");
        return (1);
    }
    printf("MLX init OK\n");  // ← DEBUG
    
    printf("Creating window...\n");  // ← DEBUG
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Fractol");
    if (!data.win_ptr)
    {
        printf("Window creation failed!\n");
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }
    printf("Window OK\n");  // ← DEBUG
    
    printf("Creating image...\n");  // ← DEBUG
    data.img_ptr = mlx_new_image(data.mlx_ptr, 800, 600);
    if (!data.img_ptr)
    {
        printf("Image creation failed!\n");
        mlx_destroy_window(data.mlx_ptr, data.win_ptr);
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (1);
    }
    printf("Image OK\n");  // ← DEBUG
    
    data.img_data = mlx_get_data_addr(data.img_ptr, &data.bpp,
                                       &data.line_len, &data.endian);
    printf("Image data: %p\n", data.img_data);  // ← DEBUG
    
    init_fractal_params(&data);
    
    printf("Drawing fractal: %s\n", argv[1]);  // ← DEBUG
    
    if (ft_strncmp(argv[1], "julia", 5) == 0)
        draw_fractal(&data, "julia", -0.7, 0.27015);
    else
        draw_fractal(&data, argv[1], 0, 0);
    
    printf("Fractal drawn, registering hooks...\n");  // ← DEBUG
    
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_press, &data);
    mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, mouse_hook, &data);
    mlx_hook(data.win_ptr, DestroyNotify, 0, close_window, &data);
    
    printf("Entering loop...\n");  // ← DEBUG
    mlx_loop(data.mlx_ptr);
    
    return (0);
}