// func cw_wtp_reboot_statistics_assemble @ 005868e8 size=280

undefined4 cw_wtp_reboot_statistics_assemble(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  puVar3 = *(undefined2 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if ((byte)(*(char *)(puVar3 + 7) - 6U) < 0xf9) {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d last failure type(%d) is wrong\n",
             "cw_wtp_reboot_statistics_assemble",0xbf,(uint)*(byte *)(puVar3 + 7));
    }
  }
  else {
    cw_protocol_restore16(param_1,*puVar3);
    cw_protocol_restore16(param_1,puVar3[1]);
    cw_protocol_restore16(param_1,puVar3[2]);
    cw_protocol_restore16(param_1,puVar3[3]);
    cw_protocol_restore16(param_1,puVar3[4]);
    cw_protocol_restore16(param_1,puVar3[5]);
    cw_protocol_restore16(param_1,puVar3[6]);
    cw_protocol_restore8(param_1,*(undefined1 *)(puVar3 + 7));
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

