// func rdmngr_db_rd_entry_del @ 006202ac size=1020

undefined4 rdmngr_db_rd_entry_del(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  int *piVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 local_30 [2];
  
  local_30[0] = 0;
  if (param_1 == 0) {
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[RDMNGR_ERROR]%s()/%d Invalid ap_entry.\n";
    uVar10 = 0x11b1;
  }
  else {
    uVar14 = (uint)*(ushort *)(param_1 + 0x10);
    uVar12 = *(undefined4 *)(param_1 + 0x40);
    local_30[0] = *(undefined4 *)(param_1 + 0x44);
    uVar10 = *(undefined4 *)(param_1 + 0x3c);
    if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d type:%d, isFirm:%d\n","rdmngr_db_rd_entry_del",0x11bb,
             *(undefined4 *)(param_1 + 0xc),uVar10);
    }
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if ((uVar14 < (uint)(iVar2 + iVar3)) ||
       ((49999 < uVar14 && (iVar2 = apmngr_db_get_sensor_max(), uVar14 < iVar2 + 50000U)))) {
      uVar4 = rdmngr_db_get_ap_radio_cnt(uVar12,param_1 + 0x218,local_30);
      uVar13 = 1;
      if ((int)uVar4 < 0) {
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar9 = "[RDMNGR_ERROR]%s()/%d rdmngr_db_get_ap_radio_cnt() fail, ret=%d.\n";
        uVar10 = 0x11c6;
        uVar5 = uVar4;
      }
      else {
        while( true ) {
          if ((int)uVar4 < (int)uVar13) {
            return 0;
          }
          uVar1 = *(ushort *)(param_1 + 0x10);
          uVar5 = rdmngr_db_generate_rd_idx((uint)uVar1,uVar13);
          iVar2 = DAT_007cc65c;
          if ((int)uVar5 < 0) break;
          iVar3 = apmngr_db_get_ap_max();
          iVar6 = apmngr_db_get_template_max();
          iVar7 = apmngr_db_get_sensor_max();
          if ((uint)((iVar3 + iVar6 + iVar7) * iVar2) <= uVar5) break;
          iVar2 = uVar5 * 8;
          FUN_004082d0(DAT_007cc64c,0xffffffff);
          if (*(int *)(DAT_007cc650 + iVar2 + 4) != 0) {
            uVar15 = uVar13 & 0xf | (uint)uVar1 << 4;
            if (*(int *)(param_1 + 0x3c) != 0) {
              puVar8 = (uint *)FUN_00408450(8,0x11d9);
              iVar3 = DAT_007cc650;
              if (puVar8 == (uint *)0x0) {
                if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(4), iVar3 != 0)) {
                  printf("[RDMNGR_ERROR]%s()/%d no momery.\n","rdmngr_db_rd_entry_del",0x11e4);
                }
              }
              else {
                *puVar8 = uVar15;
                puVar8[1] = (uint)*(byte *)(*(int *)(iVar3 + iVar2 + 4) + 0x4d);
                rdmngr_db_msg_send(4,puVar8);
                rdmngr_callback_proc(8,uVar15,0,0);
              }
            }
            if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[RDMNGR_DEBUG]%s()/%d ap_id:%d, rd_id:%d, rd_idx:%d, isFirm:%d\n",
                     "rdmngr_db_rd_entry_del",0x11e8,uVar14,uVar15,uVar5,
                     *(undefined4 *)(param_1 + 0x3c));
            }
            piVar11 = (int *)(DAT_007cc650 + iVar2);
            if (*piVar11 == 0) {
              FUN_00407df0();
              *(undefined4 *)(DAT_007cc650 + iVar2 + 4) = 0;
            }
            else {
              memset((void *)piVar11[1],0,0x54);
              *(undefined4 *)piVar11[1] = 0xffffffff;
            }
          }
          uVar13 = uVar13 + 1;
          FUN_00407f30(DAT_007cc64c);
        }
        if (rdmngr_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        pcVar9 = "[RDMNGR_ERROR]%s()/%d Invalid radio idx:%d.\n";
        uVar10 = 0x11d0;
      }
      printf(pcVar9,"rdmngr_db_rd_entry_del",uVar10,uVar5);
      return 0xffffffff;
    }
    if (rdmngr_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[RDMNGR_ERROR]%s()/%d Invalid ap_id.\n";
    uVar10 = 0x11bf;
  }
  printf(pcVar9,"rdmngr_db_rd_entry_del",uVar10);
  return 0xffffffff;
}

