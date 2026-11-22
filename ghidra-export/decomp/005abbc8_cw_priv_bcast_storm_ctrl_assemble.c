// func cw_priv_bcast_storm_ctrl_assemble @ 005abbc8 size=276

undefined4 cw_priv_bcast_storm_ctrl_assemble(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (capwap_debug_switch == 0) {
    bVar5 = *pbVar6;
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      bVar5 = *pbVar6;
    }
    else {
      printf("[CW_DEBUG]%32s():%4d state:%d,rate:%d\n","cw_priv_bcast_storm_ctrl_assemble",0x88,
             (uint)*pbVar6,*(undefined4 *)(pbVar6 + 4));
      bVar5 = *pbVar6;
    }
  }
  cw_protocol_restore8(param_1,bVar5);
  cw_protocol_restore32(param_1,*(undefined4 *)(pbVar6 + 4));
  if (capwap_debug_switch == 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 4);
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      uVar2 = (uint)*(ushort *)(param_1 + 4);
    }
    else {
      printf("[CW_DEBUG]%32s():%4d len_check:%d/%d\n","cw_priv_bcast_storm_ctrl_assemble",0x8f,
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

