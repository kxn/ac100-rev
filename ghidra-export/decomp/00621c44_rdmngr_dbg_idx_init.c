// func rdmngr_dbg_idx_init @ 00621c44 size=1

void rdmngr_dbg_idx_init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *__s;
  
  iVar1 = DAT_007cc65c;
  if (g_rdmngr_dbg_idx != (void *)0x0) {
    return;
  }
  iVar2 = apmngr_db_get_ap_max();
  iVar3 = apmngr_db_get_template_max();
  iVar4 = apmngr_db_get_sensor_max();
  __s = (void *)FUN_004082a0((iVar2 + iVar3 + iVar4) * iVar1,1,0x134e);
  iVar1 = DAT_007cc65c;
  g_rdmngr_dbg_idx = __s;
  if (__s != (void *)0x0) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    memset(__s,0,(iVar2 + iVar3 + iVar4) * iVar1);
    return;
  }
  printf("insufficient memory.");
  return;
}

