// func apmngr_ap_cloud_config_id_re_update @ 0053182c size=256

undefined4 apmngr_ap_cloud_config_id_re_update(undefined2 param_1)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int local_2f8 [2];
  undefined1 auStack_2f0 [728];
  
  local_2f8[0] = 0;
  memset(auStack_2f0,0,0x2d8);
  puVar1 = (ushort *)mesh_db_child_list_get_by_cap_id(param_1,local_2f8);
  if (local_2f8[0] == 0) {
    return 0;
  }
  iVar3 = 0;
  do {
    while( true ) {
      if (local_2f8[0] <= iVar3) {
        return 0;
      }
      iVar2 = apmngr_db_entry_get_by_id(*puVar1,auStack_2f0);
      if (iVar2 != 0) break;
      reset_ap_cloud_config_id_in_mem_db(*puVar1);
LAB_005318f0:
      iVar3 = iVar3 + 1;
      puVar1 = puVar1 + 1;
    }
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d get re ap entry failed id:%d\n",
             "apmngr_ap_cloud_config_id_re_update",0x610,(uint)*puVar1);
      goto LAB_005318f0;
    }
    iVar3 = iVar3 + 1;
    puVar1 = puVar1 + 1;
  } while( true );
}

