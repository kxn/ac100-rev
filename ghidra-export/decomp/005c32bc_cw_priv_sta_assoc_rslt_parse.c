// func cw_priv_sta_assoc_rslt_parse @ 005c32bc size=564

undefined4 cw_priv_sta_assoc_rslt_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  char *__format;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x14,0x76);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_assoc_rslt_parse",0x79);
    return 0xffffffff;
  }
  memset(__s,0,0x14);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if (uVar2 < 0x11) {
      cw_protocol_retrieve_bytes(param_1,__s + 2,6);
      uVar3 = cw_protocol_retrieve32(param_1);
      *(undefined4 *)(__s + 8) = uVar3;
      uVar2 = cw_protocol_retrieve32(param_1);
      *(uint *)(__s + 0xc) = uVar2;
      if (uVar2 == *(ushort *)(param_2 + 0xe) - 0x10) {
        if (uVar2 != 0) {
          iVar4 = cw_protocol_retrieve_raw_bytes(param_1,uVar2 & 0xffff);
          *(int *)(__s + 0x10) = iVar4;
          if (iVar4 == 0) {
            if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("[CW_ERROR]%32s():%4d failed to read backfill.\n",
                     "cw_priv_sta_assoc_rslt_parse",0xa5);
            }
            goto LAB_005c3438;
          }
        }
        *(byte **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005c3438;
      uVar2 = *(uint *)(__s + 0xc);
      __format = "[CW_ERROR]%32s():%4d length of backfill(%d) is wrong\n";
      uVar3 = 0x9a;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005c3438;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar3 = 0x8b;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005c3438;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar3 = 0x82;
  }
  printf(__format,"cw_priv_sta_assoc_rslt_parse",uVar3,uVar2);
LAB_005c3438:
  FUN_00407df0(__s);
  return 0xffffffff;
}

