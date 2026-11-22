// func _wserv_db_info_collect_by_vlan @ 005ebf94 size=476

void _wserv_db_info_collect_by_vlan(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 auStack_238 [520];
  int local_30;
  
  uVar8 = 0;
  memset(auStack_238,0,0x205);
  puVar7 = param_1;
  local_30 = param_2 + 4;
  do {
    uVar1 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 <= uVar8) {
      return;
    }
    uVar8 = uVar8 + 1;
    uVar1 = 0;
    uVar2 = rdmngr_db_generate_rd_id(*param_1,uVar8);
    while (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), uVar1 < uVar3) {
      if (*(char *)(puVar7[2] + uVar1) == '\0') {
        uVar1 = uVar1 + 1;
      }
      else {
        memset(auStack_238,0,0x205);
        iVar5 = DAT_007cbf04;
        iVar4 = rdmngr_db_generate_rd_idx_by_rd_id(uVar2);
        iVar9 = uVar1 * 6;
        iVar5 = wserv_db_get_entry_by_id
                          ((int)*(short *)(*(int *)(iVar5 + iVar4 * 0xc + 8) + iVar9 + 2),
                           auStack_238);
        if (iVar5 == 0) {
          iVar5 = wserv_calloc(1,0x220);
          if (iVar5 == 0) {
            if (g_wserv_warning == 0) {
              return;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return;
            }
            printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n","_wserv_db_info_collect_by_vlan",
                   0x5b3);
            return;
          }
          memcpy((void *)(iVar5 + 0x1a),auStack_238,0x205);
          *(undefined4 *)(iVar5 + 0x10) = uVar2;
          iVar4 = DAT_007cbf04;
          uVar1 = uVar1 + 1;
          iVar6 = rdmngr_db_generate_rd_idx_by_rd_id(uVar2);
          *(undefined1 *)(iVar5 + 0x14) =
               *(undefined1 *)(*(int *)(iVar4 + iVar6 * 0xc + 8) + iVar9 + 1);
          FUN_004086b0(local_30,iVar5);
        }
        else {
          uVar1 = uVar1 + 1;
        }
      }
    }
    puVar7 = puVar7 + 1;
  } while( true );
}

