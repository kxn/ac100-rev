// func uac_schedule_container_queue_create @ 005210a4 size=672

undefined4 *
uac_schedule_container_queue_create
          (char *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 *__s;
  int iVar1;
  undefined4 *puVar2;
  char *__dest;
  char acStack_50 [44];
  
  puVar2 = (undefined4 *)0x0;
  memset(acStack_50,0,0x26);
  if ((((param_1 != (char *)0x0) && (param_4 != 0)) && (param_5 != 0)) &&
     (__s = (undefined4 *)uac_mem_malloc_my(0x80,0x16d), puVar2 = __s, __s != (undefined4 *)0x0)) {
    memset(__s,0,0x80);
    __dest = (char *)(__s + 3);
    uac_list_init(__s + 0xd);
    uac_list_init(__s + 0x10);
    __s[0x13] = 0xffffffff;
    strncpy(__dest,param_1,0x20);
    *__s = param_2;
    __s[1] = param_3;
    __s[0x18] = param_4;
    __s[0x16] = param_5;
    __s[0x19] = 0;
    iVar1 = _uac_timer_add(param_2,0,uac_schedule_container_timer_callback,__s,0,
                           "uac_schedule_container_queue_create",0x17f);
    __s[2] = iVar1;
    if (iVar1 != -1) {
      snprintf(acStack_50,0x25,"%s_mutex",__dest);
      iVar1 = uac_mutex_create(acStack_50,0);
      __s[0xc] = iVar1;
      if (iVar1 != 0) {
        memset(acStack_50,0,0x26);
        snprintf(acStack_50,0x25,"%s_list",__dest);
        iVar1 = uac_mutex_create(acStack_50,0);
        __s[0x14] = iVar1;
        if (iVar1 != 0) {
          iVar1 = uac_cond_create(acStack_50);
          __s[0x15] = iVar1;
          if (iVar1 != 0) {
            return __s;
          }
        }
      }
    }
    if (__s[2] != -1) {
      uac_timer_remove();
      __s[2] = 0xffffffff;
    }
    if (__s[0xc] != 0) {
      uac_mutex_destroy();
      __s[0xc] = 0;
    }
    if (__s[0x14] != 0) {
      uac_mutex_destroy();
      __s[0x14] = 0;
    }
    if (__s[0x15] != 0) {
      uac_cond_destroy();
      __s[0x15] = 0;
    }
    puVar2 = (undefined4 *)0x0;
    uac_mem_free_my(__s);
  }
  return puVar2;
}

