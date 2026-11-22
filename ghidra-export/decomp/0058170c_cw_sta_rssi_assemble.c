// func cw_sta_rssi_assemble @ 0058170c size=380

undefined4 cw_sta_rssi_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  uint uVar6;
  
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar4 < 0x20) {
    cw_protocol_restore8();
    cw_protocol_restore32(param_1,*(undefined4 *)(pbVar4 + 4));
    if (*(int *)(pbVar4 + 4) == 0) {
      uVar2 = *(ushort *)(param_1 + 4);
    }
    else {
      uVar6 = 0;
      if (*(int *)(pbVar4 + 8) == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        printf("[CW_ERROR]%32s():%4d rssi list is null\n","cw_sta_rssi_assemble",0xbd);
        return 0xffffffff;
      }
      for (; uVar6 < *(uint *)(pbVar4 + 4); uVar6 = uVar6 + 1) {
        cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar4 + 8) + uVar6 * 7,6);
        cw_protocol_restore8(param_1,*(undefined1 *)(*(int *)(pbVar4 + 8) + uVar6 * 7 + 6));
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
      printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_sta_rssi_assemble",0xb4,
             (uint)*pbVar4);
    }
  }
  return uVar5;
}

