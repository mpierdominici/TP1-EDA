
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
#include "PARSER.h"
#define ERROR 0
#define NO_ERROR 1

#define MIN_ARGC 2 //cantidad  minima de argumentos a recivir por cmd
#define TRUE 1
#define FALSE 0
#define KEY '-'//caracter previo al key
#define TERMINADOR '\0' 





int parseCmdLine(int argc, char *argv[], pCallback p, void *userData)
{
   
    uint8_t end_runing=FALSE;
    int16_t counter_string = TRUE;//contador que apunta al string enviado por consola deseado, inicializado en 1(string 0 nombre del programa)
    int16_t return_value = TRUE;//variable que contiene lo que devuelve la funcion parseCmdLine
    uint8_t * key =NULL;//variable que almacena el key
    int16_t contador_opciones_parametros = FALSE;//contador que almacena la cantidad de opciones y parametros correctamanete ingresados
    if (argc>MIN_ARGC)//evaluo si hay sufucientes argumentos
    {
        return_value = PARSER_RETURN_ERROR;//en caso de que no los haya, detengo la ejecucion y devuelvo error
    }
    else
    {
        while(!end_runing)
        {
            if (((*(argv[counter_string]))==KEY)&&((*((argv[counter_string])+1))!=TERMINADOR )&&(counter_string<argc))//evaluo si recivo un key
            {
                key=(uint8_t *)((argv[counter_string])+1);//almaceno el puntero a en key para su posterior uso
                counter_string++;//incremento el contador de string para ver cual es el proximo string
                if((*(argv[counter_string]))!=TERMINADOR )//evaluo si hay string despues del key
                {
                    if (((*p)(key,argv[counter_string],userData))!=ERROR)//llamo al calback con los parametros obtenidos, y evaluo si devuelve error
                    {
                        
                        contador_opciones_parametros++;
                        counter_string++;  
                    }
                    else
                    {
                        end_runing=TRUE;
                        return_value=PARSER_RETURN_ERROR;
                    }
                       
                }
                else
                {
                    end_runing=TRUE;
                    return_value=PARSER_RETURN_ERROR;  
                }
            }
            else if (((*(argv[counter_string]))!=TERMINADOR )&&(counter_string<argc))
            {
                if (((*p)(NULL,argv[counter_string],userData))!=ERROR)//llamo al calback con los parametros obtenidos, y evaluo si devuelve error
                    {
                        
                        contador_opciones_parametros++;
                        counter_string++;  
                    }
                    else
                    {
                        end_runing=TRUE;
                        return_value=PARSER_RETURN_ERROR;
                    }
               
            }
            else if (!(counter_string<argc))//cuando ya se leyeron todos los argumentos y no hubo error
            {
                end_runing=TRUE;
                return_value=contador_opciones_parametros;
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
