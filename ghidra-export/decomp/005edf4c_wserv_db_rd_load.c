// func wserv_db_rd_load @ 005edf4c size=1148

undefined4 wserv_db_rd_load(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *__format;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  
  if (param_1 == (undefined4 *)0x0) {
    if (g_wserv_error != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      printf("<wserv>[error]%s(): %d  -> entry is null!\r\n","wserv_db_rd_load",0xbf3);
      return 0xffffffff;
    }
  }
  else {
    uVar1 = rdmngr_db_generate_rd_idx_by_rd_id(*param_1);
    if (-1 < (int)uVar1) {
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar4 = apmngr_db_get_sensor_max();
      iVar5 = rdmngr_profile_get_max_rd_per_ap();
      if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
        iVar2 = uVar1 * 0xc;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        if (*(char *)(DAT_007cbf04 + iVar2) == '\0') {
          cVar10 = '\x01';
          _wserv_init_rd((char *)(DAT_007cbf04 + iVar2) + 4);
          uVar1 = 0;
          *(undefined4 *)(DAT_007cbf04 + iVar2 + 4) = *param_1;
          while (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar1 < uVar6) {
            iVar3 = uVar1 * 6;
            if (*(short *)(param_1[1] + iVar3 + 2) == -1) {
LAB_005ee1a4:
              uVar1 = uVar1 + 1;
              cVar10 = cVar10 + '\x01';
            }
            else {
              memcpy((void *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3),
                     (void *)(param_1[1] + iVar3),6);
              *(char *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 1) = cVar10;
              uVar6 = (uint)*(short *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 2);
              if ((((int)uVar6 < 0) || (l_wserv_profile <= uVar6)) ||
                 (*(int *)(DAT_007cbefc + uVar6 * 0x21c + 0xc) == 0)) goto LAB_005ee1a4;
              puVar7 = (undefined4 *)wserv_malloc(8);
              if (puVar7 == (undefined4 *)0x0) {
                uVar9 = 0xffffffff;
                if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  __format = "<wserv>[error]%s(): %d  -> no memory!\r\n";
                  uVar8 = 0xc17;
LAB_005ee380:
                  uVar9 = 0xffffffff;
                  printf(__format,"wserv_db_rd_load",uVar8);
                }
                goto LAB_005ee0c8;
              }
              *puVar7 = *(undefined4 *)(DAT_007cbf04 + iVar2 + 4);
              *(undefined1 *)(puVar7 + 1) =
                   *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3 + 1);
              iVar4 = FUN_00408380(*(undefined4 *)(DAT_007cbefc + uVar6 * 0x21c + 0x218),puVar7);
              if (iVar4 != 0) {
                uVar9 = 0xffffffff;
                if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  __format = "<wserv>[error]%s(): %d  -> uac_hash_add() fail!\r\n";
                  uVar8 = 0xc1e;
                  goto LAB_005ee380;
                }
                goto LAB_005ee0c8;
              }
              *(undefined1 *)(*(int *)(DAT_007cbf04 + iVar2 + 8) + iVar3) = 1;
              uVar6 = (uint)*(short *)(param_1[1] + iVar3 + 4);
              if (uVar6 < 0x1001) {
                iVar3 = _wserv_db_vlan_ap_hash_op(uVar6,*param_1,*(undefined1 *)(puVar7 + 1),1);
                if (iVar3 == 0) goto LAB_005ee1a4;
                uVar9 = 0xffffffff;
                if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("<wserv>[error]%s(): %d  -> _wserv_db_vlan_ap_hash_op() fail, vlan/rd_id/wlan_id=%d/%d/%d\r\n"
                         ,"wserv_db_rd_load",0xc2c,uVar6,*param_1,(uint)*(byte *)(puVar7 + 1));
                }
                goto LAB_005ee0c8;
              }
              if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
              goto LAB_005ee1a4;
              printf("<wserv>[error]%s(): %d  -> vlan_id[%d] is invalid!\r\n","wserv_db_rd_load",
                     0xc26,uVar6);
              uVar1 = uVar1 + 1;
              cVar10 = cVar10 + '\x01';
            }
          }
          uVar9 = 0;
          *(undefined1 *)(DAT_007cbf04 + iVar2 + 1) = 1;
          *(undefined1 *)(DAT_007cbf04 + iVar2) = 1;
          DAT_007cbf00 = DAT_007cbf00 + 1;
        }
        else {
          if ((g_wserv_warning != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> idx[%d] has been used, rd_id[%d]!\r\n",
                   "wserv_db_rd_load",0xc01,uVar1,*param_1);
          }
          uVar9 = 0xffffffff;
          *(undefined1 *)(DAT_007cbf04 + iVar2 + 1) = 1;
        }
LAB_005ee0c8:
        FUN_00407f30(DAT_007cbef0);
        return uVar9;
      }
    }
    if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> rf_id[%d] is invalid!\r\n","wserv_db_rd_load",0xbfa,
             *param_1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

