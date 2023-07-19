TUTORIAL AQUI!!! 



Este repositorio es mi ejecución del ejercicio, (del cursus de 42) llamado como so_long. Que consiste en crear un "minijuego" con una libreria en concreto. La minilibX.

Cuando realice este proyecto me obsesione con leer la documentación de esta libreria, para chocarme una y otra vez con funciones que no conseguia que terminaran de funcionar del todo bien.
En este README quiero dejar una pequeña guia de las cosas que me hubiese gustado encontrar en internet y que realmente si me hubiesen ayudado a avanzar en el proyecto.

1 Iniciar la ventana:

  Para ello si usaremos funciones de la minilibX. Necesitaremos las siguientes funciones:
    A) mlx_init() 
    B) mlx_new_window()
    C) mlx_loop()

    en codigo simple seria algo como lo siguiente:

    # include <mlx.h>
    int main(void)
    {
      void  *mlx;
      void  *windows;

      mlx = mlx_init();
      windows = mlx_new_window(mlx, 100, 100, "Example_1");
      mlx_loop(mlx);
    }

  Este archivo creara una ventana de un tamaño de 100*100 pixeles. 
  Hablaremos ahora de que hace cada función:

  A) mlx_init() :
    Simplemente inicia el sistema. No tendremos que meterle ningun parametro. simplemte igualaremos la función a una variable que tengamos ya nombrada.
  B) mlx_new_window() : 
    Esta función es la encargada de abrir la ventana, (si la ejecutamos sin la funcion mlx_loop() simplemente se nos abrira y cerrara tan rápido que seguramente ni lo veamos. 
    Los parametros que tendremos que añadir seran:
      
      0 = La variable que va a contener nuestra nueva ventana (En el ejemplo sera windows.)
      1 = El nombre de la variable con la que hemos iniciado la ejecución (En el ejemplo sera el void *mlx). 
      2 = El número de columnas de bits que tendra nuestra nueva ventana.
      3 = El número de filas de bits que tendra nuestra nueva ventana.
      4 = El nombre que tendra nuestra nueva ventana.
      
  Este archivo se tendra que compilar con las siguientes flags cc -lmlx -framework OpenGL -framework AppKit


  2 Cerrar la ventana de forma correcta:

    Hay varias formas de cerrar la ventana, para mi, la mas sencilla es añadir esta linea de código justo antes de la función mlx_loop:

            mlx_hook(windows, 17, (1L << 17), ft_close, mlx);

  Con está linea seguimos usando una función de la minilibX (mlx_hook) y cerraremos la ventana correctamente al usar la X roja de la ventana que estamos creando.
  Tanto el 17 como el (1L << 17) es un código que puedes buscar en la documentación de la minilibX, hay un monton de mascaras que provocan resultados distintos en nuestro programa.
  Esta en concreto funciona perfectamente.
    
  ft_close es una función que crearemos para poder cerrar el programa sin leaks, en mi proyecto use la siguiente:

    int	ft_close(t_vars *vars)
    {
	    if (!vars)
		    exit(1);
	    exit(1);
    }
    Hay que señalar que despues de la llamada a ft_close hay que poner la variable que queremos que entre dentro de la función ft_close y que claramente podremos llamar a todo esto de cualquier manera.

3 Extructura de datos: 

  Para simplificar nuestro proyecto evitaremos usar un montón de variables aleatorias e inconexas. Para ello podemos usar las estructuras de datos (t_vars).
  Gracias a estas estructuras, simplificaremos infinitamente los siguientes problemas:

    1 = Los resultados de las ejecuciones de las funciones, ya no tendremos que usar return(valor); para poder devolver las variables que necesitemos. Es decir:
    Teniendo un vars->mlx y un vars->window solo tendriamos que devolver la variable vars.
    2 = Todas las varibles que queremos introducir en cada función. igual que en el ejemplo anterior solo tendriamos que poner "t_vars *vars",
        en comparación de tipificar cada variable que queremos usar en la función en cuestión.


Guia en proceso! (10% de su creación. Según mi estimación....)


    
   

    
