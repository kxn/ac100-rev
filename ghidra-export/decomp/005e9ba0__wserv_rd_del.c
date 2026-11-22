// func _wserv_rd_del @ 005e9ba0 size=660

undefined4 _wserv_rd_del(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  char cVar9;
  undefined4 local_30;
  uint local_2c;
  
  local_30 = 0;
  local_2c = 0;
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      iVar2 = uVar1 * 0xc;
      if (*(char *)(DAT_007cbf04 + iVar2) != '\0') {
        cVar9 = '\x01';
        uVar1 = 0;
        local_30 = param_1;
        do {
          uVar6 = rdmngr_profile_get_max_wlan_per_rd();
          if (uVar6 <= uVar1) {
            *(undefined1 *)(DAT_007cbf04 + iVar2) = 0;
            _wserv_init_rd(DAT_007cbf04 + iVar2 + 4);
            DAT_007cbf00 = DAT_007cbf00 + -1;
            return 0;
          }
          pcVar7 = (char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + uVar1 * 6);
          if (*pcVar7 != '\0') {
            iVar4 = *(short *)(pcVar7 + 2) * 0x21c;
            iVar3 = DAT_007cbefc + iVar4;
            if (*(int *)(iVar3 + 0xc) != 0) {
              local_2c = CONCAT13(cVar9,local_2c._1_3_);
              iVar3 = FUN_00407fa0(*(undefined4 *)(iVar3 + 0x218),&local_30);
              if (iVar3 != 0) {
                FUN_00407f40(*(undefined4 *)(DAT_007cbefc + iVar4 + 0x218),iVar3);
                FUN_00407df0(iVar3);
              }
              iVar4 = (int)*(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + uVar1 * 6 + 4);
              iVar3 = _wserv_db_vlan_ap_hash_op(iVar4,param_1,local_2c._0_1_,0);
              if (iVar3 != 0) {
                if (g_wserv_error == 0) {
                  return 0xffffffff;
                }
                iVar2 = is_target_debug_ap();
                if (iVar2 == 0) {
                  return 0xffffffff;
                }
                printf("<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                       ,"_wserv_rd_del",0x688,iVar4,param_1,local_2c >> 0x18);
                return 0xffffffff;
              }
            }
          }
          uVar1 = uVar1 + 1;
          cVar9 = cVar9 + '\x01';
        } while( true );
      }
      if (g_wserv_warning == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar7 = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
      uVar8 = 0x671;
      goto LAB_005e9d0c;
    }
  }
  if (g_wserv_warning == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  pcVar7 = "<wserv>[warning]%s(): %d  -> id[%d] is invalid!\r\n";
  uVar8 = 0x66b;
LAB_005e9d0c:
  printf(pcVar7,"_wserv_rd_del",uVar8,uVar1);
  return 0xffffffff;
}

