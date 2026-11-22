// func cw_priv_sta_list_assemble @ 005c6a74 size=436

undefined4 cw_priv_sta_list_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  byte *pbVar6;
  uint uVar7;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  if (*pbVar6 < 0x20) {
    cw_protocol_restore8();
    if (pbVar6[1] < 0x11) {
      cw_protocol_restore8(param_1);
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar6 + 4));
      if (*(int *)(pbVar6 + 4) == 0) {
        uVar3 = *(ushort *)(param_1 + 4);
      }
      else {
        uVar7 = 0;
        if (*(int *)(pbVar6 + 8) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          printf("[CW_ERROR]%32s():%4d sta mac list is NULL\n","cw_priv_sta_list_assemble",0xc3);
          return 0xffffffff;
        }
        for (; uVar7 < *(uint *)(pbVar6 + 4); uVar7 = uVar7 + 1) {
          cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar6 + 8) + uVar7 * 6,6);
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
    uVar5 = 0xb8;
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
    uVar5 = 0xb2;
  }
  printf(__format,"cw_priv_sta_list_assemble",uVar5,(uint)bVar1);
  return 0xffffffff;
}

