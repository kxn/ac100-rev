// func byte2bit @ 0044a020 size=2220

void byte2bit(char *param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = 8;
  do {
    if (*param_1 == '\x01') {
      bVar2 = *param_2 | 0x80;
    }
    else {
      bVar2 = *param_2 & 0x7f;
    }
    *param_2 = bVar2;
    if (param_1[1] == '\x01') {
      bVar2 = *param_2 | 0x40;
    }
    else {
      bVar2 = *param_2 & 0xbf;
    }
    *param_2 = bVar2;
    if (param_1[2] == '\x01') {
      bVar2 = *param_2 | 0x20;
    }
    else {
      bVar2 = *param_2 & 0xdf;
    }
    *param_2 = bVar2;
    if (param_1[3] == '\x01') {
      bVar2 = *param_2 | 0x10;
    }
    else {
      bVar2 = *param_2 & 0xef;
    }
    *param_2 = bVar2;
    if (param_1[4] == '\x01') {
      bVar2 = *param_2 | 8;
    }
    else {
      bVar2 = *param_2 & 0xf7;
    }
    *param_2 = bVar2;
    if (param_1[5] == '\x01') {
      bVar2 = *param_2 | 4;
    }
    else {
      bVar2 = *param_2 & 0xfb;
    }
    *param_2 = bVar2;
    if (param_1[6] == '\x01') {
      bVar2 = *param_2 | 2;
    }
    else {
      bVar2 = *param_2 & 0xfd;
    }
    *param_2 = bVar2;
    if (param_1[7] == '\x01') {
      bVar2 = *param_2 | 1;
    }
    else {
      bVar2 = *param_2 & 0xfe;
    }
    iVar1 = iVar1 + -1;
    *param_2 = bVar2;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    if (param_1[8] == '\x01') {
      bVar2 = param_2[1] | 0x80;
    }
    else {
      bVar2 = param_2[1] & 0x7f;
    }
    param_2[1] = bVar2;
    if (param_1[9] == '\x01') {
      bVar2 = param_2[1] | 0x40;
    }
    else {
      bVar2 = param_2[1] & 0xbf;
    }
    param_2[1] = bVar2;
    if (param_1[10] == '\x01') {
      bVar2 = param_2[1] | 0x20;
    }
    else {
      bVar2 = param_2[1] & 0xdf;
    }
    param_2[1] = bVar2;
    if (param_1[0xb] == '\x01') {
      bVar2 = param_2[1] | 0x10;
    }
    else {
      bVar2 = param_2[1] & 0xef;
    }
    param_2[1] = bVar2;
    if (param_1[0xc] == '\x01') {
      bVar2 = param_2[1] | 8;
    }
    else {
      bVar2 = param_2[1] & 0xf7;
    }
    param_2[1] = bVar2;
    if (param_1[0xd] == '\x01') {
      bVar2 = param_2[1] | 4;
    }
    else {
      bVar2 = param_2[1] & 0xfb;
    }
    param_2[1] = bVar2;
    if (param_1[0xe] == '\x01') {
      bVar2 = param_2[1] | 2;
    }
    else {
      bVar2 = param_2[1] & 0xfd;
    }
    param_2[1] = bVar2;
    if (param_1[0xf] == '\x01') {
      bVar2 = param_2[1] | 1;
    }
    else {
      bVar2 = param_2[1] & 0xfe;
    }
    iVar1 = iVar1 + -1;
    param_2[1] = bVar2;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    if (param_1[0x10] == '\x01') {
      bVar2 = param_2[2] | 0x80;
    }
    else {
      bVar2 = param_2[2] & 0x7f;
    }
    param_2[2] = bVar2;
    if (param_1[0x11] == '\x01') {
      bVar2 = param_2[2] | 0x40;
    }
    else {
      bVar2 = param_2[2] & 0xbf;
    }
    param_2[2] = bVar2;
    if (param_1[0x12] == '\x01') {
      bVar2 = param_2[2] | 0x20;
    }
    else {
      bVar2 = param_2[2] & 0xdf;
    }
    param_2[2] = bVar2;
    if (param_1[0x13] == '\x01') {
      bVar2 = param_2[2] | 0x10;
    }
    else {
      bVar2 = param_2[2] & 0xef;
    }
    param_2[2] = bVar2;
    if (param_1[0x14] == '\x01') {
      bVar2 = param_2[2] | 8;
    }
    else {
      bVar2 = param_2[2] & 0xf7;
    }
    param_2[2] = bVar2;
    if (param_1[0x15] == '\x01') {
      bVar2 = param_2[2] | 4;
    }
    else {
      bVar2 = param_2[2] & 0xfb;
    }
    param_2[2] = bVar2;
    if (param_1[0x16] == '\x01') {
      bVar2 = param_2[2] | 2;
    }
    else {
      bVar2 = param_2[2] & 0xfd;
    }
    param_2[2] = bVar2;
    if (param_1[0x17] == '\x01') {
      bVar2 = param_2[2] | 1;
    }
    else {
      bVar2 = param_2[2] & 0xfe;
    }
    iVar1 = iVar1 + -1;
    param_2[2] = bVar2;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    if (param_1[0x18] == '\x01') {
      bVar2 = param_2[3] | 0x80;
    }
    else {
      bVar2 = param_2[3] & 0x7f;
    }
    param_2[3] = bVar2;
    if (param_1[0x19] == '\x01') {
      bVar2 = param_2[3] | 0x40;
    }
    else {
      bVar2 = param_2[3] & 0xbf;
    }
    param_2[3] = bVar2;
    if (param_1[0x1a] == '\x01') {
      bVar2 = param_2[3] | 0x20;
    }
    else {
      bVar2 = param_2[3] & 0xdf;
    }
    param_2[3] = bVar2;
    if (param_1[0x1b] == '\x01') {
      bVar2 = param_2[3] | 0x10;
    }
    else {
      bVar2 = param_2[3] & 0xef;
    }
    param_2[3] = bVar2;
    if (param_1[0x1c] == '\x01') {
      bVar2 = param_2[3] | 8;
    }
    else {
      bVar2 = param_2[3] & 0xf7;
    }
    param_2[3] = bVar2;
    if (param_1[0x1d] == '\x01') {
      bVar2 = param_2[3] | 4;
    }
    else {
      bVar2 = param_2[3] & 0xfb;
    }
    param_2[3] = bVar2;
    if (param_1[0x1e] == '\x01') {
      bVar2 = param_2[3] | 2;
    }
    else {
      bVar2 = param_2[3] & 0xfd;
    }
    param_2[3] = bVar2;
    if (param_1[0x1f] == '\x01') {
      bVar2 = param_2[3] | 1;
    }
    else {
      bVar2 = param_2[3] & 0xfe;
    }
    iVar1 = iVar1 + -1;
    param_2[3] = bVar2;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    if (param_1[0x20] == '\x01') {
      bVar2 = param_2[4] | 0x80;
    }
    else {
      bVar2 = param_2[4] & 0x7f;
    }
    param_2[4] = bVar2;
    if (param_1[0x21] == '\x01') {
      bVar2 = param_2[4] | 0x40;
    }
    else {
      bVar2 = param_2[4] & 0xbf;
    }
    param_2[4] = bVar2;
    if (param_1[0x22] == '\x01') {
      bVar2 = param_2[4] | 0x20;
    }
    else {
      bVar2 = param_2[4] & 0xdf;
    }
    param_2[4] = bVar2;
    if (param_1[0x23] == '\x01') {
      bVar2 = param_2[4] | 0x10;
    }
    else {
      bVar2 = param_2[4] & 0xef;
    }
    param_2[4] = bVar2;
    if (param_1[0x24] == '\x01') {
      bVar2 = param_2[4] | 8;
    }
    else {
      bVar2 = param_2[4] & 0xf7;
    }
    param_2[4] = bVar2;
    if (param_1[0x25] == '\x01') {
      bVar2 = param_2[4] | 4;
    }
    else {
      bVar2 = param_2[4] & 0xfb;
    }
    param_2[4] = bVar2;
    if (param_1[0x26] == '\x01') {
      bVar2 = param_2[4] | 2;
    }
    else {
      bVar2 = param_2[4] & 0xfd;
    }
    param_2[4] = bVar2;
    if (param_1[0x27] == '\x01') {
      bVar2 = param_2[4] | 1;
    }
    else {
      bVar2 = param_2[4] & 0xfe;
    }
    iVar1 = iVar1 + -1;
    param_2[4] = bVar2;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    if (param_1[0x28] == '\x01') {
      bVar2 = param_2[5] | 0x80;
    }
    else {
      bVar2 = param_2[5] & 0x7f;
    }
    param_2[5] = bVar2;
    if (param_1[0x29] == '\x01') {
      bVar2 = param_2[5] | 0x40;
    }
    else {
      bVar2 = param_2[5] & 0xbf;
    }
    param_2[5] = bVar2;
    if (param_1[0x2a] == '\x01') {
      bVar2 = param_2[5] | 0x20;
    }
    else {
      bVar2 = param_2[5] & 0xdf;
    }
    param_2[5] = bVar2;
    if (param_1[0x2b] == '\x01') {
      bVar2 = param_2[5] | 0x10;
    }
    else {
      bVar2 = param_2[5] & 0xef;
    }
    param_2[5] = bVar2;
    if (param_1[0x2c] == '\x01') {
      bVar2 = param_2[5] | 8;
    }
    else {
      bVar2 = param_2[5] & 0xf7;
    }
    param_2[5] = bVar2;
    if (param_1[0x2d] == '\x01') {
      bVar2 = param_2[5] | 4;
    }
    else {
      bVar2 = param_2[5] & 0xfb;
    }
    param_2[5] = bVar2;
    if (param_1[0x2e] == '\x01') {
      bVar2 = param_2[5] | 2;
    }
    else {
      bVar2 = param_2[5] & 0xfd;
    }
    param_2[5] = bVar2;
    if (param_1[0x2f] == '\x01') {
      bVar2 = param_2[5] | 1;
    }
    else {
      bVar2 = param_2[5] & 0xfe;
    }
    iVar1 = iVar1 + -1;
    param_2[5] = bVar2;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    if (param_1[0x30] == '\x01') {
      bVar2 = param_2[6] | 0x80;
    }
    else {
      bVar2 = param_2[6] & 0x7f;
    }
    param_2[6] = bVar2;
    if (param_1[0x31] == '\x01') {
      bVar2 = param_2[6] | 0x40;
    }
    else {
      bVar2 = param_2[6] & 0xbf;
    }
    param_2[6] = bVar2;
    if (param_1[0x32] == '\x01') {
      bVar2 = param_2[6] | 0x20;
    }
    else {
      bVar2 = param_2[6] & 0xdf;
    }
    param_2[6] = bVar2;
    if (param_1[0x33] == '\x01') {
      bVar2 = param_2[6] | 0x10;
    }
    else {
      bVar2 = param_2[6] & 0xef;
    }
    param_2[6] = bVar2;
    if (param_1[0x34] == '\x01') {
      bVar2 = param_2[6] | 8;
    }
    else {
      bVar2 = param_2[6] & 0xf7;
    }
    param_2[6] = bVar2;
    if (param_1[0x35] == '\x01') {
      bVar2 = param_2[6] | 4;
    }
    else {
      bVar2 = param_2[6] & 0xfb;
    }
    param_2[6] = bVar2;
    if (param_1[0x36] == '\x01') {
      bVar2 = param_2[6] | 2;
    }
    else {
      bVar2 = param_2[6] & 0xfd;
    }
    param_2[6] = bVar2;
    if (param_1[0x37] == '\x01') {
      bVar2 = param_2[6] | 1;
    }
    else {
      bVar2 = param_2[6] & 0xfe;
    }
    iVar1 = iVar1 + -1;
    param_2[6] = bVar2;
  } while (iVar1 != 0);
  iVar1 = 8;
  do {
    if (param_1[0x38] == '\x01') {
      bVar2 = param_2[7] | 0x80;
    }
    else {
      bVar2 = param_2[7] & 0x7f;
    }
    param_2[7] = bVar2;
    if (param_1[0x39] == '\x01') {
      bVar2 = param_2[7] | 0x40;
    }
    else {
      bVar2 = param_2[7] & 0xbf;
    }
    param_2[7] = bVar2;
    if (param_1[0x3a] == '\x01') {
      bVar2 = param_2[7] | 0x20;
    }
    else {
      bVar2 = param_2[7] & 0xdf;
    }
    param_2[7] = bVar2;
    if (param_1[0x3b] == '\x01') {
      bVar2 = param_2[7] | 0x10;
    }
    else {
      bVar2 = param_2[7] & 0xef;
    }
    param_2[7] = bVar2;
    if (param_1[0x3c] == '\x01') {
      bVar2 = param_2[7] | 8;
    }
    else {
      bVar2 = param_2[7] & 0xf7;
    }
    param_2[7] = bVar2;
    if (param_1[0x3d] == '\x01') {
      bVar2 = param_2[7] | 4;
    }
    else {
      bVar2 = param_2[7] & 0xfb;
    }
    param_2[7] = bVar2;
    if (param_1[0x3e] == '\x01') {
      bVar2 = param_2[7] | 2;
    }
    else {
      bVar2 = param_2[7] & 0xfd;
    }
    param_2[7] = bVar2;
    if (param_1[0x3f] == '\x01') {
      bVar2 = param_2[7] | 1;
    }
    else {
      bVar2 = param_2[7] & 0xfe;
    }
    iVar1 = iVar1 + -1;
    param_2[7] = bVar2;
  } while (iVar1 != 0);
  return;
}

