// func printbinry @ 005b4788 size=108

void printbinry(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 7;
  uVar1 = (int)(param_1 & 0xff) >> 7;
  do {
    uVar2 = uVar2 - 1;
    printf("%u",uVar1 & 1);
    uVar1 = (int)(param_1 & 0xff) >> (uVar2 & 0x1f);
  } while (uVar2 != 0xffffffff);
  puts("\r");
  return;
}

