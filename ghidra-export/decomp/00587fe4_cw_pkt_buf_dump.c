// func cw_pkt_buf_dump @ 00587fe4 size=172

void cw_pkt_buf_dump(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 != (int *)0x0) && (uVar2 = 0, *(short *)(param_1 + 1) != 0)) {
    for (; (int)uVar2 < (int)(uint)*(ushort *)(param_1 + 1); uVar2 = uVar2 + 1) {
      if (uVar2 == 0) {
        iVar1 = *param_1;
      }
      else if ((uVar2 & 0xf) == 0) {
        putchar(10);
        iVar1 = *param_1;
      }
      else {
        iVar1 = *param_1;
      }
      printf("%02x ",(uint)*(byte *)(iVar1 + uVar2));
    }
    putchar(10);
    return;
  }
  return;
}

