#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width;
    int     img_height;
    int     piece_width;
    int     piece_height;
    int     current_piece_x;
    int     current_piece_y;
} t_data;

// Bir parçayı çizmek için fonksiyon
void draw_piece(t_data *data, int x, int y, int src_x, int src_y)
{
    int i, j;
    char *pixel_data = mlx_get_data_addr(data->img, &(int){0}, &(int){0}, &(int){0});
    
    for (i = 0; i < data->piece_height; i++)
    {
        for (j = 0; j < data->piece_width; j++)
        {
            int color = *(int *)(pixel_data + ((src_y + i) * data->img_width + (src_x + j)) * 4);
            mlx_pixel_put(data->mlx, data->win, x + j, y + i, color);
        }
    }
}

// Her karede farklı bir parçayı göstermek için bu fonksiyonu `mlx_loop_hook` içinde çağıracağız
int update_display(t_data *data)
{
    // Aynı konumda, bir sonraki parçaya geç
    draw_piece(data, 0, 0, data->current_piece_x, data->current_piece_y);
    
    // Sonraki parçaya geçmek için x koordinatını artır
    data->current_piece_x += data->piece_width;
    if (data->current_piece_x >= data->img_width) {
        data->current_piece_x = 0;
        data->current_piece_y += data->piece_height;
        if (data->current_piece_y >= data->img_height) {
            data->current_piece_y = 0; // En başa dön
        }
    }
    
    usleep(500000); // 0.5 saniye bekle (animasyon hızı)
    return 0;
}

int main()
{
    t_data data;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1920, 1080, "XPM Parcalara Ayirma");
    
    // XPM dosyasini yukleyin
    data.img = mlx_xpm_file_to_image(data.mlx, "vikings.xpm", &data.img_width, &data.img_height);
    if (!data.img) {
        fprintf(stderr, "XPM dosyasi yuklenemedi!\n");
        return 1;
    }

    // Parça boyutları
    data.piece_width = 128;
    data.piece_height = 128;

    // İlk parça koordinatları
    data.current_piece_x = 0;
    data.current_piece_y = 0;

    // Her döngüde `update_display` fonksiyonunu çalıştır
    mlx_loop_hook(data.mlx, update_display, &data);
    mlx_loop(data.mlx);

    return 0;
}
