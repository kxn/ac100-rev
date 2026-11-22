// func uac_mutex_get_info_by_reference @ 00523140 size=280

undefined4 uac_mutex_get_info_by_reference(undefined *param_1,void *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined *puVar3;
  code *pcVar4;
  
  uVar1 = 0xffffffff;
  if ((param_1 != (undefined *)0x0) && (param_2 != (void *)0x0)) {
    memset(param_2,0,0x34);
    pthread_mutex_lock((pthread_mutex_t *)&uac_sync_mutex);
    pcVar4 = uac_list_first;
    puVar3 = &uac_mutex_list;
    while( true ) {
      puVar3 = (undefined *)(*pcVar4)(puVar3);
      if (puVar3 == (undefined *)0x0) break;
      if (param_1 == puVar3 + -0x28) {
        memcpy(param_2,param_1,0x34);
        uVar1 = 0;
        pcVar2 = strdup(*(char **)(puVar3 + -0x10));
        *(char **)((int)param_2 + 0x18) = pcVar2;
        memset((void *)((int)param_2 + 0x28),0,0xc);
        goto LAB_005231e4;
      }
      pcVar4 = uac_list_next;
    }
    uVar1 = 0xffffffff;
LAB_005231e4:
    pthread_mutex_unlock((pthread_mutex_t *)&uac_sync_mutex);
  }
  return uVar1;
}

