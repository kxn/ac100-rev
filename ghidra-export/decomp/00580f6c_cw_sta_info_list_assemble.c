// func cw_sta_info_list_assemble @ 00580f6c size=476

undefined4 cw_sta_info_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar6 < 0x20) {
    cw_protocol_restore8();
    if (*(uint *)(pbVar6 + 4) < 0x11) {
      cw_protocol_restore32(param_1);
      cw_protocol_restore32(param_1,*(undefined4 *)(pbVar6 + 8));
      if (*(int *)(pbVar6 + 8) == 0) {
        uVar2 = *(ushort *)(param_1 + 4);
      }
      else {
        uVar5 = 0;
        if (*(int *)(pbVar6 + 0xc) == 0) {
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            return 0xffffffff;
          }
          printf("[CW_ERROR]%32s():%4d info list is null\n","cw_sta_info_list_assemble",0xd1);
          return 0xffffffff;
        }
        for (; uVar5 < *(uint *)(pbVar6 + 8); uVar5 = uVar5 + 1) {
          iVar3 = uVar5 * 0x10;
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar6 + 0xc) + iVar3));
          cw_protocol_restore32(param_1,*(undefined4 *)(*(int *)(pbVar6 + 0xc) + iVar3 + 4));
          cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar6 + 0xc) + iVar3 + 8,6);
        }
        uVar2 = *(ushort *)(param_1 + 4);
      }
      if ((uint)uVar2 - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar5 = *(uint *)(pbVar6 + 4);
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar4 = 200;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar5 = (uint)*pbVar6;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0xc2;
  }
  printf(__format,"cw_sta_info_list_assemble",uVar4,uVar5);
  return 0xffffffff;
}

