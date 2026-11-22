// func _uac_mem_calloc @ 0051e42c size=200

void * _uac_mem_calloc(size_t param_1,size_t param_2)

{
  void *__s;
  
  __s = (void *)0x0;
  if ((0 < (int)param_2) && (0 < (int)param_1)) {
    __s = calloc(param_1,param_2);
    if (__s != (void *)0x0) {
      memset(__s,0,param_1 * param_2);
    }
    if ((mem_debug_switch != 0) && (__s != (void *)0x0)) {
      pthread_mutex_lock((pthread_mutex_t *)&mutex);
      mem_count = mem_count + 1;
      pthread_mutex_unlock((pthread_mutex_t *)&mutex);
    }
  }
  return __s;
}

