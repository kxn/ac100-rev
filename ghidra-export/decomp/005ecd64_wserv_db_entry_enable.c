// func wserv_db_entry_enable @ 005ecd64 size=392

undefined4 wserv_db_entry_enable(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (((int)param_1 < 0) || (l_wserv_profile <= param_1)) {
    uVar2 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_entry_enable",0x9d7,
             param_1);
    }
  }
  else {
    FUN_004082d0(DAT_007cbef0,0xffffffff);
    if (*(int *)(DAT_007cbefc + param_1 * 0x21c + 0xc) == 0) {
      uVar2 = 0xffffffff;
      if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n","wserv_db_entry_enable",
               0x9e6,param_1);
      }
    }
    else {
      local_28 = 1;
      FUN_0051ad88(&local_24);
      iVar1 = DAT_007cbefc + param_1 * 0x21c;
      *(undefined4 *)(iVar1 + 299) = 1;
      iVar1 = *(int *)(iVar1 + 0x218);
      uVar2 = 0;
      if ((iVar1 != 0) && (param_2 != 0)) {
        FUN_00408570(iVar1,_wserv_add_wlan_db_info_collect,&local_28);
      }
    }
    FUN_00407f30(DAT_007cbef0);
    _wserv_db_do_evt(&local_24,param_2,0);
  }
  return uVar2;
}

