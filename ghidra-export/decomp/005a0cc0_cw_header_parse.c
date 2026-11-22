// func cw_header_parse @ 005a0cc0 size=416

undefined4 cw_header_parse(int *param_1,byte *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int local_20 [3];
  
  local_20[0] = 0;
  if (((param_1 == (int *)0x0) || ((byte *)*param_1 == (byte *)0x0)) || (param_2 == (byte *)0x0)) {
    uVar2 = 0xffffffff;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_parse",0x69,
           "((NULL != pkt_buf) && (NULL != pkt_buf->buf) && (NULL != hdr))");
  }
  else {
    uVar2 = 0xffffffff;
    if ((((uint)*(ushort *)((int)param_1 + 6) <= (uint)*(ushort *)(param_1 + 1)) &&
        (7 < (int)((uint)*(ushort *)(param_1 + 1) - (uint)*(ushort *)((int)param_1 + 6)))) &&
       (*(byte *)*param_1 < 2)) {
      memset(param_2,0,0x10);
      uVar1 = *(ushort *)((int)param_1 + 6);
      memcpy(local_20,(void *)(*param_1 + (uint)uVar1),4);
      *(ushort *)((int)param_1 + 6) = uVar1 + 4;
      *param_2 = (byte)((uint)local_20[0] >> 0x1c);
      param_2[7] = (byte)((uint)(local_20[0] << 0x19) >> 0x1f);
      param_2[1] = (byte)((uint)(local_20[0] << 4) >> 0x1c);
      param_2[2] = (byte)((uint)local_20[0] >> 0x10) >> 3;
      param_2[3] = (byte)((uint)(local_20[0] << 0xd) >> 0x1b);
      param_2[4] = (byte)((uint)(local_20[0] << 0x12) >> 0x1b);
      param_2[5] = (byte)((uint)(local_20[0] << 0x17) >> 0x1f);
      param_2[6] = (byte)local_20[0] >> 7;
      if ((-1 < local_20[0] << 0x19) || (local_20[0] << 0x18 < 0)) {
        param_2[8] = (byte)((uint)(local_20[0] << 0x1a) >> 0x1f);
        param_2[9] = (byte)((uint)(local_20[0] << 0x1b) >> 0x1f);
        param_2[10] = (byte)((uint)(local_20[0] << 0x1c) >> 0x1f);
        uVar2 = 0;
        uVar1 = *(ushort *)((int)param_1 + 6);
        memcpy(local_20,(void *)(*param_1 + (uint)uVar1),4);
        *(ushort *)((int)param_1 + 6) = uVar1 + 4;
        *(short *)(param_2 + 0xc) = (short)((uint)local_20[0] >> 0x10);
        *(ushort *)(param_2 + 0xe) = (ushort)local_20[0] >> 3;
        *(ushort *)((int)param_1 + 6) = (param_2[2] - 2) * 4 + *(short *)((int)param_1 + 6);
      }
    }
  }
  return uVar2;
}

