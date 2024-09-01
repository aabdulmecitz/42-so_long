#include "mlx.h"

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init(); // MinilibX'i başlat
    window = mlx_new_window(mlx, 800, 600, "Hello, MiniLibX"); // 800x600 boyutlarında bir pencere oluştur

    mlx_loop(mlx); // Pencerenin açık kalmasını sağla
    return (0);
}
