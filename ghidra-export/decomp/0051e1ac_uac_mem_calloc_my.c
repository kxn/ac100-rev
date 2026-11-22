// func uac_mem_calloc_my @ 0051e1ac size=332

size_t * uac_mem_calloc_my(int param_1,int param_2,size_t param_3)

{
  size_t *psVar1;
  size_t __n;
  size_t *__s;
  
  __s = (size_t *)0x0;
  if ((0 < param_2) && (__n = param_1 * param_2, 0 < param_1)) {
    psVar1 = (size_t *)malloc(__n + 0x18);
    if (psVar1 != (size_t *)0x0) {
      __s = psVar1 + 4;
      *psVar1 = __n;
      psVar1[1] = param_3;
      psVar1[2] = 0xaaaaaaaa;
      psVar1[3] = 0xbbbbbbbb;
      memset(__s,0,__n);
      if (mem_debug_switch != 0) {
        pthread_mutex_lock((pthread_mutex_t *)&mutex);
        mem_count = mem_count + 1;
        pthread_mutex_unlock((pthread_mutex_t *)&mutex);
      }
      pthread_mutex_lock((pthread_mutex_t *)&mutex);
      (&g_lines)[param_3] = (&g_lines)[param_3] + 1;
      pthread_mutex_unlock((pthread_mutex_t *)&mutex);
      *(undefined4 *)((int)psVar1 + __n + 0x10) = 0xaaaaaaaa;
      *(undefined4 *)((int)psVar1 + __n + 0x14) = 0xbbbbbbbb;
    }
  }
  return __s;
}

