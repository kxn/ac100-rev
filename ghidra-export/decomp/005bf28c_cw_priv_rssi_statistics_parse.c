// func cw_priv_rssi_statistics_parse @ 005bf28c size=528

undefined4 cw_priv_rssi_statistics_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  void *__s;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (void *)FUN_00408450(0x18,0x94);
  if (__s == (void *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_rssi_statistics_parse",0x97);
    return 0xffffffff;
  }
  memset(__s,0,0x18);
  cw_protocol_retrieve_bytes(param_1,__s,8);
  cw_protocol_retrieve_bytes(param_1,(int)__s + 8,8);
  uVar3 = cw_protocol_retrieve32(param_1);
  *(uint *)((int)__s + 0x10) = uVar3;
  if (uVar3 < 0x191) {
    if (uVar3 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      uVar6 = 0;
      iVar4 = FUN_00408450(uVar3 * 0xe,0xaa);
      *(int *)((int)__s + 0x14) = iVar4;
      if (iVar4 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_rssi_statistics_parse",0xad);
        }
        goto LAB_005bf424;
      }
      for (; uVar6 < *(uint *)((int)__s + 0x10); uVar6 = uVar6 + 1) {
        cw_protocol_retrieve_bytes(param_1,*(int *)((int)__s + 0x14) + uVar6 * 0xe,6);
        cw_protocol_retrieve_bytes(param_1,*(int *)((int)__s + 0x14) + uVar6 * 0xe + 6,8);
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(void **)(param_2 + 0x10) = __s;
    uVar5 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar5 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d Sta count is out of range[%u]\n","cw_priv_rssi_statistics_parse",
             0xa3,*(undefined4 *)((int)__s + 0x10));
    }
LAB_005bf424:
    FUN_00407df0(__s);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

