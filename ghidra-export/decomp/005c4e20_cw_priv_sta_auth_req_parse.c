// func cw_priv_sta_auth_req_parse @ 005c4e20 size=552

undefined4 cw_priv_sta_auth_req_parse(int param_1,int param_2)

{
  ushort uVar1;
  byte *__s;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x10,0x74);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_auth_req_parse",0x77);
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  uVar2 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar2;
  if (uVar2 < 0x20) {
    uVar2 = cw_protocol_retrieve8(param_1);
    __s[1] = (byte)uVar2;
    if (uVar2 < 0x11) {
      cw_protocol_retrieve_bytes(param_1,__s + 2,6);
      uVar2 = cw_protocol_retrieve32(param_1);
      *(uint *)(__s + 8) = uVar2;
      if (uVar2 == *(ushort *)(param_2 + 0xe) - 0xc) {
        if (uVar2 != 0) {
          iVar3 = cw_protocol_retrieve_raw_bytes(param_1,uVar2 & 0xffff);
          *(int *)(__s + 0xc) = iVar3;
          if (iVar3 == 0) {
            if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[CW_ERROR]%32s():%4d failed to read backfill.\n","cw_priv_sta_auth_req_parse",
                     0xa0);
            }
            goto LAB_005c4f90;
          }
        }
        *(byte **)(param_2 + 0x10) = __s;
        if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
          return 0xffffffff;
        }
        return 0;
      }
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005c4f90;
      uVar2 = *(uint *)(__s + 8);
      __format = "[CW_ERROR]%32s():%4d length of backfill(%d) is wrong\n";
      uVar4 = 0x95;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005c4f90;
      uVar2 = (uint)__s[1];
      __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
      uVar4 = 0x89;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_005c4f90;
    uVar2 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar4 = 0x80;
  }
  printf(__format,"cw_priv_sta_auth_req_parse",uVar4,uVar2);
LAB_005c4f90:
  FUN_00407df0(__s);
  return 0xffffffff;
}

