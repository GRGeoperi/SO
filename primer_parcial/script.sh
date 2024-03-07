#! /usr/bin/bash

# Crear un script que contenga las siguientes estructuras de control:
# IF, FOR, WHILE, CASE.
# Incluír variables con asignación de diferentes tipos de datos

echo "¡Bienvenido a la calculadora escrita en shell!"

if test "$3" = "+"; then
    SUMA=$(($1+$2))
    echo "Su suma es: $SUMA"
elif test "$3" = "-"; then
    RESTA=$(($1-$2))
    echo "Su resta es: $RESTA"
elif test "$3" = "*"; then
    MULTIPLICACION=$(($1*$2))
    echo "Su multiplicación es: $MULTIPLICACION"
elif test "$3" = "/"; then
    DIVISION=$(($1/$2))
    echo "Su división es: $DIVISION"
fi

echo "~~Potencia de un número~~"
echo -n "Escriba la base: "
read BASE
echo -n "Escriba el exponente: "
read EXPONENTE
for ((i=1; i<$EXPONENTE; i++)); do
    POTENCIA=$(($BASE*$BASE))
done
echo "Su potencia es: $POTENCIA"
