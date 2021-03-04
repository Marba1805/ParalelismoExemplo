#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *funcao(void *args)
{
  int i;
  int a =(int)args ;
  printf("iniciando contagem na thread %d ...\n", a);

  for(i=0;i<10000000;i++)
  {
    a+=1;
  }
  a -= (i*2/100);
  printf("saindoda thread\n");
  pthread_exit((void*)a);
}
int main(int argc, char* argv[])
{
int qtde = 7; // variavel global da errado, por isso que eu fiz qtde virar uma local
  pthread_t ts[qtde];
int i =1;
for(int i=0; i<qtde;i++)
{
  printf("criando t%d\n", i+1);
pthread_create(&ts[i],NULL , funcao, (void *) i); //cria 1 thread
  
}
  sleep(5);//dormir
  printf("dormindo \n");
  int res;
  for(i=0;i<qtde;i++)
  {
  pthread_join(ts[i],&res);
  printf("resultados de t%d :%d \n", res); 
  }
  printf("saindo\n");
  pthread_exit(NULL);
  return 0;
}