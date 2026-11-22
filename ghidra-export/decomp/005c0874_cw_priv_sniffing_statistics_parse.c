// func cw_priv_sniffing_statistics_parse @ 005c0874 size=600

undefined4 cw_priv_sniffing_statistics_parse(int param_1,int param_2)

{
  ushort uVar1;
  int *__s;
  int iVar2;
  void *__s_00;
  undefined1 uVar4;
  undefined4 uVar3;
  int iVar5;
  int iVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (int *)FUN_00408450(8,0x8f);
  if (__s == (int *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sniffing_statistics_parse",0x92);
    return 0xffffffff;
  }
  memset(__s,0,8);
  iVar2 = cw_protocol_retrieve32(param_1);
  *__s = iVar2;
  if (iVar2 < 0x1f5) {
    if (0 < iVar2) {
      __s_00 = (void *)FUN_00408450(iVar2 * 0x14,0xa2);
      __s[1] = (int)__s_00;
      if (__s_00 == (void *)0x0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_sniffing_statistics_parse",0xa5);
        }
        goto LAB_005c0a50;
      }
      memset(__s_00,0,*__s * 0x14);
      iVar2 = *__s;
      for (iVar6 = 0; iVar5 = iVar6 * 0x14, iVar6 < iVar2; iVar6 = iVar6 + 1) {
        iVar2 = __s[1];
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar2 + iVar5) = uVar4;
        iVar2 = __s[1];
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar2 + iVar5 + 1) = uVar4;
        cw_protocol_retrieve_bytes(param_1,__s[1] + iVar5 + 2,6);
        iVar2 = __s[1];
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar2 + iVar5 + 8) = uVar4;
        iVar2 = __s[1];
        uVar3 = cw_protocol_retrieve32(param_1);
        *(undefined4 *)(iVar2 + iVar5 + 0xc) = uVar3;
        iVar2 = __s[1];
        uVar4 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar2 + iVar5 + 0x10) = uVar4;
        iVar2 = *__s;
      }
    }
    *(int **)(param_2 + 0x10) = __s;
    uVar3 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar3 = 0;
    }
  }
  else {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n","cw_priv_sniffing_statistics_parse",
             0x9b,*__s);
    }
LAB_005c0a50:
    FUN_00407df0(__s);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

