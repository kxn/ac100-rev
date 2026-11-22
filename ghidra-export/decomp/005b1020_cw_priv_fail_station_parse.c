// func cw_priv_fail_station_parse @ 005b1020 size=604

undefined4 cw_priv_fail_station_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint *__s;
  uint uVar3;
  undefined4 uVar4;
  void *__s_00;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (uint *)FUN_00408450(8,0x8b);
  if (__s == (uint *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_fail_station_parse",0x8e);
    return 0xffffffff;
  }
  memset(__s,0,8);
  uVar3 = cw_protocol_retrieve32(param_1);
  *__s = uVar3;
  if (uVar3 < 0xc9) {
    if (uVar3 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      __s_00 = (void *)FUN_00408450(uVar3 * 0x14,0xa0);
      __s[1] = (uint)__s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_fail_station_parse",0xa3);
        }
        goto LAB_005b1200;
      }
      memset(__s_00,0,*__s * 0x14);
      uVar3 = *__s;
      for (uVar7 = 0; iVar6 = uVar7 * 0x14, uVar7 < uVar3; uVar7 = uVar7 + 1) {
        cw_protocol_retrieve_bytes(param_1,__s[1] + iVar6,6);
        uVar3 = __s[1];
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar6 + 6) = uVar5;
        uVar3 = __s[1];
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar6 + 7) = uVar5;
        uVar3 = __s[1];
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar6 + 8) = uVar5;
        uVar3 = __s[1];
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(uVar3 + iVar6 + 0xc) = uVar4;
        uVar3 = __s[1];
        uVar4 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(uVar3 + iVar6 + 0x10) = uVar4;
        uVar3 = *__s;
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(uint **)(param_2 + 0x10) = __s;
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar4 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_fail_station_parse",0x98,
             *__s);
    }
LAB_005b1200:
    FUN_00407df0(__s);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

