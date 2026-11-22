// func cw_80211_add_wlan_assemble @ 00563590 size=1164

undefined4 cw_80211_add_wlan_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 uVar8;
  
  pbVar7 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (0x1f < *pbVar7) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar6 = (uint)*pbVar7;
    uVar8 = 0x1f;
    pcVar4 = "[CW_ERROR]%32s():%4d Radio ID(%d) isn\'t between %d and %d\n";
    uVar5 = 0x120;
    goto LAB_0056365c;
  }
  cw_protocol_restore8();
  if (0x10 < pbVar7[1]) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar6 = (uint)pbVar7[1];
    pcVar4 = "[CW_ERROR]%32s():%4d Wlan ID(%d) isn\'t between %d and %d\n";
    uVar8 = 0x10;
    uVar5 = 0x128;
    goto LAB_0056365c;
  }
  cw_protocol_restore8(param_1);
  cw_protocol_restore16(param_1,*(undefined2 *)(pbVar7 + 2));
  cw_protocol_restore8(param_1,pbVar7[4]);
  if (3 < pbVar7[5]) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    uVar6 = (uint)pbVar7[5];
    uVar8 = 3;
    pcVar4 = "[CW_ERROR]%32s():%4d Key Status(%d) isn\'t between %d and %d\n";
    uVar5 = 0x135;
    goto LAB_0056365c;
  }
  cw_protocol_restore8(param_1);
  if (*(ushort *)(pbVar7 + 6) == 0) {
    if (*(int *)(pbVar7 + 8) == 0) {
      cw_protocol_restore16(param_1);
      uVar2 = *(ushort *)(param_1 + 4);
LAB_005637a4:
      if (10 < (int)(*(int *)(param_1 + 8) - (uint)uVar2)) {
        cw_protocol_restore_raw_bytes(param_1,pbVar7 + 0xc,6);
        if (pbVar7[0x12] < 4) {
          cw_protocol_restore8(param_1);
          if (pbVar7[0x13] < 2) {
            cw_protocol_restore8(param_1);
            if (pbVar7[0x14] < 2) {
              cw_protocol_restore8(param_1);
              if (pbVar7[0x15] < 3) {
                cw_protocol_restore8(param_1);
                cw_protocol_restore8(param_1,pbVar7[0x16]);
                if (((*(ushort *)(pbVar7 + 0x18) - 1 < 0x20) && (*(int *)(pbVar7 + 0x1c) != 0)) &&
                   ((int)(uint)*(ushort *)(pbVar7 + 0x18) <=
                    (int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)))) {
                  cw_protocol_restore_raw_bytes(param_1);
                  if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 !=
                      (uint)*(ushort *)(param_2 + 0xe)) {
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
                pcVar4 = 
                "[CW_ERROR]%32s():%4d length of ssid is wrong Or packet buffer isn\'t enough\n";
                uVar5 = 0x176;
                goto LAB_00563754;
              }
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              uVar6 = (uint)pbVar7[0x15];
              uVar8 = 2;
              pcVar4 = "[CW_ERROR]%32s():%4d Tunnel Mode(%d) isn\'t between %d and %d\n";
              uVar5 = 0x16b;
            }
            else {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                return 0xffffffff;
              }
              uVar6 = (uint)pbVar7[0x14];
              uVar8 = 1;
              pcVar4 = "[CW_ERROR]%32s():%4d MAC Mode(%d) isn\'t Local(%d) or Split(%d)\n";
              uVar5 = 0x164;
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
            uVar6 = (uint)pbVar7[0x13];
            uVar8 = 1;
            pcVar4 = "[CW_ERROR]%32s():%4d Auth Type(%d) isn\'t OPEN(%d) or WEP(%d)\n";
            uVar5 = 0x15d;
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
          uVar6 = (uint)pbVar7[0x12];
          uVar8 = 3;
          pcVar4 = "[CW_ERROR]%32s():%4d Qos(%d) isn\'t between %d and %d\n";
          uVar5 = 0x156;
        }
LAB_0056365c:
        printf(pcVar4,"cw_80211_add_wlan_assemble",uVar5,uVar6,0,uVar8);
        return 0xffffffff;
      }
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      pcVar4 = "[CW_ERROR]%32s():%4d packet buffer isn\'t enough\n";
      uVar5 = 0x14c;
      goto LAB_00563754;
    }
  }
  else if ((*(int *)(pbVar7 + 8) != 0) &&
          ((int)(*(ushort *)(pbVar7 + 6) + 2) <=
           (int)(*(int *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 4)))) {
    cw_protocol_restore16(param_1);
    cw_protocol_restore_raw_bytes(param_1,*(undefined4 *)(pbVar7 + 8),*(undefined2 *)(pbVar7 + 6));
    uVar2 = *(ushort *)(param_1 + 4);
    goto LAB_005637a4;
  }
  if (capwap_err_switch == 0) {
    return 0xffffffff;
  }
  iVar3 = is_target_debug_ap();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  pcVar4 = "[CW_ERROR]%32s():%4d length of key or key is wrong\n";
  uVar5 = 0x145;
LAB_00563754:
  printf(pcVar4,"cw_80211_add_wlan_assemble",uVar5);
  return 0xffffffff;
}

