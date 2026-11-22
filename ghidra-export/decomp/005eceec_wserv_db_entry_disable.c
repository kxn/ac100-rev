// func wserv_db_entry_disable @ 005eceec size=404

undefined4 wserv_db_entry_disable(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (((int)param_1 < 0) || (l_wserv_profile <= param_1)) {
    uVar3 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_entry_disable",0xa13,
             param_1);
    }
  }
  else {
    iVar1 = param_1 * 0x21c;
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    if (*(int *)(DAT_007cbefc + iVar1 + 0xc) == 0) {
      uVar3 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> id[%d] is not used!\r\n","wserv_db_entry_disable",0xa21
               ,param_1);
      }
    }
    else {
      local_28 = 1;
      FUN_0051ad88(&local_24);
      iVar2 = *(int *)(DAT_007cbefc + iVar1 + 0x218);
      if ((iVar2 != 0) && (param_2 != 0)) {
        FUN_00408570(iVar2,_wserv_del_wlan_db_info_collect,&local_28);
      }
      uVar3 = 0;
      *(undefined4 *)(DAT_007cbefc + iVar1 + 299) = 0;
    }
    FUN_00407f30(DAT_007cbef0);
    _wserv_db_do_evt(&local_24,param_2,0);
  }
  return uVar3;
}

