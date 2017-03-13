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
    
  char  *args[] ={"nombre","-a","56"};
  void * h =NULL;  
  int cantidadDeArgumentos = 3;
 
  
  if((parseCmdLine(cantidadDeArgumentos, args,parse, h))==-1)
  {
      printf("error");
  }
    
    
    
    

    return (EXIT_SUCCESS);
}

int parse(char *key, char *value, void *userData)
{
    return 1;
}