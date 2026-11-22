// func cw_sta_rssi_parse @ 00581888 size=504

undefined4 cw_sta_rssi_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *__s;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(0xc,0x7c);
  if (__s == (byte *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_sta_rssi_parse",0x7f);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar3 = cw_protocol_retrieve8(param_1);
  *__s = (byte)uVar3;
  if (uVar3 < 0x20) {
    iVar4 = cw_protocol_retrieve32(param_1);
    *(int *)(__s + 4) = iVar4;
    if (iVar4 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      uVar3 = 0;
      iVar4 = FUN_00408450(iVar4 * 7,0x8f);
      *(int *)(__s + 8) = iVar4;
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_sta_rssi_parse",0x92);
        }
        goto LAB_00581a08;
      }
      for (; uVar3 < *(uint *)(__s + 4); uVar3 = uVar3 + 1) {
        cw_protocol_retrieve_bytes(param_1,*(int *)(__s + 8) + uVar3 * 7,6);
        iVar4 = *(int *)(__s + 8);
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar4 + uVar3 * 7 + 6) = uVar6;
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(byte **)(param_2 + 0x10) = __s;
    uVar5 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar5 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d radio id(%d) is wrong\n","cw_sta_rssi_parse",0x88,(uint)*__s);
    }
LAB_00581a08:
    FUN_00407df0(__s);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

