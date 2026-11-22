// func cw_priv_ndp_para_assemble @ 005b7aac size=408

undefined4 cw_priv_ndp_para_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_2 + 0x10);
  uVar2 = *(ushort *)(param_1 + 4);
  cw_protocol_restore_raw_bytes(param_1,iVar6,6);
  if (*(byte *)(iVar6 + 6) < 0x20) {
    cw_protocol_restore8(param_1);
    cw_protocol_restore8(param_1,*(undefined1 *)(iVar6 + 7));
    cw_protocol_restore16(param_1,*(undefined2 *)(iVar6 + 8));
    cw_protocol_restore16(param_1,*(undefined2 *)(iVar6 + 10));
    cw_protocol_restore16(param_1,*(undefined2 *)(iVar6 + 0xc));
    cw_protocol_restore16(param_1,*(undefined2 *)(iVar6 + 0xe));
    cw_protocol_restore8(param_1,*(undefined1 *)(iVar6 + 0x10));
    cw_protocol_restore8(param_1,*(undefined1 *)(iVar6 + 0x11));
    cw_protocol_restore8(param_1,*(undefined1 *)(iVar6 + 0x12));
    if (*(byte *)(iVar6 + 0x13) < 0x21) {
      cw_protocol_restore8(param_1);
      if (*(char *)(iVar6 + 0x13) == '\0') {
        uVar3 = *(ushort *)(param_1 + 4);
      }
      else {
        cw_protocol_restore_raw_bytes(param_1,iVar6 + 0x14);
        uVar3 = *(ushort *)(param_1 + 4);
      }
      if ((uint)uVar3 - (uint)uVar2 != (uint)*(ushort *)(param_2 + 0xe)) {
        return 0xffffffff;
      }
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar1 = *(byte *)(iVar6 + 0x13);
    __format = "[CW_ERROR]%32s():%4d channel cnt(%d) is wrong\n";
    uVar5 = 0xcc;
  }
  else {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    bVar1 = *(byte *)(iVar6 + 6);
    __format = "[CW_ERROR]%32s():%4d radio id(%d) is wrong\n";
    uVar5 = 0xbe;
  }
  printf(__format,"cw_priv_ndp_para_assemble",uVar5,(uint)bVar1);
  return 0xffffffff;
}

