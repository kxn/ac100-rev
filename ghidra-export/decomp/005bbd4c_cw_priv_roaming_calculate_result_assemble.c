// func cw_priv_roaming_calculate_result_assemble @ 005bbd4c size=972

undefined4 cw_priv_roaming_calculate_result_assemble(int param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  
  puVar10 = *(undefined1 **)(param_2 + 0x10);
  uVar3 = *(ushort *)(param_1 + 4);
  if ((0x80 < *(uint *)(puVar10 + 4)) || (0x80 < *(uint *)(puVar10 + 8))) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d Para is out of range[%u:%u]\n",
           "cw_priv_roaming_calculate_result_assemble",0x133,*(undefined4 *)(puVar10 + 4),
           *(undefined4 *)(puVar10 + 8));
    return 0xffffffff;
  }
  if ((*(uint *)(puVar10 + 4) == 0) || (*(int *)(puVar10 + 0x10) != 0)) {
    if (*(uint *)(puVar10 + 8) == 0) {
      uVar1 = *puVar10;
    }
    else {
      if (*(int *)(puVar10 + 0xc) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffffffff;
        }
        pcVar8 = "[CW_ERROR]%32s():%4d ap union is null\n";
        uVar9 = 0x13f;
        goto LAB_005bc060;
      }
      uVar1 = *puVar10;
    }
    uVar11 = 0;
    cw_protocol_restore8(param_1,uVar1);
    cw_protocol_restore8(param_1,puVar10[1]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar10 + 4));
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar10 + 8));
    bVar4 = *(int *)(puVar10 + 8) != 0;
    if (*(int *)(puVar10 + 8) == 0) {
      iVar5 = *(int *)(puVar10 + 4);
    }
    else {
      while (bVar4) {
        iVar5 = uVar11 * 6;
        uVar11 = uVar11 + 1;
        cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar10 + 0xc) + iVar5,6);
        bVar4 = uVar11 < *(uint *)(puVar10 + 8);
      }
      iVar5 = *(int *)(puVar10 + 4);
    }
    uVar11 = 0;
    if (iVar5 != 0) {
      for (; uVar11 < *(uint *)(puVar10 + 4); uVar11 = uVar11 + 1) {
        iVar5 = uVar11 * 0x1c;
        iVar13 = 0;
        cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar10 + 0x10) + iVar5,6);
        cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar10 + 0x10) + iVar5 + 6,0x10);
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar10 + 0x10) + iVar5 + 0x16));
        bVar2 = *(byte *)(*(int *)(puVar10 + 0x10) + iVar5 + 0x16);
        if (bVar2 == 0) {
          iVar6 = *(int *)(puVar10 + 0x10);
        }
        else {
          if (*(int *)(*(int *)(puVar10 + 0x10) + iVar5 + 0x18) == 0) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return 0xffffffff;
            }
            pcVar8 = "[CW_ERROR]%32s():%4d radio_list is null[%d]\n";
            uVar9 = 0x158;
LAB_005bc0d4:
            printf(pcVar8,"cw_priv_roaming_calculate_result_assemble",uVar9,uVar11);
            return 0xffffffff;
          }
          if (6 < bVar2) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return 0xffffffff;
            }
            pcVar8 = "[CW_ERROR]%32s():%4d radio_list is overflow[%d]\n";
            uVar9 = 0x15d;
            goto LAB_005bc0d4;
          }
          iVar6 = *(int *)(puVar10 + 0x10);
        }
        for (; iVar13 < (int)(uint)*(byte *)(iVar6 + iVar5 + 0x16); iVar13 = iVar13 + 1) {
          iVar12 = iVar13 * 10;
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(iVar6 + iVar5 + 0x18) + iVar12));
          cw_protocol_restore8
                    (param_1,*(undefined1 *)
                              (*(int *)(*(int *)(puVar10 + 0x10) + iVar5 + 0x18) + iVar12 + 1));
          cw_protocol_restore8
                    (param_1,*(undefined1 *)
                              (*(int *)(*(int *)(puVar10 + 0x10) + iVar5 + 0x18) + iVar12 + 2));
          cw_protocol_restore_raw_bytes
                    (param_1,*(int *)(*(int *)(puVar10 + 0x10) + iVar5 + 0x18) + iVar12 + 3,6);
          cw_protocol_restore8
                    (param_1,*(undefined1 *)
                              (*(int *)(*(int *)(puVar10 + 0x10) + iVar5 + 0x18) + iVar12 + 9));
          iVar6 = *(int *)(puVar10 + 0x10);
        }
      }
    }
    uVar7 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar3 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar7 = 0;
    }
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    pcVar8 = "[CW_ERROR]%32s():%4d ret list is null\n";
    uVar9 = 0x13a;
LAB_005bc060:
    uVar7 = 0xffffffff;
    printf(pcVar8,"cw_priv_roaming_calculate_result_assemble",uVar9);
  }
  return uVar7;
}

