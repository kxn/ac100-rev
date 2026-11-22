// func cw_80211_antenna_parse @ 005645a4 size=708

undefined4 cw_80211_antenna_parse(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  uVar2 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x67);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_80211_antenna_parse",0x6a);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    uVar3 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar3;
    if (uVar3 < 2) {
      iVar4 = cw_protocol_retrieve8(param_1);
      __s[2] = (byte)iVar4;
      if (iVar4 - 1U < 4) {
        iVar4 = cw_protocol_retrieve8(param_1);
        __s[3] = (byte)iVar4;
        if (iVar4 != 0) {
          if (*(ushort *)(param_2 + 0xe) - 4 == iVar4) {
            iVar4 = cw_protocol_retrieve_raw_bytes(param_1);
            *(int *)(__s + 4) = iVar4;
            if (iVar4 != 0) {
              *(byte **)(param_2 + 0x10) = __s;
              if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe))
              {
                return 0xffffffff;
              }
              return 0;
            }
            if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[CW_ERROR]%32s():%4d failed to read selection\n","cw_80211_antenna_parse",0x95
                    );
            }
            goto LAB_005646f4;
          }
          if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
          goto LAB_005646f4;
          uVar3 = (uint)*(ushort *)(param_2 + 0xe);
          bVar1 = __s[3];
          pcVar5 = 
          "[CW_ERROR]%32s():%4d count(%d) doesn\'t match capwap message element length(%d)\n";
          uVar6 = 0x8e;
          goto LAB_0056473c;
        }
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_005646f4;
        uVar3 = (uint)__s[3];
        pcVar5 = "[CW_ERROR]%32s():%4d count(%d) is Wrong\n";
        uVar6 = 0x88;
      }
      else {
        if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
        goto LAB_005646f4;
        uVar3 = (uint)__s[2];
        pcVar5 = "[CW_ERROR]%32s():%4d combiner(%d) is wrong\n";
        uVar6 = 0x81;
      }
    }
    else {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005646f4;
      uVar3 = (uint)__s[1];
      pcVar5 = "[CW_ERROR]%32s():%4d Diversity(%d) is wrong\n";
      uVar6 = 0x7a;
    }
    printf(pcVar5,"cw_80211_antenna_parse",uVar6,uVar3);
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005646f4;
    bVar1 = *__s;
    uVar3 = 0;
    pcVar5 = "[CW_ERROR]%32s():%4d Radio ID(%d) isn\'t between %d and %d\n";
    uVar6 = 0x73;
LAB_0056473c:
    printf(pcVar5,"cw_80211_antenna_parse",uVar6,(uint)bVar1,uVar3);
  }
LAB_005646f4:
  FUN_00407df0(__s);
  return 0xffffffff;
}

