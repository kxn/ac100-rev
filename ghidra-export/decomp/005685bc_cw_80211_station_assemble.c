// func cw_80211_station_assemble @ 005685bc size=500

undefined4 cw_80211_station_assemble(int param_1,int param_2)

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
    cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 2));
    if (pbVar5[4] == 0) {
      cw_protocol_restore8(param_1,0);
      cw_protocol_restore_raw_bytes(param_1,pbVar5 + 5,6);
      cw_protocol_restore16(param_1,*(undefined2 *)(pbVar5 + 0xc));
      if (pbVar5[0xe] < 0x11) {
        cw_protocol_restore8(param_1);
        if (((pbVar5[0xf] != 0) && (*(int *)(pbVar5 + 0x10) != 0)) &&
           (*(ushort *)(param_2 + 0xe) - 0xd == (uint)pbVar5[0xf])) {
          cw_protocol_restore_raw_bytes(param_1);
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
        printf("[CW_ERROR]%32s():%4d failed to write supported rates\n","cw_80211_station_assemble",
               0xd4);
        return 0xffffffff;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)pbVar5[0xe];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar3 = 0xcc;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = (uint)pbVar5[4];
      __format = "[CW_ERROR]%32s():%4d flags(%d) isn\'t zeroed\n";
      uVar3 = 0xc0;
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
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0xb5;
  }
  printf(__format,"cw_80211_station_assemble",uVar3,uVar4);
  return 0xffffffff;
}

