// func uac_mem_malloc_my @ 0051deac size=296

int * uac_mem_malloc_my(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (0 < param_1) {
    piVar1 = (int *)malloc(param_1 + 0x18);
    if (piVar1 != (int *)0x0) {
      *piVar1 = param_1;
      piVar1[1] = param_2;
      piVar1[2] = -0x55555556;
      piVar1[3] = -0x44444445;
      if (mem_debug_switch != 0) {
        pthread_mutex_lock((pthread_mutex_t *)&mutex);
        mem_count = mem_count + 1;
        pthread_mutex_unlock((pthread_mutex_t *)&mutex);
      }
      pthread_mutex_lock((pthread_mutex_t *)&mutex);
      piVar2 = piVar1 + 4;
      (&g_lines)[param_2] = (&g_lines)[param_2] + 1;
      pthread_mutex_unlock((pthread_mutex_t *)&mutex);
      *(undefined4 *)((int)piVar1 + param_1 + 0x10) = 0xaaaaaaaa;
      *(undefined4 *)((int)piVar1 + param_1 + 0x14) = 0xbbbbbbbb;
    }
  }
  return piVar2;
}

