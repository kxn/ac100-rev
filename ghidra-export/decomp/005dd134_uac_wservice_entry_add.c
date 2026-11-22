// func uac_wservice_entry_add @ 005dd134 size=580

int uac_wservice_entry_add(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_28 [2];
  
  local_28[0] = 0;
  iVar3 = wserv_db_entry_add();
  if ((g_wserv_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_entry_add() wserv_id=%d.\r\n",
           "uac_wservice_entry_add",0x149f,iVar3);
  }
  iVar4 = apmngr_db_get_ap_max();
  uVar5 = apmngr_db_get_ap_max();
  uVar5 = (iVar4 >> 5) + (uint)((uVar5 & 0x1f) != 0);
  iVar4 = FUN_004082a0(uVar5,4,0x14a1);
  if (iVar4 == 0) {
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n","uac_wservice_entry_add",0x14a4);
    }
  }
  else if ((iVar3 != -1) && (*(int *)(param_1 + 0x11f) != 0)) {
    uVar1 = param_1 + 0x80U & 3;
    uVar2 = param_1 + 0x83U & 3;
    uac_wservice_refresh_bind_list
              ((*(int *)((param_1 + 0x80U) - uVar1) << uVar1 * 8 |
               uVar5 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)((param_1 + 0x83U) - uVar2) >> (3 - uVar2) * 8,
               *(undefined2 *)(param_1 + 0x123),*(undefined2 *)(param_1 + 0x125),iVar4,local_28);
    uVar7 = *(undefined4 *)(param_1 + 0x80);
    iVar6 = apmngr_db_get_ap_max();
    uVar5 = apmngr_db_get_ap_max();
    iVar6 = wserv_db_entry_get_binded_ap_id_bm
                      (uVar7,iVar4,(iVar6 >> 5) + (uint)((uVar5 & 0x1f) != 0),local_28);
    if ((iVar6 != 0) && ((g_wserv_error != 0 && (iVar6 = is_target_debug_ap(), iVar6 != 0)))) {
      printf("<wserv>[error]%s(): %d  -> wserv_db_entry_get_binded_ap_id_bm() fail. wserv_id[%d]\r\n"
             ,"uac_wservice_entry_add",0x14ae,*(undefined4 *)(param_1 + 0x80));
    }
    _uac_wserv_update_aps_md5(iVar4,local_28[0]);
  }
  if ((g_wserv_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> uac_wservice_entry_add() finish, wserv_id=%d.\r\n",
           "uac_wservice_entry_add",0x14b5,iVar3);
  }
  if (iVar4 != 0) {
    FUN_00407df0(iVar4);
  }
  return iVar3;
}

