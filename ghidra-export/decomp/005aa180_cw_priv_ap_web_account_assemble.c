// func cw_priv_ap_web_account_assemble @ 005aa180 size=240

undefined4 cw_priv_ap_web_account_assemble(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  
  puVar5 = *(undefined2 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore16(param_1,*puVar5);
  cw_protocol_restore8(param_1,*(undefined1 *)(puVar5 + 1));
  cw_protocol_restore8(param_1,*(undefined1 *)((int)puVar5 + 3));
  cw_protocol_restore_raw_bytes(param_1,*(undefined4 *)(puVar5 + 2),*(undefined1 *)(puVar5 + 1));
  cw_protocol_restore_raw_bytes
            (param_1,*(undefined4 *)(puVar5 + 4),*(undefined1 *)((int)puVar5 + 3));
  if (capwap_debug_switch == 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 4);
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      uVar2 = (uint)*(ushort *)(param_1 + 4);
    }
    else {
      printf("[CW_DEBUG]%32s():%4d len_check:%d/%d\n","cw_priv_ap_web_account_assemble",0xa0,
             (uint)*(ushort *)(param_1 + 4) - (uint)uVar1,(uint)*(ushort *)(param_2 + 0xe));
      uVar2 = (uint)*(ushort *)(param_1 + 4);
    }
  }
  uVar4 = 0xffffffff;
  if (uVar2 - uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
    uVar4 = 0;
  }
  return uVar4;
}

