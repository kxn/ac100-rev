// func cw_80211_add_wlan_parse @ 00563a1c size=1408

undefined4 cw_80211_add_wlan_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined2 uVar4;
  byte bVar5;
  int iVar3;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x20,0x91);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_add_wlan_parse",0x94);
    return 0xffffffff;
  }
  memset(__s,0,0x20);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if (uVar2 < 0x11) {
      uVar4 = cw_protocol_retrieve16(param_1);
      *(undefined2 *)(__s + 2) = uVar4;
      bVar5 = cw_protocol_retrieve8(param_1);
      __s[4] = bVar5;
      uVar2 = cw_protocol_retrieve8(param_1);
      __s[5] = (byte)uVar2;
      if (uVar2 < 4) {
        iVar3 = cw_protocol_retrieve16(param_1);
        *(short *)(__s + 6) = (short)iVar3;
        if (iVar3 == 0) {
LAB_00563ad8:
          if (10 < (int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6))) {
            cw_protocol_retrieve_bytes(param_1,__s + 0xc,6);
            uVar2 = cw_protocol_retrieve8(param_1);
            __s[0x12] = (byte)uVar2;
            if (uVar2 < 4) {
              uVar2 = cw_protocol_retrieve8(param_1);
              __s[0x13] = (byte)uVar2;
              if (uVar2 < 2) {
                uVar2 = cw_protocol_retrieve8(param_1);
                __s[0x14] = (byte)uVar2;
                if (uVar2 < 2) {
                  uVar2 = cw_protocol_retrieve8(param_1);
                  __s[0x15] = (byte)uVar2;
                  if (uVar2 < 3) {
                    bVar5 = cw_protocol_retrieve8(param_1);
                    __s[0x16] = bVar5;
                    iVar3 = (uint)*(ushort *)(param_2 + 0xe) - (uint)*(ushort *)(__s + 6);
                    iVar8 = iVar3 + -0x13;
                    if ((0x1f < iVar3 - 0x14U) ||
                       ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) <
                        iVar8)) {
                      if (capwap_err_switch == 0) {
                        iVar3 = *(int *)(__s + 8);
                      }
                      else {
                        iVar3 = is_target_debug_ap();
                        if (iVar3 == 0) {
                          iVar3 = *(int *)(__s + 8);
                        }
                        else {
                          printf("[CW_ERROR]%32s():%4d length of ssid(%d) is wrong\n",
                                 "cw_80211_add_wlan_parse",0xf6,iVar8);
                          iVar3 = *(int *)(__s + 8);
                        }
                      }
                      goto LAB_00563cc0;
                    }
                    *(short *)(__s + 0x18) = (short)iVar8;
                    iVar3 = cw_protocol_retrieve_str(param_1);
                    *(int *)(__s + 0x1c) = iVar3;
                    if (iVar3 != 0) {
                      *(byte **)(param_2 + 0x10) = __s;
                      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 !=
                          (uint)*(ushort *)(param_2 + 0xe)) {
                        return 0xffffffff;
                      }
                      return 0;
                    }
                    if (capwap_err_switch == 0) {
                      iVar3 = *(int *)(__s + 8);
                      goto LAB_00563cc0;
                    }
                    iVar3 = is_target_debug_ap();
                    if (iVar3 == 0) {
                      iVar3 = *(int *)(__s + 8);
                      goto LAB_00563cc0;
                    }
                    pcVar6 = "[CW_ERROR]%32s():%4d failed to read ssid\n";
                    uVar7 = 0xfd;
                    goto LAB_00563c60;
                  }
                  if (capwap_err_switch == 0) {
                    iVar3 = *(int *)(__s + 8);
                    goto LAB_00563cc0;
                  }
                  iVar3 = is_target_debug_ap();
                  if (iVar3 == 0) {
                    iVar3 = *(int *)(__s + 8);
                    goto LAB_00563cc0;
                  }
                  uVar2 = (uint)__s[0x15];
                  uVar9 = 2;
                  pcVar6 = "[CW_ERROR]%32s():%4d Tunnel Mode(%d) isn\'t between %d and %d\n";
                  uVar7 = 0xeb;
                }
                else {
                  if (capwap_err_switch == 0) {
                    iVar3 = *(int *)(__s + 8);
                    goto LAB_00563cc0;
                  }
                  iVar3 = is_target_debug_ap();
                  if (iVar3 == 0) {
                    iVar3 = *(int *)(__s + 8);
                    goto LAB_00563cc0;
                  }
                  uVar2 = (uint)__s[0x14];
                  pcVar6 = "[CW_ERROR]%32s():%4d MAC Mode(%d) isn\'t Local(%d) or Split(%d)\n";
                  uVar9 = 1;
                  uVar7 = 0xe4;
                }
              }
              else {
                if (capwap_err_switch == 0) {
                  iVar3 = *(int *)(__s + 8);
                  goto LAB_00563cc0;
                }
                iVar3 = is_target_debug_ap();
                if (iVar3 == 0) {
                  iVar3 = *(int *)(__s + 8);
                  goto LAB_00563cc0;
                }
                uVar2 = (uint)__s[0x13];
                uVar9 = 1;
                pcVar6 = "[CW_ERROR]%32s():%4d Auth Type(%d) isn\'t OPEN(%d) or WEP(%d)\n";
                uVar7 = 0xdd;
              }
            }
            else {
              if (capwap_err_switch == 0) {
                iVar3 = *(int *)(__s + 8);
                goto LAB_00563cc0;
              }
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                iVar3 = *(int *)(__s + 8);
                goto LAB_00563cc0;
              }
              uVar2 = (uint)__s[0x12];
              uVar9 = 3;
              pcVar6 = "[CW_ERROR]%32s():%4d Qos(%d) isn\'t between %d and %d\n";
              uVar7 = 0xd6;
            }
            goto LAB_00563d20;
          }
          if (capwap_err_switch == 0) {
            iVar3 = *(int *)(__s + 8);
            goto LAB_00563cc0;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            iVar3 = *(int *)(__s + 8);
            goto LAB_00563cc0;
          }
          pcVar6 = "[CW_ERROR]%32s():%4d packet buffer isn\'t enough\n";
          uVar7 = 0xcb;
        }
        else if ((int)((uint)*(ushort *)(param_1 + 4) - (uint)*(ushort *)(param_1 + 6)) < iVar3) {
          if (capwap_err_switch == 0) {
            iVar3 = *(int *)(__s + 8);
            goto LAB_00563cc0;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            iVar3 = *(int *)(__s + 8);
            goto LAB_00563cc0;
          }
          pcVar6 = "[CW_ERROR]%32s():%4d packet buffer isn\'t enough\n";
          uVar7 = 0xbc;
        }
        else {
          iVar3 = cw_protocol_retrieve_str(param_1,iVar3);
          *(int *)(__s + 8) = iVar3;
          if (iVar3 != 0) goto LAB_00563ad8;
          if (capwap_err_switch == 0) {
            iVar3 = *(int *)(__s + 8);
            goto LAB_00563cc0;
          }
          iVar3 = is_target_debug_ap();
          if (iVar3 == 0) {
            iVar3 = *(int *)(__s + 8);
            goto LAB_00563cc0;
          }
          pcVar6 = "[CW_ERROR]%32s():%4d failed to read Key\n";
          uVar7 = 0xc3;
        }
LAB_00563c60:
        printf(pcVar6,"cw_80211_add_wlan_parse",uVar7);
        iVar3 = *(int *)(__s + 8);
        goto LAB_00563cc0;
      }
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(__s + 8);
        goto LAB_00563cc0;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        iVar3 = *(int *)(__s + 8);
        goto LAB_00563cc0;
      }
      uVar2 = (uint)__s[5];
      uVar9 = 3;
      pcVar6 = "[CW_ERROR]%32s():%4d Key Status(%d) isn\'t between %d and %d\n";
      uVar7 = 0xb2;
    }
    else {
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(__s + 8);
        goto LAB_00563cc0;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        iVar3 = *(int *)(__s + 8);
        goto LAB_00563cc0;
      }
      uVar2 = (uint)__s[1];
      uVar9 = 0x10;
      pcVar6 = "[CW_ERROR]%32s():%4d Wlan ID(%d) isn\'t between %d and %d\n";
      uVar7 = 0xa5;
    }
  }
  else {
    if (capwap_err_switch == 0) {
      iVar3 = *(int *)(__s + 8);
      goto LAB_00563cc0;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      iVar3 = *(int *)(__s + 8);
      goto LAB_00563cc0;
    }
    uVar2 = (uint)*__s;
    uVar9 = 0x1f;
    pcVar6 = "[CW_ERROR]%32s():%4d Radio ID(%d) isn\'t between %d and %d\n";
    uVar7 = 0x9d;
  }
LAB_00563d20:
  printf(pcVar6,"cw_80211_add_wlan_parse",uVar7,uVar2,0,uVar9);
  iVar3 = *(int *)(__s + 8);
LAB_00563cc0:
  if (iVar3 != 0) {
    FUN_00407df0();
  }
  FUN_00407df0(__s);
  return 0xffffffff;
}

