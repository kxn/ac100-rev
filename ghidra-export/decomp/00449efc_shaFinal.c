// func shaFinal @ 00449efc size=284

void shaFinal(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  undefined1 local_20;
  undefined1 local_1f [3];
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
  local_1f[0] = 0x80;
  uVar1 = *(undefined4 *)(param_1 + 0x158);
  local_20 = 0;
  local_19 = (undefined1)uVar1;
  local_1c = (undefined1)((uint)uVar1 >> 0x18);
  local_1b = (undefined1)((uint)uVar1 >> 0x10);
  uVar2 = *(undefined4 *)(param_1 + 0x15c);
  local_1a = (undefined1)((uint)uVar1 >> 8);
  local_15 = (undefined1)uVar2;
  local_18 = (undefined1)((uint)uVar2 >> 0x18);
  local_17 = (undefined1)((uint)uVar2 >> 0x10);
  local_16 = (undefined1)((uint)uVar2 >> 8);
  shaUpdate(param_1,local_1f,1);
  while (*(int *)(param_1 + 0x154) != 0x38) {
    shaUpdate(param_1,&local_20,1);
  }
  shaUpdate(param_1,&local_1c,8);
  iVar3 = 0;
  do {
    iVar4 = iVar3 >> 2;
    puVar6 = (undefined1 *)(param_2 + iVar3);
    iVar3 = iVar3 + 1;
    piVar5 = (int *)(param_1 + iVar4 * 4);
    *puVar6 = *(undefined1 *)piVar5;
    *piVar5 = *piVar5 << 8;
  } while (iVar3 != 0x14);
  shaInit(param_1);
  return;
}

