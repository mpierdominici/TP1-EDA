
#include <stdio.h>
#include"CallBack.h"

#define WORD_SIZE   30

////////////////////////////////////////// parseCallback /////////////////////////////////////////////
//
// Este callback se encarga de verificar si se ingresó correctamente un nombre, un mes o un año.
//
// Recive: una clave y un valor.
// Devuelve: 1 si lo ingresado es VALIDO. 0 si lo ingresado es INVALIDO.
//
//
// Para ingresar un nombre: -n nombre
// Siendo "n" la clave y "nombre" el valor.
//  El callback verifica que el nombre este compuesto unicamente por letras.
//  Cantidad máxima permitida: WORD_SIZE. Se aceptan tanto minúsculas como mayúsculas.
//
// Para ingresar un mes: -m mes.
// Siendo "m" la clave y "mes" el valor.
//  El callback verifica que lo ingresado sea efectivamente un mes del año, en números.
//  Se acepta: 0; 1; 2; ... ; 12. Tanto como 00; 01; 02; ... ;09.
//
// Para ingresar un año: -a año.
// Siendo "a" la clave y "año" el valor.
//  El callback únicamente acepta como valido que el valor este formado por 4 dígitos (números).
//  Solo se aceptan años entre el 0000 y el 2017.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

int parseCallback(char *key, char *value, void *userData)
{
    
    int i;
    
    switch (*key)
    {
            
        case 'n':                                   //Se espera que lo ingresado sea el NOMBRE de una persona, máximo WORD_SIZE cantidad de letras.
        {
            if ((*(key + 1)) != '\0')               //Para eso la clave es 'n'.
            {
                return 0;                           //Si se trata de una clave con más caracteres,
            }                                       //INVALIDO.
            
            
            else for (i=0; i<(WORD_SIZE + 1); i++) //Si la clave es para el nombre, se analiza si este esta formado por letras.
            {
                char c = *(value + i);
                
                if (((c <= 'a') && (c >= 'z')) && ((c <= 'A') && (c >= 'Z')) && ( c != '\0'))
                {
                    return 0;                       //Si se ingreso algo distinto de letras, es INVALIDO.
                }
                else if (c == '\0')                 //Efectivamente se ingresaron únicamente letras: es VALIDO.
                    return 1;
                
                else if ((c != '\0') && (i == WORD_SIZE)) //Si lo ingresado es de mayor tamaño que lo permitido: es INVALIDO.
                {
                    return 0;
                }
            }
        }
        break;

        /////////////////////
        case 'm':                                    //Se espera que lo ingresado sea un MES del año.
            
        {
            if ((*(key + 1)) != '\0')                //Para eso la clave es 'm'.
            {
                return 0;                            //Si se trata de una clave con más caracteres: es INVALIDO.
            }
            
            int m = 0;
            
            if ((*(value + 1)) == '\0')
            {
                if (((*(value)) >= '1') && ((*(value)) <= '9')) //Si se ingresó un solo dígito entre
                                                                //el 1 inclusive y el 9 inclusive: es VALIDO.
                {
                    m = ((*(value)) - '0');
                    return 1;
                }
                else                                            //De lo contrario: INVALIDO.
                {
                    return 0;
                }
            }
            else if ((*(value + 2)) == '\0')
            {
                if (((*(value)) == '0') && (((*(value+1)) >= '0') && ((*(value+1)) <= '9')))
                {
                    m = ((*(value)) - '0');                     //Si se ingresa un mes de un dígito, anteponiendo un 0: es VALIDO.
                    return 1;
                }
                else if (((*(value)) == '1') && (((*(value+1)) >= '0') && ((*(value+1)) <= '2')))
                {
                    m = (10 + (*(value+1)) - '0');              //De dos dígitos, si se ingresa 10; 11 o 12: es VALIDO.
                    return 1;
                }
                else
                {
                    return 0;                                   //De lo contrario: INVALIDO.
                }
            }
            else
            {
                return 0;                                       //Si se ingresan mas de 2 dígitos: es INVALIDO.
            }
        }
        break;
            
            
            
        /////////////////
        case 'a':                                               //Se espera que lo ingresado sea un AÑO D.C., anterior o igual al 2017.
            {
                if(*(key+1) != '\0')                            //Para eso la clave es 'a'.
                {
                    return 0;                                   //Si se trata de una clave con más caracteres: es INVALIDO.

                }
                
                long int a = 0;
                
                if ((*(value + 3)) == '\0')                     //Si se ingresaron 4 dígitos:
                {
                    int i;
                    for (i=0; i<4; i++)                         //Se chequea que sean números enteros.
                    {
                        if (((*(value + i)) >= '0') && ((*(value + i)) <= '9'))
                        {
                            a = ((a * 10) + (*(value + i)) - '0');
                        }
                        else
                        {
                            return 0;                           //Si alguno de ellos no lo es: es INVALIDO.
                        }
                    }
                    if (a > 2017)                               //Si el año es posterior al 2017: es INVALIDO.
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;                               //De lo contrario: es VALIDO.
                    }
                }
                else
                {
                    return 0;                                   //Si no se ingresaron 4 dígitos: es INVALIDO.
                }
            }
            break;
            
        default:
        {
            return 0;
        }
        break;
    }
}

