// func cw_priv_sta_statistics_parse @ 005c7c9c size=780

undefined4 cw_priv_sta_statistics_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint *__s;
  uint uVar3;
  undefined1 uVar6;
  undefined2 uVar5;
  int iVar4;
  undefined4 uVar7;
  uint uVar8;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (uint *)FUN_00408450(8,0x94);
  if (__s == (uint *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_statistics_parse",0x97);
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
      uVar8 = 0;
      uVar3 = FUN_00408450(uVar3 * 0x28,0xa7);
      __s[1] = uVar3;
      if (uVar3 == 0) {
        if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sta_statistics_parse",0xaa);
        }
        goto LAB_005c7f30;
      }
      for (; iVar4 = uVar8 * 0x28, uVar8 < *__s; uVar8 = uVar8 + 1) {
        cw_protocol_retrieve_bytes(param_1,__s[1] + iVar4,6);
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 6) = uVar6;
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 7) = uVar6;
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 8) = uVar6;
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 9) = uVar6;
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 10) = uVar6;
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 0xb) = uVar6;
        uVar3 = __s[1];
        uVar5 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(uVar3 + iVar4 + 0xc) = uVar5;
        uVar3 = __s[1];
        uVar7 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(uVar3 + iVar4 + 0x10) = uVar7;
        uVar3 = __s[1];
        uVar5 = cw_protocol_retrieve16(param_1);
        *(undefined2 *)(uVar3 + iVar4 + 0x14) = uVar5;
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 0x16) = uVar6;
        uVar3 = __s[1];
        uVar6 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(uVar3 + iVar4 + 0x17) = uVar6;
        uVar3 = __s[1];
        uVar7 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(uVar3 + iVar4 + 0x18) = uVar7;
        uVar3 = __s[1];
        uVar7 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(uVar3 + iVar4 + 0x1c) = uVar7;
        uVar3 = __s[1];
        uVar7 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(uVar3 + iVar4 + 0x20) = uVar7;
        uVar3 = __s[1];
        uVar7 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(uVar3 + iVar4 + 0x24) = uVar7;
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(uint **)(param_2 + 0x10) = __s;
    uVar7 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar7 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d Sta count is out of range[%u]\n","cw_priv_sta_statistics_parse",
             0xa0,*__s);
    }
LAB_005c7f30:
    FUN_00407df0(__s);
    uVar7 = 0xffffffff;
  }
  return uVar7;
}

