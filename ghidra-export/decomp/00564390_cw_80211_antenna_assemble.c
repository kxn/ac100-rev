// func cw_80211_antenna_assemble @ 00564390 size=532

undefined4 cw_80211_antenna_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar5 < 0x20) {
    cw_protocol_restore8();
    if (pbVar5[1] < 2) {
      cw_protocol_restore8(param_1);
      if (pbVar5[2] - 1 < 4) {
        cw_protocol_restore8(param_1);
        if ((pbVar5[3] != 0) && (*(ushort *)(param_2 + 0xe) - 4 == (uint)pbVar5[3])) {
          cw_protocol_restore8(param_1);
          if (*(int *)(pbVar5 + 4) != 0) {
            cw_protocol_restore_raw_bytes(param_1,*(int *)(pbVar5 + 4),pbVar5[3]);
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
          printf("[CW_ERROR]%32s():%4d selection is null\n","cw_80211_antenna_assemble",0xd3);
          return 0xffffffff;
        }
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        uVar4 = (uint)pbVar5[3];
        __format = "[CW_ERROR]%32s():%4d count(%d) is wrong\n";
        uVar3 = 0xcb;
      }
      else {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        uVar4 = (uint)pbVar5[2];
        __format = "[CW_ERROR]%32s():%4d combiner(%d) is wrong\n";
        uVar3 = 0xc3;
      }
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)pbVar5[1];
      __format = "[CW_ERROR]%32s():%4d diversity(%d) is wrong\n";
      uVar3 = 0xbb;
    }
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    uVar4 = (uint)*pbVar5;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is Wrong\n";
    uVar3 = 0xb3;
  }
  printf(__format,"cw_80211_antenna_assemble",uVar3,uVar4);
  return 0xffffffff;
}

