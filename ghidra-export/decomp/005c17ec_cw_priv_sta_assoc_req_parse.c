// func cw_priv_sta_assoc_req_parse @ 005c17ec size=500

undefined4 cw_priv_sta_assoc_req_parse(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  __s = (byte *)FUN_00408450(0x14,0x80);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_assoc_req_parse",0x83);
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
      if ((**(uint **)(param_2 + 0x14) & 0x40) == 0) {
LAB_005c1880:
        __s[8] = 0;
        __s[9] = 0;
        __s[10] = 0;
        __s[0xb] = 1;
      }
      else {
        iVar3 = cw_protocol_retrieve32(param_1);
        *(int *)(__s + 8) = iVar3;
        if (-1 < iVar3) goto LAB_005c1880;
      }
      uVar2 = cw_protocol_retrieve32(param_1);
      *(uint *)(__s + 0xc) = uVar2;
      if (uVar2 == 0) {
LAB_005c1898:
        *(byte **)(param_2 + 0x10) = __s;
        return 0;
      }
      iVar3 = cw_protocol_retrieve_raw_bytes(param_1,uVar2 & 0xffff);
      *(int *)(__s + 0x10) = iVar3;
      if (iVar3 != 0) goto LAB_005c1898;
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to read backfill.\n","cw_priv_sta_assoc_req_parse",0xc2)
        ;
      }
      goto LAB_005c1944;
    }
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005c1944;
    bVar1 = __s[1];
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar4 = 0x95;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005c1944;
    bVar1 = *__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x8c;
  }
  printf(__format,"cw_priv_sta_assoc_req_parse",uVar4,(uint)bVar1);
LAB_005c1944:
  FUN_00407df0(__s);
  return 0xffffffff;
}

