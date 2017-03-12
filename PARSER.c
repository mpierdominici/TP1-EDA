/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdint.h>

#define ERROR 0
#define NO_ERROR 1
#define PARSER_RETURN_ERROR -1
#define MIN_ARGC 2 //cantidad  minima de argumentos a recivir por cmd
#define TRUE 1
#define FALSE 0
#define KEY '-'

typedef int (*pCallback) (char *, char*, void *);

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData); 



int parseCmdLine(int argc, char *argv[], pCallback p, void *userData)
{
   
    uint8_t end_runing=FALSE;
    int counter_string = TRUE;//contador que apunta al string enviado por consola deseado, inicializado en 1(string 0 nombre del programa)
    int return_value = TRUE;
    
    uint8_t * key =NULL;
    if (argc>MIN_ARGC)
    {
        return_value = PARSER_RETURN_ERROR;
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
