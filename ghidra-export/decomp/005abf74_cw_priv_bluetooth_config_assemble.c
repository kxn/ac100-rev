// func cw_priv_bluetooth_config_assemble @ 005abf74 size=208

undefined4 cw_priv_bluetooth_config_assemble(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  puVar5 = *(undefined1 **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  cw_protocol_restore8(param_1,*puVar5);
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar5 + 4));
  cw_protocol_restore32(param_1,*(undefined4 *)(puVar5 + 8));
  if (capwap_debug_switch == 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 4);
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      uVar2 = (uint)*(ushort *)(param_1 + 4);
    }
    else {
      printf("[CW_DEBUG]%32s():%4d len_check:%d/%d\n","cw_priv_bluetooth_config_assemble",0x8c,
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

