// func cw_priv_sniffing_statistics_assemble @ 005c06a8 size=460

undefined4 cw_priv_sniffing_statistics_assemble(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  piVar4 = *(int **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*piVar4 < 0x1f5) {
    if ((*piVar4 < 1) || (piVar4[1] != 0)) {
      cw_protocol_restore32(param_1);
      iVar7 = 0;
      iVar3 = *piVar4;
      if (iVar3 < 1) {
        uVar2 = *(ushort *)(param_1 + 4);
      }
      else {
        for (; iVar6 = iVar7 * 0x14, iVar7 < iVar3; iVar7 = iVar7 + 1) {
          cw_protocol_restore8(param_1,*(undefined1 *)(piVar4[1] + iVar6));
          cw_protocol_restore8(param_1,*(undefined1 *)(piVar4[1] + iVar6 + 1));
          cw_protocol_restore_raw_bytes(param_1,piVar4[1] + iVar6 + 2,6);
          cw_protocol_restore8(param_1,*(undefined1 *)(piVar4[1] + iVar6 + 8));
          cw_protocol_restore32(param_1,*(undefined4 *)(piVar4[1] + iVar6 + 0xc));
          cw_protocol_restore8(param_1,*(undefined1 *)(piVar4[1] + iVar6 + 0x10));
          iVar3 = *piVar4;
        }
        uVar2 = *(ushort *)(param_1 + 4);
      }
      uVar5 = 0xffffffff;
      if ((uint)uVar2 - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0xffffffff;
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d sta_list list is null\n","cw_priv_sniffing_statistics_assemble"
               ,0xd2);
      }
    }
  }
  else {
    uVar5 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d Para is out of range[%u]\n",
             "cw_priv_sniffing_statistics_assemble",0xcc,*piVar4);
    }
  }
  return uVar5;
}

