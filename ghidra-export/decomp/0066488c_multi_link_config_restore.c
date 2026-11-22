// func multi_link_config_restore @ 0066488c size=184

undefined4 multi_link_config_restore(void)

{
  void *__s;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_a0 [148];
  
  memcpy(auStack_a0,&DAT_0071bb50,0x90);
  iVar1 = FUN_00408120("apmng_backup_link","settings",auStack_a0,4);
  __s = g_multi_link_array;
  if (iVar1 == 0) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_sensor_max();
    memset(__s,0,iVar1 + iVar2);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
    if (multi_link_err_switch != '\0') {
      printf("[MULTI_LINK_ERROR]%s()/%d uci req parse failed.\n","multi_link_config_restore",0x21d);
    }
  }
  return uVar3;
}

