// func cw_sta_info_list_parse @ 00581148 size=600

undefined4 cw_sta_info_list_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *__format;
  int iVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0x10,0x82);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_sta_info_list_parse",0x85);
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    uVar3 = cw_protocol_retrieve32(param_1);
    *(uint *)(__s + 4) = uVar3;
    if (uVar3 < 0x11) {
      iVar4 = cw_protocol_retrieve32(param_1);
      *(int *)(__s + 8) = iVar4;
      if (iVar4 == 0) {
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      else {
        uVar3 = 0;
        iVar4 = FUN_00408450(iVar4 << 4,0x9c);
        *(int *)(__s + 0xc) = iVar4;
        if (iVar4 == 0) {
          if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
            printf("[CW_ERROR]%32s():%4d out of memory\n","cw_sta_info_list_parse",0x9f);
          }
          goto LAB_005812f0;
        }
        for (; uVar3 < *(uint *)(__s + 8); uVar3 = uVar3 + 1) {
          iVar4 = *(int *)(__s + 0xc);
          iVar6 = uVar3 * 0x10;
          uVar5 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar4 + iVar6) = uVar5;
          iVar4 = *(int *)(__s + 0xc);
          uVar5 = cw_protocol_retrieve32(param_1);
          *(undefined4 *)(iVar4 + iVar6 + 4) = uVar5;
          cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 0xc) + iVar6 + 8,6);
        }
        uVar2 = *(ushort *)(param_2 + 0xe);
      }
      *(byte **)(param_2 + 0x10) = __s;
      if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)uVar2) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005812f0;
    uVar3 = *(uint *)(__s + 4);
    __format = "[CW_ERROR]%32s():%4d wlan id(%d) is wrong\n";
    uVar5 = 0x95;
  }
  else {
    if ((capwap_err_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_005812f0;
    uVar3 = (uint)*__s;
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar5 = 0x8e;
  }
  printf(__format,"cw_sta_info_list_parse",uVar5,uVar3);
LAB_005812f0:
  FUN_00407df0(__s);
  return 0xffffffff;
}

