### TUTORIAL del so_long 42!!! 

### Objetivos: 
	1 : Facilitar la busqueda de información sobre la Minilibx. 
 	    En concreto, no perderse entre las funciones que tiene la libreria, 
 	2 : Que exista información escrita en español para la gente que tiene problemas con el ingles o el frances.

### Documentación:
 Puedes amplicar la documentación de esta guia en distintas paginas webs, te dejo una lista de los sitios donde yo me informe:

 - Para mi gusto, esta es la forma más dificil de enterarse de algo. En la terminal usa el comando : "/usr/share/man/man3/" .
 - Puedes entrar en el blog de Aurelien, mas concretamente en las entradas sobre la MinilibX : https://aurelienbrabant.fr/blog .
 - En la última pagina que te dejo en este apartado tienes un monton de funciones tipificadas, entre otras cosas, como la explicación detallada de como funciona la MinilibX :
   	https://harm-smits.github.io/42docs/libs/minilibx .


Una última explicación. Este repositorio es mi ejecución del ejercicio, (del cursus de 42) llamado como so_long.
Consiste en crear un "minijuego" con la libreria minilibX. En mi caso, no hice más que los bonus más faciles dado que mi intención era no hacerlos. 
Si quisierais sacar todos los bonus, tendreis que buscar algo mas de información.

Cuando realice este proyecto me obsesione con leer la documentación de esta libreria, para chocarme una y otra vez con funciones que no conseguia que terminaran de funcionar del todo bien.
En este README quiero dejar una pequeña guia de las cosas que me hubiese gustado encontrar en internet y que realmente si me hubiesen ayudado a avanzar en el proyecto.

### 1 Iniciar la ventana:

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


  ### 2 Cerrar la ventana de forma correcta:

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

### 3 Extructura de datos: 

  Para simplificar nuestro proyecto evitaremos usar un montón de variables aleatorias e inconexas. Para ello podemos usar las estructuras de datos (t_vars).
  Gracias a estas estructuras, simplificaremos infinitamente los siguientes problemas:

    1 = Los resultados de las ejecuciones de las funciones, ya no tendremos que usar return(valor); para poder devolver las variables que necesitemos. Es decir:
    Teniendo un vars->mlx y un vars->window solo tendriamos que devolver la variable vars.
    2 = Todas las varibles que queremos introducir en cada función. igual que en el ejemplo anterior solo tendriamos que poner "t_vars *vars",
        en comparación de tipificar cada variable que queremos usar en la función en cuestión.

  Un ejemplo de una estructura de datos seria la siguiente: 

  	typedef struct s_vars
	{
		void	*mlx;
		void	*windows;
		void	*player;

	}		t_vars;

  Por supuesto, para poder finalizar este ejercicio, la estructura sera mucho mas grande. Incluso recomiendo meter una estructura extra dentro de la estructura para que todo quede mas ordenado. Te dejo otro ejemplo:

  	typedef struct s_vars
	{
		void		*mlx;
		void		*windows;
		struct s_player	*player;

	}			t_vars;

 	typedef struct s_player
	{
		void	*img;
		int	x;
		int	y;
	}		t_player;


Guia en proceso! (12% de su creación. Según mi estimación....)


    
   

    
