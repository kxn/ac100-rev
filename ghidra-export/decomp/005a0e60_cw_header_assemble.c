// func cw_header_assemble @ 005a0e60 size=424

undefined4 cw_header_assemble(int *param_1,byte *param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint local_18 [3];
  
  local_18[0] = 0;
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) || (param_2 == (byte *)0x0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_header_assemble",0xaf,
           "((NULL != pkt_buf) && (NULL != pkt_buf->buf) && (NULL != hdr))");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0xffffffff;
    if ((7 < (int)(param_1[2] - (uint)*(ushort *)(param_1 + 1))) && (*(short *)param_2 == 0)) {
      local_18[0] = (param_2[1] & 0xf) << 0x18 | (param_2[2] & 0x1f) << 0x13 |
                    (uint)*param_2 << 0x1c | (param_2[3] & 0x1f) << 0xe | (param_2[4] & 0x1f) << 9 |
                    (param_2[5] & 1) << 8 | (param_2[6] & 1) << 7 | (param_2[7] & 1) << 6 |
                    (param_2[8] & 1) << 5 | (param_2[9] & 1) << 4 | (param_2[10] & 1) << 3;
      if (param_2[0xb] == 0) {
        memcpy((void *)(*param_1 + (uint)*(ushort *)(param_1 + 1)),local_18,4);
        sVar1 = *(short *)(param_1 + 1);
        *(ushort *)(param_1 + 1) = sVar1 + 4U;
        local_18[0] = (*(ushort *)(param_2 + 0xe) & 0x1fff) << 3 |
                      (uint)*(ushort *)(param_2 + 0xc) << 0x10;
        memcpy((void *)(*param_1 + (uint)(ushort)(sVar1 + 4U)),local_18,4);
        *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + 4;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

