// func cw_priv_chnl_scan_report_parse @ 005ae290 size=484

undefined4 cw_priv_chnl_scan_report_parse(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte *__s;
  int iVar3;
  undefined1 uVar5;
  undefined4 uVar4;
  int iVar6;
  int iVar7;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (byte *)FUN_00408450(8,0x7d);
  if (__s == (byte *)0x0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_chnl_scan_report_parse",0x80);
    }
  }
  else {
    memset(__s,0,8);
    iVar3 = cw_protocol_retrieve8(param_1);
    *__s = (byte)iVar3;
    iVar7 = 0;
    iVar3 = FUN_00408450(iVar3 * 9,0x8e);
    *(int *)(__s + 4) = iVar3;
    if (iVar3 == 0) {
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    else {
      for (; iVar3 = iVar7 * 9, iVar7 < (int)(uint)*__s; iVar7 = iVar7 + 1) {
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 1) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 2) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 3) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 4) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 5) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 6) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 7) = uVar5;
        iVar6 = *(int *)(__s + 4);
        uVar5 = cw_protocol_retrieve8(param_1);
        *(undefined1 *)(iVar6 + iVar3 + 8) = uVar5;
      }
      uVar2 = *(ushort *)(param_2 + 0xe);
    }
    *(byte **)(param_2 + 0x10) = __s;
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)uVar2) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

