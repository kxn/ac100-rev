// func rdmngr_dbg_idx_set_all @ 00621f24 size=124

void rdmngr_dbg_idx_set_all(void)

{
  void *__s;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_007cc65c;
  __s = g_rdmngr_dbg_idx;
  if (g_rdmngr_dbg_idx != (void *)0x0) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    memset(__s,1,(iVar2 + iVar3 + iVar4) * iVar1);
    return;
  }
  return;
}

