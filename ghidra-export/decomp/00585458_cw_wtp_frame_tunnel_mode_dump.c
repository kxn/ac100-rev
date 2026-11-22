// func cw_wtp_frame_tunnel_mode_dump @ 00585458 size=276

undefined4 cw_wtp_frame_tunnel_mode_dump(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) WTP Frame Tunnel Mode  \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: WTP Frame Tunnel Mode  (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %0x \r\n",(uint)*pbVar3);
  if ((*pbVar3 & 0xe) == *pbVar3) {
    puts("\t\t\tWTP Frame Tunnel Mode \r");
    iVar1 = (int)((uint)*pbVar3 << 0x1c) >> 0x1f;
    printf("\t\t\t\t.... %d... = Native Frame Tunnel Mode: %s \r\n",-iVar1,
           *(undefined4 *)(&UNK_006dd2d0 + iVar1 * -4));
    iVar1 = (int)((uint)*pbVar3 << 0x1d) >> 0x1f;
    printf("\t\t\t\t.... .%d.. = 802.3 Frame Tunnel Mode: %s \r\n",-iVar1,
           *(undefined4 *)(&UNK_006dd2d0 + iVar1 * -4));
    iVar1 = (int)((uint)*pbVar3 << 0x1e) >> 0x1f;
    printf("\t\t\t\t.... ..%d. = Local Bridging: %s \r\n",-iVar1,
           *(undefined4 *)(&UNK_006dd2d0 + iVar1 * -4));
    puts("\t\t\t\t0000 ...0 = Reserved: Not set \r");
    uVar2 = 0;
  }
  else {
    printf("\t\t\t***WTP Frame Tunnel Mode(%02x) is wrong \r\n");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

