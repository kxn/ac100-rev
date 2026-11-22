// func cw_priv_rrm_neighs_list_assemble @ 005be67c size=712

undefined4 cw_priv_rrm_neighs_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar6 < 0x20) {
    cw_protocol_restore8();
    cw_protocol_restore8(param_1,pbVar6[1]);
    if (*(ushort *)(pbVar6 + 2) < 0x21) {
      cw_protocol_restore16(param_1);
      if (*(short *)(pbVar6 + 2) != 0) {
        iVar2 = 0;
        if (*(int *)(pbVar6 + 4) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          pcVar3 = "[CW_ERROR]%32s():%4d neigh_list is NULL\n";
          uVar4 = 0x11b;
LAB_005be8fc:
          printf(pcVar3,"cw_priv_rrm_neighs_list_assemble",uVar4);
          return 0xffffffff;
        }
        while (iVar2 < (int)(uint)*(ushort *)(pbVar6 + 2)) {
          iVar7 = iVar2 * 0xc;
          cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar6 + 4) + iVar7,6);
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar6 + 4) + iVar7 + 6));
          cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar6 + 4) + iVar7 + 7));
          if (*(char *)(*(int *)(pbVar6 + 4) + iVar7 + 7) == '\0') {
            iVar2 = iVar2 + 1;
          }
          else {
            if (*(int *)(*(int *)(pbVar6 + 4) + iVar7 + 8) == 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar2 = is_target_debug_ap();
              if (iVar2 == 0) {
                return 0xffffffff;
              }
              pcVar3 = "[CW_ERROR]%32s():%4d neigh_list\'s rssi list is NULL\n";
              uVar4 = 0x127;
              goto LAB_005be8fc;
            }
            for (iVar8 = 0; iVar8 < (int)(uint)*(byte *)(*(int *)(pbVar6 + 4) + iVar7 + 7);
                iVar8 = iVar8 + 1) {
              iVar9 = iVar8 * 3;
              cw_protocol_restore8
                        (param_1,*(undefined1 *)(*(int *)(*(int *)(pbVar6 + 4) + iVar7 + 8) + iVar9)
                        );
              cw_protocol_restore8
                        (param_1,*(undefined1 *)
                                  (*(int *)(*(int *)(pbVar6 + 4) + iVar7 + 8) + iVar9 + 1));
              cw_protocol_restore8
                        (param_1,*(undefined1 *)
                                  (*(int *)(*(int *)(pbVar6 + 4) + iVar7 + 8) + iVar9 + 2));
            }
            iVar2 = iVar2 + 1;
          }
        }
      }
      if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar5 = (uint)*(ushort *)(pbVar6 + 2);
    pcVar3 = "[CW_ERROR]%32s():%4d neighbor count(%d) is wrong\n";
    uVar4 = 0x112;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar5 = (uint)*pbVar6;
    pcVar3 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x10a;
  }
  printf(pcVar3,"cw_priv_rrm_neighs_list_assemble",uVar4,uVar5);
  return 0xffffffff;
}

