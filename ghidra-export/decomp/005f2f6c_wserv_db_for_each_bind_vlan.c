// func wserv_db_for_each_bind_vlan @ 005f2f6c size=436

int wserv_db_for_each_bind_vlan(uint param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if (param_1 < 0x1001) {
    iVar3 = 0;
    if (param_2 != (code *)0x0) {
      FUN_0051ad88(&local_2c);
      FUN_004082d0(DAT_007cbef0,0xffffffff);
      iVar3 = *(int *)(DAT_007cbf08 + param_1 * 4);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x10) != 0)) {
        FUN_00408570(iVar3,_wserv_db_info_collect_by_vlan,&local_30);
      }
      FUN_00407f30(DAT_007cbef0);
      iVar3 = FUN_004081b0(&local_2c);
      while (iVar3 != 0) {
        iVar1 = FUN_00408680(iVar3);
        iVar2 = (*param_2)(iVar3 + 0x10,iVar3 + 0x1a,param_3);
        if (iVar2 == 0) {
          FUN_00407df0(iVar3);
          iVar3 = iVar1;
        }
        else if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[error]%s(): %d  -> do cb for rd_id[%d] wlan_id[%d] fail.\r\n",
                 "wserv_db_for_each_bind_vlan",0x1432,*(undefined4 *)(iVar3 + 0x10),
                 (uint)*(byte *)(iVar3 + 0x14));
        }
      }
    }
  }
  else {
    iVar3 = -1;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> vlan_id[%d] is invalid!\r\n",
             "wserv_db_for_each_bind_vlan",0x1417,param_1);
    }
  }
  return iVar3;
}

