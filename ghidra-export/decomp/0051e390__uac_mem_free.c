// func _uac_mem_free @ 0051e390 size=156

void _uac_mem_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (mem_debug_switch != 0) {
      pthread_mutex_lock((pthread_mutex_t *)&mutex);
      mem_count = mem_count + -1;
      pthread_mutex_unlock((pthread_mutex_t *)&mutex);
    }
    free(param_1);
    return;
  }
  return;
}

