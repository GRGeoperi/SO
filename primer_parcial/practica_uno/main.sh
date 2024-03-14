#! /usr/bin/bash
# * Ejercicio 1
# ? Imprimir las últimas 15 líneas del log del sistema (/var/log/syslog) en orden inverso,
# ? redirigir la salida estándar a un archivo de texto que se llame syslog.txt.
# ? Redirigir los errores al archivo /dev/null
function ejercicio_1()
{
    tail -15 /var/log/syslog | sort -r > syslog.txt 2> /dev/null
}
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
function ejercicio_2
{
    A=$(echo "10" | bc)
    echo "a = $A"
    B=$(echo "2*10" | bc)
    echo "b = $B"
    C=$(echo "scale=4; $A+$B/2" | bc)
    echo "c = $C"
    D=$(echo "(2+3)*10" | bc)
    echo "d = $D"
    DIV=$(echo "scale=4; $C/2" | bc)
    echo "div = $DIV"
    RES=$(echo "$B%$C" | bc)
    echo "res = $RES"
}
# * Ejercicio 3
# ? Usa expresiones condicionales para validar 3 archivos. El primer archivo debe tener
# ? permisos de lectura, el segundo debe existir y tener permisos de ejecución.
# ? Mostrar quién es el propietario del tercer archivo.
# ? Mostrar cuál de los tres es el archivo más antiguo (en creación).
# ? El nombre de los archivos se recibe por argumento al momento de ejecutar el script.
function lectura()
{
    DIRECTORIO=$(pwd)
    ARCHIVO="$1"
    if test -r "$DIRECTORIO"/"$ARCHIVO"; then
        echo "El archivo $ARCHIVO tiene permisos de lectura"
    else
        echo "El archivo $ARCHIVO no tiene permisos de lectura"
    fi
}
function existencia_lectura()
{
    DIRECTORIO=$(pwd)
    ARCHIVO="$1"
    if test -e "$DIRECTORIO"/"$ARCHIVO"; then
        lectura "$ARCHIVO"
        return 0
    else
        echo "El archivo $ARCHIVO no existe en su directorio"
        return 1
    fi    
}
function ejecucion()
{
    DIRECTORIO=$(pwd)
    ARCHIVO="$1"
    if test -x "$DIRECTORIO"/"$ARCHIVO"; then
        echo "El archivo $ARCHIVO tiene permisos de ejecución"
    else
        echo "El archivo $ARCHIVO no tiene permisos de ejecución"
    fi
}
function existencia_ejecucion()
{
    DIRECTORIO=$(pwd)
    ARCHIVO="$1"
    if test -e "$DIRECTORIO"/"$ARCHIVO"; then
        ejecucion "$ARCHIVO"
    else
        echo "El archivo $ARCHIVO no existe en su directorio"
    fi    
}
function propietario()
{
    DIRECTORIO=$(pwd)
    ARCHIVO="$1"
    NOMBRE=$(stat -c %U "$0")
    echo "$NOMBRE es el propietario de $ARCHIVO"
}
function existencia_propietario()
{
    DIRECTORIO=$(pwd)
    ARCHIVO="$1"
    if test -e "$DIRECTORIO"/"$ARCHIVO"; then
        propietario "$ARCHIVO"
    else
        echo "El archivo $ARCHIVO no existe en su directorio"
    fi
}
function antiguedad()
{
    DIRECTORIO=$(pwd)
    ARCHIVO_UNO="$1"
    ARCHIVO_DOS="$2"
    ARCHIVO_TRES="$3"
    if test "$DIRECTORIO"/"$ARCHIVO_UNO" -ot "$DIRECTORIO"/"$ARCHIVO_DOS" -a "$DIRECTORIO"/"$ARCHIVO_UNO" -ot "$DIRECTORIO"/"$ARCHIVO_TRES"; then
        echo "El archivo $ARCHIVO_UNO se creó primero"
    elif test "$DIRECTORIO"/"$ARCHIVO_DOS" -ot "$DIRECTORIO"/"$ARCHIVO_UNO" -a "$DIRECTORIO"/"$ARCHIVO_DOS" -ot "$DIRECTORIO"/"$ARCHIVO_TRES"; then
        echo "El archivo $ARCHIVO_DOS se creó primero"
    elif test "$DIRECTORIO"/"$ARCHIVO_TRES" -ot "$DIRECTORIO"/"$ARCHIVO_DOS" -a "$DIRECTORIO"/"$ARCHIVO_TRES" -ot "$DIRECTORIO"/"$ARCHIVO_UNO"; then
        echo "El archivo $ARCHIVO_TRES se creó primero"
    fi
}
function existencia_antiguedad()
{
    DIRECTORIO=$(pwd)
    ARCHIVO_UNO="$1"
    ARCHIVO_DOS="$2"
    ARCHIVO_TRES="$3"
    if [ -e "$DIRECTORIO"/"$ARCHIVO_UNO" ] && [ -e "$DIRECTORIO"/"$ARCHIVO_DOS" ] && [ -e "$DIRECTORIO"/"$ARCHIVO_TRES" ]; then
        antiguedad "$ARCHIVO_UNO" "$ARCHIVO_DOS" "$ARCHIVO_TRES"
    else
        echo "No se puede hacer la comparación de archivos inexistentes"
    fi
}
function ejercicio_3 ()
{
    if test "$#" == 3; then
        existencia_lectura "$1"
        existencia_ejecucion "$2"
        existencia_propietario "$3"
        existencia_antiguedad "$1" "$2" "$3"
    else
        echo "Argumentos faltantes o sobrantes"
    fi
}
# * Ejercicio 4
# ? Completa el siguiente código para verificar el contenido todas las variables de entorno,
# ? tip usa env para conocer esas variables.
# Si HOSTNAME es una variable vacía o
# tiene el valor "(none)"; entonces ...
# if [ -z "$HOSTNAME" -o "$HOSTNAME" = "(none)" ]; then
# * Ejercicio 5
# ? Valida los argumentos de ejecución del shellscript. Si tiene argumentos que imprima
# ? el número de argumentos y su valor, si no tiene argumentos entonces imprime “Sin argumentos”.
function ejercicio_5()
{
    if test "$#" != 0; then
        for((i=1; i<=$#; i++)); do
            NUMERO_ARGUMENTO=$i
            ARGUMENTO=${!i}
            echo "Numero de argumento: $NUMERO_ARGUMENTO"
            echo "Valor: $ARGUMENTO"
        done
    else
        echo "Sin argumentos."
    fi
}
# ! Uso: ejercicio_5 "$@"
# * Ejercicio 6
# ? Que lea nombres de archivos de un archivo de texto y los copie a otro directorio.
# ? El usuario introduce el nombre del archivo y el nombre del directorio destino.
function existencia_directorio()
{
    DIRECTORIO=$1
    if test -d "$DIRECTORIO"; then
        echo "$DIRECTORIO es un directorio existente"
        return 0
    else
        echo "$DIRECTORIO no es un directorio, crealo y vuelva a intentar"
        return 1
    fi
}
function copiar_archivos()
{
    if test -s "$1"; then
        for NOMBRES_ARCHIVOS in $1; do
            cp "$(pwd)"/"$NOMBRES_ARCHIVOS" "$2"
            echo "Archivos copiados"
        done
    else
        echo "Nota: Los nombres de archivo de su .txt deben existir en la raíz y no estar vacíos"
    fi
}
function extraccion_contenido()
{
    if test "$1" == 0 -a "$2" == 0; then
        NOMBRE_ARCHIVO=$3
        DIRECTORIO=$4
        CONTENIDO_ARCHIVO=$(cat "$NOMBRE_ARCHIVO")
        copiar_archivos "$CONTENIDO_ARCHIVO" "$DIRECTORIO"
    fi
}
function ejercicio_6()
{
    if test "$#" == 2; then
        existencia_lectura "$1"
        RESULTADO_ARCHIVO=$?
        existencia_directorio "$2"
        RESULTADO_DIRECTORIO=$?
        extraccion_contenido "$RESULTADO_ARCHIVO" "$RESULTADO_DIRECTORIO" "$1" "$2"
    else
        echo "Argumentos faltantes o sobrantes"
    fi
}
# ! Uso: ejercicio_6 "$@"
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
