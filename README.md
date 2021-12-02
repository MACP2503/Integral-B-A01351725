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
El hash almacena por medio de lectura de archivos el nombre de una variedad de ciudades. Esta función utiliza la impresión del hash para desplegar las ciudades y sus respectivos ids obtenidos de el archivo "Ciudades.txt". Como caso de prueba, se le atribuye una lista de 8 ciudades en formato de texto que pueden ser perfectamente modificables al gusto de la persona. Si se coloca una menor o mayor cantidad de ciudades, arrojará un error que evitará que prosiga la plataforma.
#### Encontrar ruta más cercana entre dos ciudades por id.
Solicita al usuario dos ids válidos de ciudades (si no marca error) para proceder a hacer una búsqueda de la menor distancia posible entre dos puntos del hash. Posteriormente, se hace una impresión de los valores transcritos de Id a su equivalente de ciudad para finalizar añadiendo la búsqueda al historial. El caso de prueba incluye el archivo historial.txt con ejemplos de impresiones acordes al funcionamiento de la función que no serán sobreescritas cada que se corra el programa. La cantidad de estas puede ser infinita y proseguirá funcionando.
#### Ver lista de líneas de autobuses disponibles para servicio.
Utiliza un pancake sort con equivalencias létricas para ordenar e imprimir las líneas de autobuses disponibles para la movilidad entre las ciudades del txt. Es una función automática que apoya al usuario para observar la información requerida de los medios de transporte adecuados y oficiales para su conveniencia.
#### Eliminar historial de búsqueda de rutas. 
Utiliza un algoritmo de escritura para eliminar todo texto, fuera del título, que se encuentre dentro de historial.txt para suprimirlo y quitar rastro de toda búsqueda realizada en tiempos anteriores. Se otorga el historial.txt con información y perfectamente modificable para asegurarse del constante funcionamiento de la función.
### Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes
#### Inicio del proyecto.
Se realizó una lectura de archivo que se encargase de la inserción de valores en un hash que será el encargado de guardar tanto ciudad como ID y en el grafo de búsqueda de caminos. Dado a que este depende del archivo y su tamaño, la cantidad de instrucciones a realizar se convierte en un O(n) en el peor de los casos, siendo O(1) casi una constante por la cantidad ya definida de ciudades.
#### Comprobación de errores.
Un if define la comprobación que mata todo el programa si no se cumple, un O(1) constante para esta función.
#### Despliega lista completa de ciudades.
La impresión de los valores del hash debería ser un O(n) por la dependencia de la cantidad de valores del mismo, sin embargo, pasa como en la función anterior puesto a que el 8 es una constante en este programa, haciéndolo O(1) casi por completo. 
#### Encontrar ruta más cercana entre dos ciudades por id.
El método de búsqueda del grafo consiste en un O(V+E) por su bipolaridad de búsqueda conectable por medio de valores y vértices. Este generó un contraste junto con el while de posicionamiento usando como herramienta el hash para hacer tanto una búsqueda de caminos cortos como un análisis de equivalencias entre números y nombres de ciudad. Esto lo hace un 0(N(V+E)) para el peor de los casos. 
#### Ver lista de líneas de autobuses disponibles para servicio.
La ejecución de un pancake equivale a un O(n*n), algo que ya se explicó en la documentación superior. La posterior impresión de las líneas es una constante porque los valores del arreglo ya se encuentran definidos. Ergo, sigue siendo O(n*n).
#### Eliminar historial de búsqueda de rutas. 
Un O(1) que ejecuta un par de funciones para dejar en blanco el historial.txt con su respectivo título.
## SICT0303B: Implementa acciones científicas 

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
Desde el momento que se hace un menú principal con recursión que permite elegir 4 funciones que se guardan en archivos de texto, se implementan mecanismos propios para el usuario que no sólo son impresiones. Desde ordenamientos con sortings nuevos y contrastes entre grafos y heaps hasta lectura y escritura de documentos, el programa implementa consultoría y escritura de información movilizadas en diversos ámbitos de las estructuras de datos.
### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera
La lectura proviene del archivo ciudades.txt que da nombre a las ciudades de la plataforma.
### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera
La escritura se encuentra en el historial con extensión txt, puesto a que es modificable a conveniencia del usuario por medio de las opciones 2 y 4.

