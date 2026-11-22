// func cw_priv_special_frame_rate_ctrl_assemble @ 005bb4dc size=464

undefined4 cw_priv_special_frame_rate_ctrl_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if (*pbVar6 < 0x20) {
    cw_protocol_restore8();
    if (pbVar6[1] < 0x11) {
      cw_protocol_restore8(param_1);
      cw_protocol_restore8(param_1,pbVar6[2]);
      cw_protocol_restore8(param_1,pbVar6[3]);
      if (pbVar6[2] == 0) {
        uVar3 = *(ushort *)(param_1 + 4);
      }
      else {
        iVar4 = 0;
        if (*(int *)(pbVar6 + 4) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          printf("[CW_ERROR]%32s():%4d frame info is NULL\n",
                 "cw_priv_special_frame_rate_ctrl_assemble",0xc5);
          return 0xffffffff;
        }
        for (; iVar4 < (int)(uint)pbVar6[2]; iVar4 = iVar4 + 1) {
          cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(pbVar6 + 4) + iVar4 * 4));
          cw_protocol_restore16(param_1,*(undefined2 *)(*(int *)(pbVar6 + 4) + iVar4 * 4 + 2));
        }
        uVar3 = *(ushort *)(param_1 + 4);
      }
      if ((uint)uVar3 - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar1 = pbVar6[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar5 = 0xb9;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar1 = *pbVar6;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar5 = 0xb3;
  }
  printf(__format,"cw_priv_special_frame_rate_ctrl_assemble",uVar5,(uint)bVar1);
  return 0xffffffff;
}

