#! /usr/bin/bash

# Crear un script que contenga las siguientes estructuras de control:
# IF, FOR, WHILE, CASE.
# Incluír variables con asignación de diferentes tipos de datos

echo "¡Bienvenido a la calculadora escrita en shell!"

# En caso de que se le pasen tres argumentos a la ejecución:
# Si el tercer argumento es el símbolo de "+", entonces
# hará la suma del primer con el segundo argumento
if test "$3" = "+"; then
    SUMA=$(($1+$2))
    echo "Su suma es: $SUMA"
# Si el tercer argumento es el símbolo de "-", entonces
# hará la resta del primer con el segundo argumento
elif test "$3" = "-"; then
    RESTA=$(($1-$2))
    echo "Su resta es: $RESTA"
# Si el tercer argumento es el símbolo de "*", entonces
# hará la multiplicación del primer con el segundo argumento
elif test "$3" = "*"; then
    MULTIPLICACION=$(($1*$2))
    echo "Su multiplicación es: $MULTIPLICACION"
# Si el tercer argumento es el símbolo de "/", entonces
# hará la división del primer con el segundo argumento
elif test "$3" = "/"; then
    DIVISION=$(($1/$2))
    echo "Su división es: $DIVISION"
fi

echo "~~Potencia de un número~~"
echo -n "Escriba la base: "
read BASE
echo -n "Escriba el exponente: "
read EXPONENTE
# Hace la potencia de un número multiplicando iterativamente
# la base por sí misma cuántas veces el exponente lo dicte
for ((i=1; i<$EXPONENTE; i++)); do
    POTENCIA=$(($BASE*$BASE))
done
echo "Su potencia es: $POTENCIA"
