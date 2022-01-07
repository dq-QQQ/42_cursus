#include "solong.h"


int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path = "./asset/player.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
