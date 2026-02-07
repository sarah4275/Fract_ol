#include "minilibx-linux/mlx.h"

int main (void)
{
  
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
    mlx_loop(win);
	return (0);
}