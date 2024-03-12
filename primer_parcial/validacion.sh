#! /usr/bin/bash

# Usa expresiones condicionales para validar 3 archivos.
# Los nombres de los archivos se reciben mediante argumentos.
# El primer archivo debe tener permisos de lectura, el segundo
# debe existir y tener permisos de ejecución. Mostrar quién es
# el propietario del tercer archivo. Mostrar cuál de los tres
# es el archivo más antigüo (en creación).

function lectura()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    if test -r $DIRECTORIO/$ARCHIVO; then
        echo "El archivo $ARCHIVO tiene permisos de lectura"
    else
        echo "El archivo $ARCHIVO no tiene permisos de lectura"
    fi
}

function existencia_lectura()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    if test -e $DIRECTORIO/$ARCHIVO; then
        lectura $ARCHIVO
    else
        echo "El archivo $ARCHIVO no existe en su directorio"
    fi    
}

function ejecucion()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    if test -x $DIRECTORIO/$ARCHIVO; then
        echo "El archivo $ARCHIVO tiene permisos de ejecución"
    else
        echo "El archivo $ARCHIVO no tiene permisos de ejecución"
    fi
}

function existencia_ejecucion()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    if test -e $DIRECTORIO/$ARCHIVO; then
        ejecucion $ARCHIVO
    else
        echo "El archivo $ARCHIVO no existe en su directorio"
    fi    
}

function propietario()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    NOMBRE=$(stat -c %U "$0")
    echo "$NOMBRE es el propietario de $ARCHIVO"
}

function existencia_propietario()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    if test -e $DIRECTORIO/$ARCHIVO; then
        propietario $ARCHIVO
    else
        echo "El archivo $ARCHIVO no existe en su directorio"
    fi
}

function antiguedad()
{
    DIRECTORIO=`pwd`
    ARCHIVO_UNO="$1"
    ARCHIVO_DOS="$2"
    ARCHIVO_TRES="$3"
    if test $DIRECTORIO/$ARCHIVO_UNO -ot $DIRECTORIO/$ARCHIVO_DOS -a $DIRECTORIO/$ARCHIVO_UNO -ot $DIRECTORIO/$ARCHIVO_TRES; then
        echo "El archivo $ARCHIVO_UNO se creó primero"
    elif test $DIRECTORIO/$ARCHIVO_DOS -ot $DIRECTORIO/$ARCHIVO_UNO -a $DIRECTORIO/$ARCHIVO_DOS -ot $DIRECTORIO/$ARCHIVO_TRES; then
        echo "El archivo $ARCHIVO_DOS se creó primero"
    elif test $DIRECTORIO/$ARCHIVO_TRES -ot $DIRECTORIO/$ARCHIVO_DOS -a $DIRECTORIO/$ARCHIVO_TRES -ot $DIRECTORIO/$ARCHIVO_UNO; then
        echo "El archivo $ARCHIVO_TRES se creó primero"
    fi
}

function existencia_antiguedad()
{
    DIRECTORIO=`pwd`
    ARCHIVO_UNO="$1"
    ARCHIVO_DOS="$2"
    ARCHIVO_TRES="$3"
    if [ -e $DIRECTORIO/$ARCHIVO_UNO ] && [ -e $DIRECTORIO/$ARCHIVO_DOS ] && [ -e $DIRECTORIO/$ARCHIVO_TRES ]; then
        antiguedad $ARCHIVO_UNO $ARCHIVO_DOS $ARCHIVO_TRES
    else
        echo "No se puede hacer la comparación de archivos inexistentes"
    fi
}

if test "$#" == 3; then
    existencia_lectura $1
    existencia_ejecucion $2
    existencia_propietario $3
    existencia_antiguedad $1 $2 $3
else
    echo "Argumentos faltantes"
fi
