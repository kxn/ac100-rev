// func cw_priv_port_info_assemble @ 005b8090 size=376

undefined4 cw_priv_port_info_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int iVar6;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 < 0x41) {
    cw_protocol_restore8();
    if (*pbVar4 == 0) {
      uVar2 = *(ushort *)(param_1 + 4);
    }
    else {
      iVar3 = 0;
      if (*(int *)(pbVar4 + 4) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d phy list should not be NULL\n","cw_priv_port_info_assemble",
               0xfb);
        return 0xffffffff;
      }
      for (; iVar3 < (int)(uint)*pbVar4; iVar3 = iVar3 + 1) {
        iVar6 = iVar3 * 8;
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar4 + 4) + iVar6));
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar4 + 4) + iVar6 + 1));
        cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar4 + 4) + iVar6 + 4));
      }
      uVar2 = *(ushort *)(param_1 + 4);
    }
    uVar5 = 0xffffffff;
    if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d phy_num(%d) is too large\n","cw_priv_port_info_assemble",0xf1,
             (uint)*pbVar4);
    }
  }
  return uVar5;
}

