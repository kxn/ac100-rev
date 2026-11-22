// func rdmngr_db_do_relativity @ 0061b9ec size=480

undefined4 rdmngr_db_do_relativity(int param_1,int param_2,short param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = (int)*(short *)(param_1 + 8);
  if (iVar3 == -1) {
    *(short *)(param_2 + 8) = *(short *)(param_1 + 8);
  }
  else if (iVar3 == 1) {
    *(undefined2 *)(param_2 + 8) = 0xb;
  }
  else if (iVar3 == 0xb) {
    *(undefined2 *)(param_2 + 8) = 1;
  }
  else if ((iVar3 - 1U & 0xffff) < 0xd) {
    *(undefined2 *)(param_2 + 8) = 0xffff;
  }
  else {
    uVar2 = 0;
    if (param_3 != -1) goto LAB_0061ba44;
    if (iVar3 == 0x95) {
      *(undefined2 *)(param_2 + 8) = 0xa1;
    }
    else {
      *(undefined2 *)(param_2 + 8) = 0x95;
    }
  }
  uVar2 = 1;
LAB_0061ba44:
  if (*(char *)(param_2 + 10) == *(char *)(param_1 + 10)) {
    sVar1 = *(short *)(param_1 + 0xc);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 10) = *(char *)(param_1 + 10);
    sVar1 = *(short *)(param_1 + 0xc);
  }
  if (*(short *)(param_2 + 0xc) == sVar1) {
    sVar1 = *(short *)(param_1 + 0xe);
  }
  else {
    uVar2 = 1;
    *(short *)(param_2 + 0xc) = sVar1;
    sVar1 = *(short *)(param_1 + 0xe);
  }
  if (*(short *)(param_2 + 0xe) == sVar1) {
    sVar1 = *(short *)(param_1 + 0x12);
  }
  else {
    uVar2 = 1;
    *(short *)(param_2 + 0xe) = sVar1;
    sVar1 = *(short *)(param_1 + 0x12);
  }
  if (*(short *)(param_2 + 0x12) == sVar1) {
    cVar4 = *(char *)(param_1 + 0x14);
  }
  else {
    uVar2 = 1;
    *(short *)(param_2 + 0x12) = sVar1;
    cVar4 = *(char *)(param_1 + 0x14);
  }
  if (*(char *)(param_2 + 0x14) == cVar4) {
    cVar4 = *(char *)(param_1 + 0x45);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 0x14) = cVar4;
    cVar4 = *(char *)(param_1 + 0x45);
  }
  if (*(char *)(param_2 + 0x45) == cVar4) {
    cVar4 = *(char *)(param_1 + 5);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 0x45) = cVar4;
    cVar4 = *(char *)(param_1 + 5);
  }
  if (*(char *)(param_2 + 5) == cVar4) {
    cVar4 = *(char *)(param_1 + 6);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 5) = cVar4;
    cVar4 = *(char *)(param_1 + 6);
  }
  if (*(char *)(param_2 + 6) == cVar4) {
    cVar4 = *(char *)(param_1 + 0x23);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 6) = cVar4;
    cVar4 = *(char *)(param_1 + 0x23);
  }
  if (*(char *)(param_2 + 0x23) == cVar4) {
    cVar4 = *(char *)(param_1 + 0x24);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 0x23) = cVar4;
    cVar4 = *(char *)(param_1 + 0x24);
  }
  if (*(char *)(param_2 + 0x24) == cVar4) {
    sVar1 = *(short *)(param_1 + 0x16);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 0x24) = cVar4;
    sVar1 = *(short *)(param_1 + 0x16);
  }
  if (*(short *)(param_2 + 0x16) == sVar1) {
    cVar4 = *(char *)(param_1 + 0x27);
  }
  else {
    uVar2 = 1;
    *(short *)(param_2 + 0x16) = sVar1;
    cVar4 = *(char *)(param_1 + 0x27);
  }
  if (*(char *)(param_2 + 0x27) == cVar4) {
    cVar4 = *(char *)(param_1 + 0x28);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 0x27) = cVar4;
    cVar4 = *(char *)(param_1 + 0x28);
  }
  if (*(char *)(param_2 + 0x28) == cVar4) {
    cVar4 = *(char *)(param_1 + 0x29);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 0x28) = cVar4;
    cVar4 = *(char *)(param_1 + 0x29);
  }
  if (*(char *)(param_2 + 0x29) == cVar4) {
    cVar4 = *(char *)(param_1 + 0x2a);
  }
  else {
    uVar2 = 1;
    *(char *)(param_2 + 0x29) = cVar4;
    cVar4 = *(char *)(param_1 + 0x2a);
  }
  if (*(char *)(param_2 + 0x2a) != cVar4) {
    uVar2 = 1;
    *(char *)(param_2 + 0x2a) = cVar4;
  }
  return uVar2;
}

