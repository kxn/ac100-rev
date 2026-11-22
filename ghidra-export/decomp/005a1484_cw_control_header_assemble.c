// func cw_control_header_assemble @ 005a1484 size=336

undefined4 cw_control_header_assemble(int *param_1,int *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 uStack_17;
  int local_14 [2];
  
  local_14[0] = 0;
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) || (param_2 == (int *)0x0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_control_header_assemble",0x17c,
           "((NULL != pkt_buf) && (NULL != pkt_buf->buf) && (NULL != ctrl_hdr))");
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 0xffffffff;
    if ((7 < (int)(param_1[2] - (uint)*(ushort *)(param_1 + 1))) &&
       ((local_14[0] = *param_2, local_14[0] - 1U < 0x1a || (local_14[0] - 0x33dd01U < 2)))) {
      memcpy((void *)(*param_1 + (uint)*(ushort *)(param_1 + 1)),local_14,4);
      sVar1 = *(short *)(param_1 + 1);
      *(ushort *)(param_1 + 1) = sVar1 + 4U;
      *(undefined1 *)(*param_1 + (uint)(ushort)(sVar1 + 4U)) = *(undefined1 *)(param_2 + 1);
      sVar1 = *(short *)(param_1 + 1);
      *(ushort *)(param_1 + 1) = sVar1 + 1U;
      puVar3 = (undefined1 *)(*param_1 + (uint)(ushort)(sVar1 + 1U));
      uVar2 = *(undefined2 *)((int)param_2 + 6);
      *puVar3 = (char)((ushort)uVar2 >> 8);
      uStack_17 = (undefined1)uVar2;
      puVar3[1] = uStack_17;
      sVar1 = *(short *)(param_1 + 1);
      *(ushort *)(param_1 + 1) = sVar1 + 2U;
      uVar4 = 0xffffffff;
      if (*(char *)(param_2 + 2) == '\0') {
        *(undefined1 *)(*param_1 + (uint)(ushort)(sVar1 + 2U)) = 0;
        *(short *)(param_1 + 1) = *(short *)(param_1 + 1) + 1;
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

