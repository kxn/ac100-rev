// func _wserv_del_rd_hash_cb @ 005eae14 size=548

void _wserv_del_rd_hash_cb(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = *param_2;
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id(*param_1);
  uVar8 = (uint)*(byte *)(param_1 + 1);
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (((uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) && (uVar8 != 0)) &&
       (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar8 <= uVar6)) {
      iVar2 = uVar1 * 0xc;
      iVar3 = (uVar8 - 1) * 6;
      pcVar7 = (char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3);
      if (*pcVar7 != '\0') {
        iVar5 = (int)*(short *)(pcVar7 + 4);
        iVar4 = _wserv_db_vlan_ap_hash_op(iVar5,*param_1,*(undefined1 *)(param_1 + 1),0);
        if (((iVar4 != 0) && (g_wserv_error != 0)) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                 ,"_wserv_del_rd_hash_cb",0x602,iVar5,*param_1,(uint)*(byte *)(param_1 + 1));
        }
        *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 2) = 0xffff;
        *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 4) = 0xffff;
        *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3) = 0;
        iVar2 = wserv_sqlite_notify(3,param_1,8);
        if (((iVar2 != 0) && (g_wserv_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wserv>[error]%s(): %d  -> wserv_sqlite_notify() unbind fail. rd_id=%d, wlan_id=%d!\r\n"
                 ,"_wserv_del_rd_hash_cb",0x60b,*param_1,(uint)*(byte *)(param_1 + 1));
        }
      }
    }
  }
  FUN_00407f40(*(undefined4 *)(DAT_007cbefc + iVar9 * 0x21c + 0x218),param_1);
  FUN_00407df0(param_1);
  return;
}

