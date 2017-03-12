
//****************************************
// Bibliteca para parseo de la linea de comando
//
//
//
//
//
//Version: 12/03/2017
//Git: https://github.com/mpierdominici/TP1-EDA.git
//****************************************







#include <stdio.h>
#include <stdint.h>

#define ERROR 0
#define NO_ERROR 1
#define PARSER_RETURN_ERROR -1 //valor que devueleve el parser en caso que suceda un error
#define MIN_ARGC 2 //cantidad  minima de argumentos a recivir por cmd
#define TRUE 1
#define FALSE 0
#define KEY '-'//caracter previo al key

typedef int (*pCallback) (char *, char*, void *);

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData); 



int parseCmdLine(int argc, char *argv[], pCallback p, void *userData)
{
   
    uint8_t end_runing=FALSE;
    int16_t counter_string = TRUE;//contador que apunta al string enviado por consola deseado, inicializado en 1(string 0 nombre del programa)
    int16_t return_value = TRUE;//variable que contiene lo que devuelve la funcion parseCmdLine
    uint8_t * key =NULL;//variable que almacena el key
    
    if (argc>MIN_ARGC)//evaluo si hay sufucientes argumentos
    {
        return_value = PARSER_RETURN_ERROR;//en caso de que no los haya, detengo la ejecucion y devuelvo error
    }
    else
    {
        while(!end_runing)
        {
            if (((*(argv[counter_string]))==KEY)&&((*((argv[counter_string])+1))!='\0'))
            {
                key=(uint8_t *)((argv[counter_string])+1);
                counter_string++;
               // if() ver si hay una opcion y llamar al calback
            }else if ((*(argv[counter_string]))!='\0')
            {
                
            }
            else
            {
                end_runing=TRUE;
                return_value=PARSER_RETURN_ERROR;                
            }
        }
        
        
        
        
    }
    
    return return_value;
   
   
   
    
    
    
}
