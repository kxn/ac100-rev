// func _radius_random_vector @ 0043df88 size=176

void _radius_random_vector(void *param_1)

{
  time_t tVar1;
  __pid_t _Var2;
  __pid_t _Var3;
  void *__dest;
  void *pvVar4;
  int local_18 [3];
  
  tVar1 = time((time_t *)0x0);
  _Var2 = getppid();
  _Var3 = getpid();
  srand(tVar1 + _Var2 + _Var3);
  __dest = param_1;
  do {
    local_18[0] = rand();
    pvVar4 = (void *)((int)__dest + 4);
    memcpy(__dest,local_18,4);
    __dest = pvVar4;
  } while (pvVar4 != (void *)((int)param_1 + 0x10));
  return;
}

