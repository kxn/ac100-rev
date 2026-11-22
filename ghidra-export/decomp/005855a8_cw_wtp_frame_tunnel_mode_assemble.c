// func cw_wtp_frame_tunnel_mode_assemble @ 005855a8 size=188

undefined4 cw_wtp_frame_tunnel_mode_assemble(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  pbVar5 = *(byte **)(param_2 + 0x10);
  bVar1 = *pbVar5;
  uVar2 = *(ushort *)(param_1 + 4);
  if ((bVar1 & 0xe) == bVar1) {
    cw_protocol_restore8();
    uVar4 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 4) - (uint)uVar2 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d frame tunnel mode(0x%02x) is wrong\n",
             "cw_wtp_frame_tunnel_mode_assemble",0xa4,(uint)*pbVar5);
    }
  }
  return uVar4;
}

