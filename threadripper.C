{
#include <pthread.h>

  #define THREADS 10
  int i=0;
  int rc;
  pthread_t ts[THREADS];


  for(;i<THREADS; i++){
    cout << "Initializing thread from main() id:" <<i <<endl;
    struct arg_struct{
        int x;
        char c;
    }args;
    struct arg_struct *arg;
    arg = malloc(sizeof(struct arg_struct));
    arg->x = rand()&4;
    arg->c = rand()&8+'a';

    rc = pthread_create(&ts[i], NULL, some_function,(void *)arg); 
    if(rc){
      cout <<"can't make threads" << endl;
    }
  }
  pthread_exit(NULL);
}
