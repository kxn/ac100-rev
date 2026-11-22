// func cw_priv_sta_auth_req_assemble @ 005c4c8c size=404

undefined4 cw_priv_sta_auth_req_assemble(int param_1,int param_2)

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
    if (pbVar6[1] < 0x11) {
      cw_protocol_restore8(param_1);
      cw_protocol_restore_raw_bytes(param_1,pbVar6 + 2,6);
      if (*(int *)(pbVar6 + 8) == *(ushort *)(param_2 + 0xe) - 0xc) {
        cw_protocol_restore32(param_1);
        if (*(uint *)(pbVar6 + 8) == 0) {
          uVar2 = *(ushort *)(param_1 + 4);
        }
        else {
          if (*(int *)(pbVar6 + 0xc) != 0) {
            cw_protocol_restore_raw_bytes
                      (param_1,*(int *)(pbVar6 + 0xc),*(uint *)(pbVar6 + 8) & 0xffff);
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
      uVar5 = *(uint *)(pbVar6 + 8);
      __format = "[CW_ERROR]%32s():%4d length of backfill(%d) is wrong\n";
      uVar4 = 0xcf;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      uVar5 = (uint)pbVar6[1];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar4 = 0xc4;
    }
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
    uVar4 = 0xbc;
  }
  printf(__format,"cw_priv_sta_auth_req_assemble",uVar4,uVar5);
  return 0xffffffff;
}

