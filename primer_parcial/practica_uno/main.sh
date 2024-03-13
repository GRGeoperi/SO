#! /usr/bin/bash
# * Ejercicio 1
# ? Imprimir las últimas 15 líneas del log del sistema (/var/log/syslog) en orden alfabético,
# ? redirigir la salida estándar a un archivo de texto que se llame syslog.txt.
# ? Redirigir los errores al archivo /dev/null
# * Ejercicio 2
# ? Escribir las siguientes expresiones en el shellscript:
# ? a) a=10
# ? b) b= 2 * 10
# ? c) c= a + b / 2
# ? d) d = (2+3) * 10
# ? e) div = c / 2
# ? f) res = b % c
# ? Imprime el resultado de todas las variables (revisar que el resultado de las operaciones
# ? incluya números con decimales y negativos)
# * Ejercicio 3
# ? Usa expresiones condicionales para validar 3 archivos. El primer archivo debe tener
# ? permisos de lectura, el segundo debe existir y tener permisos de ejecución.
# ? Mostrar quién es el propietario del tercer archivo.
# ? Mostrar cuál de los tres es el archivo más antiguo (en creación).
# ? El nombre de los archivos se recibe por argumento al momento de ejecutar el script.
# * Ejercicio 4
# ? Completa el siguiente código para verificar el contenido todas las variables de entorno,
# ? tip usa env para conocer esas variables.
# Si HOSTNAME es una variable vacía o
# tiene el valor "(none)"; entonces ...
# if [ -z "$HOSTNAME" -o "$HOSTNAME" = "(none)" ]; then
# * Ejercicio 5
# ? Valida los argumentos de ejecución del shellscript. Si tiene argumentos que imprima
# ? el número de argumentos y su valor, si no tiene argumentos entonces imprime “Sin argumentos”.
# * Ejercicio 6
# ? Que lea nombres de archivos de un archivo de texto y los copie a otro directorio.
# ? El usuario introduce el nombre del archivo y el nombre del directorio destino.
# * Ejercicio 7
# ? Que realice una búsqueda recursiva en un directorio de archivos de texto, encuentre todas
# ? las ocurrencias de un patrón específico y las redirija a un archivo de resumen.
# ? El usuario introduce el directorio de búsqueda y el patrón que se buscará.
# * Ejercicio 8
# ? Que tome la salida de múltiples comandos como entrada, combine los resultados y los
# ? clasifique según ciertos criterios antes de escribirlos en un archivo de salida.
# * Ejercicio 9
# ? Que monitorice el estado del CPU, registre el modelo, número de procesadores y el uso
# ? de cada procesador, genere un archivo de texto con los cambios cada 5 minutos.
# ? Nota: Se puede usar el archivo /proc/cpuinfo.
# * Ejercicio 10
# ? Que monitorice el estado de la memoria RAM, registre la capacidad total y la memoria
# ? disponible, genere un archivo de texto con los cambios cada 5 minutos.
