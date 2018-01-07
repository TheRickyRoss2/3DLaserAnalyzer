struct func_args{
  void * id;
  int x;
  char c;
}fargs;
void *some_function(void * fargs)
{
  long id = (long) fargs->id;

  cout <<"Thead " << args->id << " doing random shit" << endl;
  cout << "The meaning of life: "<<rand()*100 << endl;
  pthread_exit(NULL);
}
