/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: matias
 *
 * Created on 11 de marzo de 2017, 17:48
 */

#include <stdio.h>
#include <stdlib.h>
#include "PARSER.h"

/*
 * 
 */


int parse(char *key, char *value, void *userData);
 
int main(int argc, char** argv) {
    
  char  *args[] ={"nombre","-a","56","hola"};
  void * h =NULL;  
  int cantidadDeArgumentos = 4;
  int cantidad_de_paramtros_recividos =0;
  
  if((cantidad_de_paramtros_recividos=(parseCmdLine(cantidadDeArgumentos, args,parse, h)))==-1)
  {
      printf("error");
  }
   printf("%d \n",cantidad_de_paramtros_recividos);  
    
    

    return (EXIT_SUCCESS);
}

int parse(char *key, char *value, void *userData)
{
    if(key==NULL)
    {
        
        printf("LLEGO NULL \n");
    }
    else
    {
       printf("%s \n",key); 
    }
    printf("%s \n",value);
    return 1;
}