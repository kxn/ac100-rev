// func cw_priv_roaming_trigger_assemble @ 005bd324 size=800

undefined4 cw_priv_roaming_trigger_assemble(int param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  char *__format;
  undefined4 uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  
  puVar10 = *(undefined1 **)(param_2 + 0x10);
  uVar3 = *(ushort *)(param_1 + 4);
  if (*(uint *)(puVar10 + 4) < 0xc9) {
    if (*(uint *)(puVar10 + 4) == 0) {
      uVar1 = *puVar10;
    }
    else {
      if (*(int *)(puVar10 + 8) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d station list is null\n","cw_priv_roaming_trigger_assemble",
               0x10d);
        return 0xffffffff;
      }
      uVar1 = *puVar10;
    }
    uVar9 = 0;
    cw_protocol_restore8(param_1,uVar1);
    cw_protocol_restore8(param_1,puVar10[1]);
    cw_protocol_restore8(param_1,puVar10[2]);
    cw_protocol_restore32(param_1,*(undefined4 *)(puVar10 + 4));
    bVar5 = *(int *)(puVar10 + 4) != 0;
    if (*(int *)(puVar10 + 4) == 0) {
      uVar4 = *(ushort *)(param_1 + 4);
    }
    else {
      while (bVar5) {
        iVar6 = uVar9 * 0x10;
        iVar13 = 0;
        cw_protocol_restore_raw_bytes(param_1,*(int *)(puVar10 + 8) + iVar6,6);
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar10 + 8) + iVar6 + 6));
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar10 + 8) + iVar6 + 7));
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar10 + 8) + iVar6 + 8));
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(puVar10 + 8) + iVar6 + 9));
        bVar2 = *(byte *)(*(int *)(puVar10 + 8) + iVar6 + 9);
        if (bVar2 == 0) {
          iVar7 = *(int *)(puVar10 + 8);
        }
        else {
          if (*(int *)(*(int *)(puVar10 + 8) + iVar6 + 0xc) == 0) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              return 0xffffffff;
            }
            __format = "[CW_ERROR]%32s():%4d nbr list is null[%d]\n";
            uVar8 = 0x122;
            goto LAB_005bd588;
          }
          if (0xc < bVar2) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar6 = is_target_debug_ap();
            if (iVar6 == 0) {
              return 0xffffffff;
            }
            __format = "[CW_ERROR]%32s():%4d nbr list is overflow[%d]\n";
            uVar8 = 0x127;
            goto LAB_005bd588;
          }
          iVar7 = *(int *)(puVar10 + 8);
        }
        for (; iVar13 < (int)(uint)*(byte *)(iVar7 + iVar6 + 9); iVar13 = iVar13 + 1) {
          iVar12 = iVar13 * 9;
          cw_protocol_restore_raw_bytes(param_1,*(int *)(iVar7 + iVar6 + 0xc) + iVar12,6);
          cw_protocol_restore8
                    (param_1,*(undefined1 *)
                              (*(int *)(*(int *)(puVar10 + 8) + iVar6 + 0xc) + iVar12 + 6));
          cw_protocol_restore8
                    (param_1,*(undefined1 *)
                              (*(int *)(*(int *)(puVar10 + 8) + iVar6 + 0xc) + iVar12 + 7));
          cw_protocol_restore8
                    (param_1,*(undefined1 *)
                              (*(int *)(*(int *)(puVar10 + 8) + iVar6 + 0xc) + iVar12 + 8));
          iVar7 = *(int *)(puVar10 + 8);
        }
        uVar9 = uVar9 + 1;
        bVar5 = uVar9 < *(uint *)(puVar10 + 4);
      }
      uVar4 = *(ushort *)(param_1 + 4);
    }
    uVar11 = 0xffffffff;
    if ((uint)uVar4 - (uint)uVar3 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar11 = 0;
    }
  }
  else {
    uVar11 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      uVar9 = *(uint *)(puVar10 + 4);
      __format = "[CW_ERROR]%32s():%4d Para is out of range[%u]\n";
      uVar8 = 0x107;
LAB_005bd588:
      uVar11 = 0xffffffff;
      printf(__format,"cw_priv_roaming_trigger_assemble",uVar8,uVar9);
    }
  }
  return uVar11;
}

