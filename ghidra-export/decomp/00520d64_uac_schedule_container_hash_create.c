// func uac_schedule_container_hash_create @ 00520d64 size=832

undefined4 *
uac_schedule_container_hash_create
          (char *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,
          int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *__dest;
  char acStack_50 [40];
  
  puVar2 = (undefined4 *)0x0;
  memset(acStack_50,0,0x26);
  puVar3 = puVar2;
  if ((((((param_1 != (char *)0x0) && (param_4 != 0)) && (param_5 != 0)) &&
       ((param_6 != 0 && (puVar3 = (undefined4 *)0x0, param_7 != 0)))) &&
      ((param_8 != 0 && ((puVar3 = puVar2, param_9 != 0 && (param_10 != 0)))))) &&
     (puVar2 = (undefined4 *)uac_mem_malloc_my(0x80,0x10f), puVar3 = puVar2,
     puVar2 != (undefined4 *)0x0)) {
    memset(puVar2,0,0x80);
    __dest = (char *)(puVar2 + 3);
    uac_list_init(puVar2 + 0xd);
    uac_list_init(puVar2 + 0x10);
    puVar2[0x13] = 0xffffffff;
    strncpy(__dest,param_1,0x20);
    *puVar2 = param_2;
    puVar2[1] = param_3;
    puVar2[0x18] = param_8;
    puVar2[0x17] = param_9;
    puVar2[0x16] = param_10;
    iVar1 = uac_hash_new_fixed(uac_schedule_container_hash_obj_func,param_5,
                               uac_schedule_container_hash_cmp_func,param_3);
    puVar2[0x1a] = iVar1;
    if (iVar1 != 0) {
      puVar2[0x19] = 1;
      puVar2[0x1b] = param_4;
      puVar2[0x1d] = param_6;
      puVar2[0x1c] = param_5;
      puVar2[0x1e] = param_7;
      iVar1 = _uac_timer_add(*puVar2,0,uac_schedule_container_timer_callback,puVar2,0,
                             "uac_schedule_container_hash_create",299);
      puVar2[2] = iVar1;
      if (iVar1 != -1) {
        snprintf(acStack_50,0x25,"%s_mutex",__dest);
        iVar1 = uac_mutex_create(acStack_50,0);
        puVar2[0xc] = iVar1;
        if (iVar1 != 0) {
          memset(acStack_50,0,0x26);
          snprintf(acStack_50,0x25,"%s_list",__dest);
          iVar1 = uac_mutex_create(acStack_50,0);
          puVar2[0x14] = iVar1;
          if (iVar1 != 0) {
            iVar1 = uac_cond_create(acStack_50);
            puVar2[0x15] = iVar1;
            if (iVar1 != 0) {
              return puVar2;
            }
          }
        }
      }
    }
    if (puVar2[0x1a] != 0) {
      uac_hash_delete();
      puVar2[0x1a] = 0;
    }
    if (puVar2[2] != -1) {
      uac_timer_remove();
      puVar2[2] = 0xffffffff;
    }
    if (puVar2[0xc] != 0) {
      uac_mutex_destroy();
      puVar2[0xc] = 0;
    }
    if (puVar2[0x14] != 0) {
      uac_mutex_destroy();
      puVar2[0x14] = 0;
    }
    if (puVar2[0x15] != 0) {
      uac_cond_destroy();
      puVar2[0x15] = 0;
    }
    puVar3 = (undefined4 *)0x0;
    uac_mem_free_my(puVar2);
  }
  return puVar3;
}

