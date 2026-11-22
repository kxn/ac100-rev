// func cw_add_station_assemble @ 00570100 size=568

undefined4 cw_add_station_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  byte *pbVar7;
  
  pbVar7 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*pbVar7 < 0x20) {
    cw_protocol_restore8();
    if ((pbVar7[1] == 6) || (pbVar7[1] == 8)) {
      cw_protocol_restore8(param_1);
      if ((*(int *)(pbVar7 + 4) == 0) ||
         ((int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)) < (int)(uint)pbVar7[1])) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        pcVar4 = "[CW_ERROR]%32s():%4d failed to write mac address\n";
        uVar5 = 0xd9;
LAB_00570250:
        printf(pcVar4,"cw_add_station_assemble",uVar5);
        return 0xffffffff;
      }
      cw_protocol_restore_raw_bytes(param_1);
      uVar6 = (uint)*(ushort *)(pbVar7 + 8);
      if (uVar6 == (*(ushort *)(param_2 + 0xe) - 2) - (uint)pbVar7[1]) {
        if (uVar6 == 0) {
          uVar2 = *(ushort *)(param_1 + 4);
        }
        else {
          if ((0x200 < uVar6) || (*(int *)(pbVar7 + 0xc) == 0)) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar3 = is_target_debug_ap();
            if (iVar3 == 0) {
              return 0xffffffff;
            }
            pcVar4 = "[CW_ERROR]%32s():%4d failed to write vlan name\n";
            uVar5 = 0xe8;
            goto LAB_00570250;
          }
          cw_protocol_restore_raw_bytes(param_1);
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
      uVar6 = (uint)*(ushort *)(param_2 + 0xe);
      pcVar4 = "[CW_ERROR]%32s():%4d length of message eleemnt(%d) is wrong\n";
      uVar5 = 0xe1;
    }
    else {
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      uVar6 = (uint)pbVar7[1];
      pcVar4 = "[CW_ERROR]%32s():%4d length of mac address(%d) is wrong\n";
      uVar5 = 0xd1;
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
    uVar6 = (uint)*pbVar7;
    pcVar4 = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar5 = 0xc9;
  }
  printf(pcVar4,"cw_add_station_assemble",uVar5,uVar6);
  return 0xffffffff;
}

