#include "../../include/cub3D.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
        return;
        
    dst = data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
void draw_column(t_data *data, int x, int draw_start, int draw_end)
{
    int y;
    
    y = draw_start;    
    if (draw_start < 0)
        draw_start = 0;
    if (draw_end >= WINDOW_HEIGHT)
        draw_end = WINDOW_HEIGHT - 1;
    
    while (y <= draw_end)
    {
        my_mlx_pixel_put(data, x, y, 0xFF0000); // Rouge pour le mur
        y++;
    }
}