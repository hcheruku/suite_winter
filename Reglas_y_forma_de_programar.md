# Estandar
Este archivo describe las reglas y forma de programar mia (Joaquin Manuel Crespo) para todos mis programas.

## Requerimientos 
* La compilación con gcc debe llevar sus argumentos: -Wall -Werror para que muestre todos los warnings dentro del programa
y los mismos sean considerados errores del programador.
* Para pasar datos entre funciones y que cualquiera las pueda leer se debe usar una estructura Backup con variable punte Back.
* Las funciones específicas que pueda desempeñarse como separadas deben tener sus funciones en winter-lib.
* Los hilos deben ser creados con pthread.h
* Cuando el programa madre pueda soportarlo deben crearse hilos. Los hilos no deben ser creados arbitrariamente, si no cuando se
sabe que el programa desempeñará varias funciones a la vez.
* Para condicionales que requieran más de dos conjuntos de acciones no se debe utilizar if{} , elseif{} , else{} si no switch(){}
* No se debe utilizar la sintaxis polaca inversa ni ningun tipo de sintaxis (por más que sea soportado por el lenguaje y
por el compilador) que ofusque el entendimiento del programa.
* No debe utilizarse goto() bajo ninguna circunstancia (para eso esta la estructura backup) o yo mismo mandaré a toda la orden 
lovecraftiana y a Technical Boy a tu cama.
* El programa debe ser tan simple y facilmente legible como sea posible, por más que ello conlleve codigo adicional. Recuerden
que hay programadores novatos que intentan aprender, hagamosles las cosas un poco más faciles.
* La cabezera del programa debe llevar el nombre y apellido, asi como el seudónimo, del programador/es y su licencia.
* Los archivos de los  #include deben ir en orden alfabético.
* El compilador no reconoce guiones medios (" - ") entre palabras como parte del nombre de una variable/función, ergo usar guiones bajos.
* No usar guiones bajos en el inicio de las variables alias de un typedef, #define, etc.
* Cada dato que fue pasado a una función X o Y debe ser almacenado en la estructura BackUp por si esa llamada falla.
* La estructura no debe ser modificada para que contenga una función inicializadora al principio de ella. Ya que si se trata
como un hilo más y el main() falla, este quedará funcionando en el host. Para eso se debe crear una variable de tipo ptheread_t
con tantos arreglos como hilos de la estructura original se requiera y usar eso (de paso evitamos colisiones entre programas
por no usar variables tipos mutex o semaphoro).
