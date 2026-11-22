// func MD4Init @ 0044befc size=88

void MD4Init(undefined4 *param_1)

{
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  *param_1 = 0x67452301;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  param_1[1] = 0xefcdab89;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  param_1[2] = 0x98badcfe;
  param_1[6] = 0;
  param_1[3] = 0x10325476;
  return;
}

