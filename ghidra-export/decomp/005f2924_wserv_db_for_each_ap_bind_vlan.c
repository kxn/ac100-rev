// func wserv_db_for_each_ap_bind_vlan @ 005f2924 size=504

undefined4 wserv_db_for_each_ap_bind_vlan(uint param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30;
  int local_2c;
  int local_28;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  if (param_1 < 0x1001) {
    uVar4 = 0;
    if (param_2 != (code *)0x0) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      iVar3 = apmngr_db_get_sensor_max();
      iVar1 = wserv_calloc(iVar1 + iVar2 + iVar3,4);
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> no memory!\r\n","wserv_db_for_each_ap_bind_vlan",
                 0x1374);
        }
      }
      else {
        local_30 = 0;
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        local_2c = apmngr_db_get_sensor_max();
        local_2c = iVar2 + iVar3 + local_2c;
        local_28 = iVar1;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        iVar2 = *(int *)(DAT_007cbf08 + param_1 * 4);
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x10) != 0)) {
          FUN_00408570(iVar2,_ap_hash_info_collect,&local_30);
        }
        iVar2 = 0;
        FUN_00407f30(DAT_007cbef0);
        while (iVar2 < local_30) {
          uVar4 = *(undefined4 *)(local_28 + iVar2 * 4);
          iVar3 = rdmngr_db_is_ap_all_rd_disabled(uVar4);
          if (iVar3 == 0) {
            (*param_2)(uVar4,param_3);
            iVar2 = iVar2 + 1;
          }
          else {
            iVar2 = iVar2 + 1;
          }
        }
        FUN_00407df0(iVar1);
        uVar4 = 0;
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> vlan_id[%d] is invalid!\r\n",
             "wserv_db_for_each_ap_bind_vlan",0x1368,param_1);
    }
  }
  return uVar4;
}

