// func wserv_db_entry_for_each_rd @ 005ed45c size=656

undefined4 wserv_db_entry_for_each_rd(uint param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if (((int)param_1 < 0) || (l_wserv_profile <= param_1)) {
    if (g_wserv_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n","wserv_db_entry_for_each_rd",0xa9c,
           param_1);
    return 0xffffffff;
  }
  if (param_2 == (code *)0x0) {
    if (g_wserv_warning == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    printf("<wserv>[warning]%s(): %d  -> cb is null!\r\n","wserv_db_entry_for_each_rd",0xaa2);
    return 0;
  }
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  if (*(int *)(DAT_007cbefc + param_1 * 0x21c + 0xc) == 0) {
    if ((g_wserv_warning == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005ed548;
    __format = "<wserv>[warning]%s(): %d  -> entry.id[%d] is not used!\r\n";
    uVar4 = 0xaa9;
  }
  else {
    local_30 = 0;
    FUN_0051ad88(&local_2c);
    iVar1 = *(int *)(DAT_007cbefc + param_1 * 0x21c + 0x218);
    if (iVar1 != 0) {
      FUN_00408570(iVar1,_wserv_db_info_collect,&local_30);
    }
    if ((g_wserv_debug == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005ed548;
    __format = "<wserv>[debug]%s(): %d  -> @ wserv_id=%d\n\r\n";
    uVar4 = 0xab3;
  }
  printf(__format,"wserv_db_entry_for_each_rd",uVar4,param_1);
LAB_005ed548:
  FUN_00407f30(DAT_007cbef0);
  iVar1 = FUN_004081b0(&local_2c);
  while (iVar1 != 0) {
    iVar2 = FUN_00408680(iVar1);
    iVar3 = (*param_2)(iVar1 + 0x10,iVar1 + 0x1a,param_3);
    if (((iVar3 != 0) && (g_wserv_warning != 0)) && (iVar3 = is_target_debug_ap(iVar1), iVar3 != 0))
    {
      printf("<wserv>[warning]%s(): %d  -> do cb for rd_id[%d] wlan_id[%d] fail.\r\n",
             "wserv_db_entry_for_each_rd",0xac1,*(undefined4 *)(iVar1 + 0x10),
             (uint)*(byte *)(iVar1 + 0x14));
    }
    FUN_00407df0(iVar1);
    iVar1 = iVar2;
  }
  return 0;
}

