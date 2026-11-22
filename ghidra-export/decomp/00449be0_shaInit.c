// func shaInit @ 00449be0 size=104

void shaInit(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  param_1[0x55] = 0;
  param_1[0x57] = 0;
  param_1[0x56] = 0;
  *param_1 = 0x67452301;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  param_1[4] = 0xc3d2e1f0;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)param_1 + iVar1 + 0x14) = 0;
    iVar1 = iVar2;
  } while (iVar2 != 0x140);
  return;
}

