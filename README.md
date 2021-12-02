# Búsqueda optimizada de localizaciones satelitales por medio de grafos
Vivimos en pleno Siglo XXI y las necesidades están en constante cambio. A pesar de la existencia de una pandemia global, el movimiento humano no puede detenerse ya que la civilización depende de la participación de todos con su respectiva relevancia en cada campo de la sociedad. Este programa permite analizar distintas ciudades de la República para poder encontrar conexiones de carretera más factibles para lograr una rápida y correcta llegada al destino final.

## SEG0702A Tecnologías de Vanguardia 

### Usa grafos para hacer analisis de información
Se utiliza una estructura de grafos para representar la conexión entre distintas ciudades del país. Esto es perfectamente palpable puesto a que la multiconectividad de los grafos permite identificar las diferentes carreteras que conectan las localidades y así permitir la búsqueda del camino más corto para llegar entre ellas.
### Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema
Se realizó un recorrido entre los puntos que se tocan en los grafos. Dado a que se requiere buscar un trayecto que involucre la menor cantidad de tiempo posible, trazar todos los caminos posibles hasta encontrar el más conveniente para llegar al destino es un algoritmo bastante adecuado para el servicio que ofrece este sistema.
### Usa un algoritmo de hashing adecauado para resolver un problema
Se realizó un cambio que modificó enteramente el funcionamiento del main. Se incluyó el algoritmo de hashing utilizado en la última actividad manejando ciertas modificaciones para poder manejar los ids directamente dentro del hash, poder almacenarlos en conjunto con el nombre de la ciudad y así finalmente imprimir el recorrido de las ciudades con el nombre de las mismas y no con sus respectivos números como se realizaba en la entrega anterior. Esta mejora es sustancial para el entendimiento del usuario y utiliza una mezcla entre funciones y retorno de vectores y la función Get y el print del hash para obtener los resultados.
### Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso
El algoritmno implementado fue el pancake sort, tipo de sort interesante ya que funciona como una espátula que por la función "flip", es capaz de invertir los panqueques (datos) insertándose en medio de cualquiera de los que se encuentran en el plato (arreglo). Dado a que la cantidad de flips es n y la cantidad de panqueques también es n. Un requerimiento de voltear n cantidad de veces una n cantidad de panqueques hace que el peor de los casos sea O(n*n). Fue utilizado para acomodar las líneas de autobuses por medio de sus largos ids y es muy propio el algoritmo dado que los flips son un método más propio para el análisis de números con amplias diferencias entre si que todos aquellos que utilizan contrastes posición por posición.
## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,
El programa maneja una variedad de 4 funciones que serán explicadas a continuación:
#### Despliega lista completa de ciudades.
Utiliza la impresión del hash para desplegar las ciudades y sus respectivos ids obtenidos de el archivo "Ciudades.txt". Como caso de prueba, se le atribuye una lista de 8 ciudades en formato de texto que pueden ser perfectamente modificables al gusto de la persona. Si se coloca una menor o mayor cantidad de ciudades, arrojará un error que evitará que prosiga la plataforma. 
### Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes


## SICT0303B: Implementa acciones científicas 

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.


### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera



### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera


