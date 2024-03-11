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
        echo "Tiene permitido leer $ARCHIVO"
    fi
}

function ejecucion()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    if test -x $DIRECTORIO/$ARCHIVO; then
        echo "Tiene permitido ejecutar $ARCHIVO"
    else
        echo "No tiene permitido ejecutar $ARCHIVO"
    fi
}

function propietario()
{
    DIRECTORIO=`pwd`
    ARCHIVO="$1"
    NOMBRE=$(stat -c %U "$0")
    if test -O $DIRECTORIO/$ARCHIVO; then
        echo "$NOMBRE es el propietario de $ARCHIVO"
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


if test "$#" != 0; then
    lectura $1
    ejecucion $2
    propietario $3
    antiguedad $1 $2 $3
else
    echo "Argumentos faltantes."
fi