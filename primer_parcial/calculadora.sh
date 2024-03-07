# Crear un shellscript que realice las operaciones básicas de
# una calculadora, tomando en cuenta lo siguiente:
# 1. Validar que el usuario introduzca al menos un argumento al
# momento de ejecutar el script.
# 2. El argumento indica la operación que se desea realizar,
# ejemplo ./calculadora.sh suma.
# 3. Usar un CASE y funciones para realizar las operaciones
# necesarias.

function sumar()
{
    read -p "Introduce el primer número: " VAR1
    read -p "Introduce el segundo número: " VAR2
    return $(($VAR1+$VAR2))
}

function restar()
{
    read -p "Introduce el primer número: " VAR1
    read -p "Introduce el segundo número: " VAR2
    return $(($VAR1-$VAR2))
}

function multiplicar()
{
    read -p "Introduce el primer número: " VAR1
    read -p "Introduce el segundo número: " VAR2
    return $(($VAR1*$VAR2))
}

function dividir()
{
    read -p "Introduce el primer número: " VAR1
    read -p "Introduce el segundo número: " VAR2
    return $(($VAR1/$VAR2))
}

if test "$#" != 0; then
    echo "¡Bienvenido a la calculadora escrita en shell!"
    case $1 in
        suma)
            sumar
            echo "Su suma es: $?"
            ;;
        resta)
            restar
            echo "Su resta es: $?"
            ;;
        multiplicacion)
            multiplicar
            echo "Su multiplicación es: $?"
            ;;
        division)
            dividir
            echo "Su división es: $?"
            ;;
    esac
else
    echo "Argumentos faltantes"
fi