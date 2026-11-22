// func rdmngr_db_5g_do_relativity @ 0061c0f0 size=1

undefined4
rdmngr_db_5g_do_relativity
          (int *param_1,int param_2,int param_3,short param_4,undefined4 *param_5,int param_6,
          undefined4 *param_7)

{
  short sVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar6;
  int iVar5;
  
  pcVar2 = (char *)(param_3 + 0x31);
  iVar4 = 0;
  do {
    if (param_6 <= iVar4) {
      return 0;
    }
    uVar3 = 0;
    if (*param_1 == 0) {
code_r0x0061c118:
      iVar5 = param_1[7];
    }
    else {
      if (*(short *)(param_2 + 8) != param_4) {
        if (*(short *)(param_2 + 8) == -1) {
          pcVar2[-0xffffffff00000025] = -1;
          pcVar2[-0xffffffff00000024] = -1;
          uVar3 = 1;
        }
        else if (param_4 == -1) {
          *(short *)(pcVar2 + -0x25) = (short)*param_5;
          uVar3 = 1;
        }
        goto code_r0x0061c118;
      }
      iVar5 = param_1[7];
    }
    if (iVar5 == 0) {
      iVar5 = param_1[1];
    }
    else {
      if (pcVar2[-0x23] == *(char *)(param_2 + 10)) {
        sVar1 = *(short *)(param_2 + 0xc);
      }
      else {
        uVar3 = 1;
        pcVar2[-0x23] = *(char *)(param_2 + 10);
        sVar1 = *(short *)(param_2 + 0xc);
      }
      if (*(short *)(pcVar2 + -0x21) == sVar1) {
        sVar1 = *(short *)(param_2 + 0xe);
      }
      else {
        uVar3 = 1;
        *(short *)(pcVar2 + -0x21) = sVar1;
        sVar1 = *(short *)(param_2 + 0xe);
      }
      if (*(short *)(pcVar2 + -0x1f) == sVar1) {
        sVar1 = *(short *)(param_2 + 0x12);
      }
      else {
        uVar3 = 1;
        *(short *)(pcVar2 + -0x1f) = sVar1;
        sVar1 = *(short *)(param_2 + 0x12);
      }
      if (*(short *)(pcVar2 + -0x1b) == sVar1) {
        cVar6 = *(char *)(param_2 + 0x14);
      }
      else {
        uVar3 = 1;
        *(short *)(pcVar2 + -0x1b) = sVar1;
        cVar6 = *(char *)(param_2 + 0x14);
      }
      if (pcVar2[-0x19] == cVar6) {
        cVar6 = *(char *)(param_2 + 0x45);
      }
      else {
        uVar3 = 1;
        pcVar2[-0x19] = cVar6;
        cVar6 = *(char *)(param_2 + 0x45);
      }
      if (pcVar2[0x18] == cVar6) {
        iVar5 = param_1[1];
      }
      else {
        uVar3 = 1;
        pcVar2[0x18] = cVar6;
        iVar5 = param_1[1];
      }
    }
    if (iVar5 == 0) {
      iVar5 = param_1[2];
    }
    else if (pcVar2[-0x28] == *(char *)(param_2 + 5)) {
      iVar5 = param_1[2];
    }
    else {
      uVar3 = 1;
      pcVar2[-0x28] = *(char *)(param_2 + 5);
      iVar5 = param_1[2];
    }
    if (iVar5 == 0) {
      iVar5 = param_1[3];
    }
    else if (pcVar2[-0x27] == *(char *)(param_2 + 6)) {
      iVar5 = param_1[3];
    }
    else {
      uVar3 = 1;
      pcVar2[-0x27] = *(char *)(param_2 + 6);
      iVar5 = param_1[3];
    }
    if (iVar5 == 0) {
      iVar5 = param_1[4];
    }
    else if (pcVar2[-10] == *(char *)(param_2 + 0x23)) {
      iVar5 = param_1[4];
    }
    else {
      uVar3 = 1;
      pcVar2[-10] = *(char *)(param_2 + 0x23);
      iVar5 = param_1[4];
    }
    if (iVar5 == 0) {
      iVar5 = param_1[5];
    }
    else if (pcVar2[-9] == *(char *)(param_2 + 0x24)) {
      iVar5 = param_1[5];
    }
    else {
      uVar3 = 1;
      pcVar2[-9] = *(char *)(param_2 + 0x24);
      iVar5 = param_1[5];
    }
    if (iVar5 == 0) {
      iVar5 = param_1[6];
    }
    else if (*(short *)(pcVar2 + -0x17) == *(short *)(param_2 + 0x16)) {
      iVar5 = param_1[6];
    }
    else {
      uVar3 = 1;
      *(short *)(pcVar2 + -0x17) = *(short *)(param_2 + 0x16);
      iVar5 = param_1[6];
    }
    if (iVar5 == 0) {
      iVar5 = param_1[8];
    }
    else {
      if (pcVar2[-6] == *(char *)(param_2 + 0x27)) {
        cVar6 = *(char *)(param_2 + 0x28);
      }
      else {
        uVar3 = 1;
        pcVar2[-6] = *(char *)(param_2 + 0x27);
        cVar6 = *(char *)(param_2 + 0x28);
      }
      if (pcVar2[-5] == cVar6) {
        cVar6 = *(char *)(param_2 + 0x29);
      }
      else {
        uVar3 = 1;
        pcVar2[-5] = cVar6;
        cVar6 = *(char *)(param_2 + 0x29);
      }
      if (pcVar2[-4] == cVar6) {
        cVar6 = *(char *)(param_2 + 0x2a);
      }
      else {
        uVar3 = 1;
        pcVar2[-4] = cVar6;
        cVar6 = *(char *)(param_2 + 0x2a);
      }
      if (pcVar2[-3] == cVar6) {
        iVar5 = param_1[8];
      }
      else {
        uVar3 = 1;
        pcVar2[-3] = cVar6;
        iVar5 = param_1[8];
      }
    }
    if (iVar5 == 0) {
      iVar5 = param_1[9];
    }
    else if (*(short *)(pcVar2 + -0x11) == *(short *)(param_2 + 0x1c)) {
      iVar5 = param_1[9];
    }
    else {
      uVar3 = 1;
      *(short *)(pcVar2 + -0x11) = *(short *)(param_2 + 0x1c);
      iVar5 = param_1[9];
    }
    if (iVar5 == 0) {
      *param_7 = uVar3;
    }
    else {
      if (pcVar2[-2] == *(char *)(param_2 + 0x2b)) {
        cVar6 = *(char *)(param_2 + 0x2c);
      }
      else {
        uVar3 = 1;
        pcVar2[-2] = *(char *)(param_2 + 0x2b);
        cVar6 = *(char *)(param_2 + 0x2c);
      }
      if (pcVar2[-1] == cVar6) {
        cVar6 = *(char *)(param_2 + 0x2d);
      }
      else {
        uVar3 = 1;
        pcVar2[-1] = cVar6;
        cVar6 = *(char *)(param_2 + 0x2d);
      }
      if (*pcVar2 == cVar6) {
        *param_7 = uVar3;
      }
      else {
        *pcVar2 = cVar6;
        *param_7 = 1;
      }
    }
    iVar4 = iVar4 + 1;
    param_7 = param_7 + 1;
    pcVar2 = pcVar2 + 0x54;
    param_5 = param_5 + 1;
  } while( true );
}

