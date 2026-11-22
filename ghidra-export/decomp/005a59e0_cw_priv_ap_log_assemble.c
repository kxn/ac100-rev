// func cw_priv_ap_log_assemble @ 005a59e0 size=552

undefined4 cw_priv_ap_log_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  ushort *puVar6;
  undefined4 uVar7;
  int iVar8;
  
  puVar6 = *(ushort **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*puVar6 < 0x21) {
    cw_protocol_restore16();
    if (*puVar6 == 0) {
      uVar2 = *(ushort *)(param_1 + 4);
    }
    else {
      iVar3 = 0;
      if (*(int *)(puVar6 + 2) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        pcVar4 = "[CW_ERROR]%32s():%4d log list should not be NULL\n";
        uVar5 = 0xe8;
LAB_005a5bc0:
        printf(pcVar4,"cw_priv_ap_log_assemble",uVar5);
        return 0xffffffff;
      }
      while (iVar3 < (int)(uint)*puVar6) {
        iVar8 = iVar3 * 8;
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar6 + 2) + iVar8));
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar6 + 2) + iVar8 + 1));
        cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(puVar6 + 2) + iVar8 + 2));
        uVar2 = *(ushort *)(*(int *)(puVar6 + 2) + iVar8 + 2);
        if (0x400 < uVar2) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          pcVar4 = "[CW_ERROR]%32s():%4d log\'s len(%d) is too large\n";
          uVar5 = 0xf3;
          uVar1 = *(ushort *)(*(int *)(puVar6 + 2) + iVar8 + 2);
          goto LAB_005a5b24;
        }
        if (uVar2 == 0) {
          iVar3 = iVar3 + 1;
        }
        else {
          if (*(int *)(*(int *)(puVar6 + 2) + iVar8 + 4) == 0) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              return 0xffffffff;
            }
            pcVar4 = "[CW_ERROR]%32s():%4d log content should not be NULL\n";
            uVar5 = 0xfa;
            goto LAB_005a5bc0;
          }
          cw_protocol_restore_raw_bytes(param_1);
          iVar3 = iVar3 + 1;
        }
      }
      uVar2 = *(ushort *)(param_1 + 4);
    }
    uVar7 = 0xffffffff;
    if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      uVar1 = *puVar6;
      pcVar4 = "[CW_ERROR]%32s():%4d log_num(%d) is too large\n";
      uVar5 = 0xde;
LAB_005a5b24:
      uVar7 = 0xffffffff;
      printf(pcVar4,"cw_priv_ap_log_assemble",uVar5,(uint)uVar1);
    }
  }
  return uVar7;
}

