// func wserv_db_rd_inherit @ 005f1024 size=1020

undefined4 wserv_db_rd_inherit(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  void *__dest;
  void *__src;
  char cVar11;
  
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      uVar6 = rdmngr_db_generate_rd_idx_by_rd_id(param_2);
      if (-1 < (int)uVar6) {
        iVar2 = apmngr_db_get_ap_max();
        iVar3 = apmngr_db_get_template_max();
        iVar4 = apmngr_db_get_sensor_max();
        iVar5 = rdmngr_profile_get_max_rd_per_ap();
        if (uVar6 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
          FUN_004082d0(DAT_007cbef0,0xffffffff);
          pcVar8 = (char *)(DAT_007cbf04 + uVar1 * 0xc);
          if (*pcVar8 == '\0') {
            uVar9 = 0xffffffff;
            if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005f11d0;
            pcVar8 = "<wserv>[warning]%s(): %d  -> parent_idx[%d] is not used!\r\n";
            uVar10 = 0x1167;
          }
          else {
            iVar2 = uVar6 * 0xc;
            if (*(char *)(DAT_007cbf04 + iVar2) != '\0') {
              __dest = *(void **)((char *)(DAT_007cbf04 + iVar2) + 8);
              cVar11 = '\x01';
              __src = *(void **)(pcVar8 + 8);
              uVar1 = 0;
              iVar3 = rdmngr_profile_get_max_wlan_per_rd();
              memcpy(__dest,__src,iVar3 * 6);
              while( true ) {
                uVar6 = rdmngr_profile_get_max_wlan_per_rd();
                uVar9 = 0;
                if (uVar6 <= uVar1) break;
                pcVar8 = (char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + uVar1 * 6);
                if ((*pcVar8 != '\0') && (iVar3 = (int)*(short *)(pcVar8 + 2), iVar3 != -1)) {
                  puVar7 = (undefined4 *)wserv_malloc(8);
                  if (puVar7 == (undefined4 *)0x0) {
                    uVar9 = 0xffffffff;
                    if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) break;
                    pcVar8 = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                    uVar10 = 0x1179;
                  }
                  else {
                    *puVar7 = param_2;
                    *(char *)(puVar7 + 1) = cVar11;
                    iVar3 = FUN_00408380(*(undefined4 *)(DAT_007cbefc + iVar3 * 0x21c + 0x218),
                                         puVar7);
                    if (iVar3 == 0) {
                      iVar3 = (int)*(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + uVar1 * 6 + 4);
                      if ((iVar3 == -1) ||
                         (iVar4 = _wserv_db_vlan_ap_hash_op
                                            (iVar3,*puVar7,*(undefined1 *)(puVar7 + 1),1),
                         iVar4 == 0)) goto LAB_005f1324;
                      uVar9 = 0xffffffff;
                      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                        printf("<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                               ,"wserv_db_rd_inherit",0x118a,iVar3,*puVar7,
                               (uint)*(byte *)(puVar7 + 1));
                      }
                      break;
                    }
                    uVar9 = 0xffffffff;
                    if ((g_wserv_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) break;
                    pcVar8 = "<wserv>[error]%s(): %d  -> uac_hash_add() fail!\r\n";
                    uVar10 = 0x1181;
                  }
                  uVar9 = 0xffffffff;
                  printf(pcVar8,"wserv_db_rd_inherit",uVar10);
                  break;
                }
LAB_005f1324:
                uVar1 = uVar1 + 1;
                cVar11 = cVar11 + '\x01';
              }
              goto LAB_005f11d0;
            }
            uVar9 = 0xffffffff;
            if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
            goto LAB_005f11d0;
            pcVar8 = "<wserv>[warning]%s(): %d  -> child_idx[%d] is not used!\r\n";
            uVar10 = 0x116d;
            uVar1 = uVar6;
          }
          uVar9 = 0xffffffff;
          printf(pcVar8,"wserv_db_rd_inherit",uVar10,uVar1);
LAB_005f11d0:
          FUN_00407f30(DAT_007cbef0);
          return uVar9;
        }
      }
      if (g_wserv_warning == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pcVar8 = "<wserv>[warning]%s(): %d  -> child_id[%d] is invalid!\r\n";
      uVar9 = 0x1160;
      goto LAB_005f1100;
    }
  }
  if ((g_wserv_warning == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
    return 0xffffffff;
  }
  pcVar8 = "<wserv>[warning]%s(): %d  -> parent_id[%d] is invalid!\r\n";
  uVar9 = 0x1159;
  param_2 = param_1;
LAB_005f1100:
  printf(pcVar8,"wserv_db_rd_inherit",uVar9,param_2);
  return 0xffffffff;
}

