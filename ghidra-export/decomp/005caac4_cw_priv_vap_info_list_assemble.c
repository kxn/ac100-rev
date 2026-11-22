// func cw_priv_vap_info_list_assemble @ 005caac4 size=496

undefined4 cw_priv_vap_info_list_assemble(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar7 = 0;
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*pbVar6);
  bVar3 = *pbVar6 != 0;
  if (*pbVar6 == 0) goto LAB_005cab20;
  if (*(int *)(pbVar6 + 4) == 0) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
      printf("[CW_ERROR]%32s():%4d Input error\n","cw_priv_vap_info_list_assemble",0x11c);
    }
  }
  else {
    while( true ) {
      bVar3 = iVar7 < (int)(uint)*pbVar6;
LAB_005cab20:
      if (!bVar3) break;
      iVar5 = *(int *)(pbVar6 + 4) + iVar7 * 0x20;
      cw_protocol_restore_raw_bytes(param_1,iVar5,6);
      cw_protocol_restore8(param_1,*(undefined1 *)(iVar5 + 6));
      cw_protocol_restore8(param_1,*(undefined1 *)(iVar5 + 7));
      cw_protocol_restore16(param_1,*(undefined2 *)(iVar5 + 8));
      cw_protocol_restore32(param_1,*(undefined4 *)(iVar5 + 0xc));
      cw_protocol_restore16(param_1,*(undefined2 *)(iVar5 + 0x10));
      for (iVar5 = FUN_004081b0(iVar5 + 0x14); iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
        if (*(short *)(iVar5 + 0xe) == 0) {
          uVar2 = *(undefined2 *)(iVar5 + 0xc);
        }
        else {
          if (*(int *)(iVar5 + 0x10) == 0) {
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar7 = is_target_debug_ap();
            if (iVar7 == 0) {
              return 0xffffffff;
            }
            printf("[CW_ERROR]%32s():%4d Data can not be NULL for sub ele type(%d)\n",
                   "cw_priv_vap_info_list_assemble",0x12d,(uint)*(ushort *)(iVar5 + 0xc));
            return 0xffffffff;
          }
          uVar2 = *(undefined2 *)(iVar5 + 0xc);
        }
        cw_protocol_restore16(param_1,uVar2);
        cw_protocol_restore16(param_1,*(undefined2 *)(iVar5 + 0xe));
        if ((*(short *)(iVar5 + 0xe) != 0) && (*(int *)(iVar5 + 0x10) != 0)) {
          cw_protocol_restore_raw_bytes(param_1);
        }
      }
      iVar7 = iVar7 + 1;
    }
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

