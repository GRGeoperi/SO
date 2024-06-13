## Diferencia entre concurrencia y paralelismo
### Concurrencia
En la concurrencia hay múltiples ejecuciones de hilos pero no necesariamente
transcurren al mismo tiempo.
Es una optimización para distribuír la carga de procesamiento pero se debe
tener extremo cuidado en no leer el estado compartido mientras se podría
estar escribiendo en él. 
Entonces, por decirlo así, *la concurrencia* se enfoca más en el procesamiento 
de varias tareas ejecutando y gestionando cada una de ellas para mejorar
el tiempo de respuesta con solo una unidad de procesamiento.
### Paralelismo
En el paralelismo, la ejecución de hilos transcurren al mismo tiempo.
También es una optimización para distribuir la carga de procesamiento pero,
a diferencia de la concurrencia, esto ocurre asignando a cada unidad de
procesamiento disponible una sola tarea que se soluciona al mismo tiempo.
Aquí radica la gran diferencia del paralelismo, mientras que la concurrencia
es un diseño de software, el *paralelismo* es la forma de ejecución de esta
concurrencia