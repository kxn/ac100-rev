// func rdmngr_db_2_4g_do_relativity @ 0061bd2c size=1

undefined4
rdmngr_db_2_4g_do_relativity
          (int *param_1,int param_2,int param_3,short param_4,undefined4 *param_5,int param_6,
          int *param_7)

{
  short sVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  
  if ((rdmngr_debug_switch != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d link_cnt(%d).\n","rdmngr_db_2_4g_do_relativity",0xa00,param_6);
  }
  pcVar6 = (char *)(param_3 + 0x31);
  iVar7 = 0;
  do {
    if (param_6 <= iVar7) {
      return 0;
    }
    iVar2 = 0;
    if (*param_1 == 0) {
code_r0x0061bde8:
      iVar4 = param_1[7];
    }
    else {
      iVar4 = (int)*(short *)(param_2 + 8);
      if (iVar4 != param_4) {
        if (iVar4 == -1) {
          pcVar6[-0xffffffff00000025] = -1;
          pcVar6[-0xffffffff00000024] = -1;
        }
        else {
          if (0xc < (iVar4 - 1U & 0xffff)) {
            iVar4 = param_1[7];
            goto code_r0x0061bdec;
          }
          *(short *)(pcVar6 + -0x25) = (short)*param_5;
        }
        iVar2 = 1;
        goto code_r0x0061bde8;
      }
      iVar4 = param_1[7];
    }
code_r0x0061bdec:
    if (iVar4 == 0) {
      iVar4 = param_1[1];
    }
    else {
      if (pcVar6[-0x23] == *(char *)(param_2 + 10)) {
        sVar1 = *(short *)(param_2 + 0xc);
      }
      else {
        iVar2 = 1;
        pcVar6[-0x23] = *(char *)(param_2 + 10);
        sVar1 = *(short *)(param_2 + 0xc);
      }
      if (*(short *)(pcVar6 + -0x21) == sVar1) {
        sVar1 = *(short *)(param_2 + 0xe);
      }
      else {
        iVar2 = 1;
        *(short *)(pcVar6 + -0x21) = sVar1;
        sVar1 = *(short *)(param_2 + 0xe);
      }
      if (*(short *)(pcVar6 + -0x1f) == sVar1) {
        sVar1 = *(short *)(param_2 + 0x12);
      }
      else {
        iVar2 = 1;
        *(short *)(pcVar6 + -0x1f) = sVar1;
        sVar1 = *(short *)(param_2 + 0x12);
      }
      if (*(short *)(pcVar6 + -0x1b) == sVar1) {
        cVar5 = *(char *)(param_2 + 0x14);
      }
      else {
        iVar2 = 1;
        *(short *)(pcVar6 + -0x1b) = sVar1;
        cVar5 = *(char *)(param_2 + 0x14);
      }
      if (pcVar6[-0x19] == cVar5) {
        cVar5 = *(char *)(param_2 + 0x45);
      }
      else {
        iVar2 = 1;
        pcVar6[-0x19] = cVar5;
        cVar5 = *(char *)(param_2 + 0x45);
      }
      if (pcVar6[0x18] == cVar5) {
        iVar4 = param_1[1];
      }
      else {
        iVar2 = 1;
        pcVar6[0x18] = cVar5;
        iVar4 = param_1[1];
      }
    }
    if (iVar4 == 0) {
      iVar4 = param_1[2];
    }
    else if (pcVar6[-0x28] == *(char *)(param_2 + 5)) {
      iVar4 = param_1[2];
    }
    else {
      iVar2 = 1;
      pcVar6[-0x28] = *(char *)(param_2 + 5);
      iVar4 = param_1[2];
    }
    if (iVar4 == 0) {
      iVar4 = param_1[3];
    }
    else if (pcVar6[-0x27] == *(char *)(param_2 + 6)) {
      iVar4 = param_1[3];
    }
    else {
      iVar2 = 1;
      pcVar6[-0x27] = *(char *)(param_2 + 6);
      iVar4 = param_1[3];
    }
    if (iVar4 == 0) {
      iVar4 = param_1[4];
    }
    else if (pcVar6[-10] == *(char *)(param_2 + 0x23)) {
      iVar4 = param_1[4];
    }
    else {
      iVar2 = 1;
      pcVar6[-10] = *(char *)(param_2 + 0x23);
      iVar4 = param_1[4];
    }
    if (iVar4 == 0) {
      iVar4 = param_1[5];
    }
    else if (pcVar6[-9] == *(char *)(param_2 + 0x24)) {
      iVar4 = param_1[5];
    }
    else {
      iVar2 = 1;
      pcVar6[-9] = *(char *)(param_2 + 0x24);
      iVar4 = param_1[5];
    }
    if (iVar4 == 0) {
      iVar4 = param_1[6];
    }
    else if (*(short *)(pcVar6 + -0x17) == *(short *)(param_2 + 0x16)) {
      iVar4 = param_1[6];
    }
    else {
      iVar2 = 1;
      *(short *)(pcVar6 + -0x17) = *(short *)(param_2 + 0x16);
      iVar4 = param_1[6];
    }
    if (iVar4 == 0) {
      iVar4 = param_1[8];
    }
    else {
      if (pcVar6[-6] == *(char *)(param_2 + 0x27)) {
        cVar5 = *(char *)(param_2 + 0x28);
      }
      else {
        iVar2 = 1;
        pcVar6[-6] = *(char *)(param_2 + 0x27);
        cVar5 = *(char *)(param_2 + 0x28);
      }
      if (pcVar6[-5] == cVar5) {
        cVar5 = *(char *)(param_2 + 0x29);
      }
      else {
        iVar2 = 1;
        pcVar6[-5] = cVar5;
        cVar5 = *(char *)(param_2 + 0x29);
      }
      if (pcVar6[-4] == cVar5) {
        cVar5 = *(char *)(param_2 + 0x2a);
      }
      else {
        iVar2 = 1;
        pcVar6[-4] = cVar5;
        cVar5 = *(char *)(param_2 + 0x2a);
      }
      if (pcVar6[-3] == cVar5) {
        iVar4 = param_1[8];
      }
      else {
        iVar2 = 1;
        pcVar6[-3] = cVar5;
        iVar4 = param_1[8];
      }
    }
    if (iVar4 == 0) {
      iVar4 = param_1[9];
    }
    else if (*(short *)(pcVar6 + -0x11) == *(short *)(param_2 + 0x1c)) {
      iVar4 = param_1[9];
    }
    else {
      iVar2 = 1;
      *(short *)(pcVar6 + -0x11) = *(short *)(param_2 + 0x1c);
      iVar4 = param_1[9];
    }
    if (iVar4 == 0) {
      *param_7 = iVar2;
    }
    else {
      if (pcVar6[-2] == *(char *)(param_2 + 0x2b)) {
        cVar5 = *(char *)(param_2 + 0x2c);
      }
      else {
        iVar2 = 1;
        pcVar6[-2] = *(char *)(param_2 + 0x2b);
        cVar5 = *(char *)(param_2 + 0x2c);
      }
      if (pcVar6[-1] == cVar5) {
        cVar5 = *(char *)(param_2 + 0x2d);
      }
      else {
        iVar2 = 1;
        pcVar6[-1] = cVar5;
        cVar5 = *(char *)(param_2 + 0x2d);
      }
      if (*pcVar6 == cVar5) {
        *param_7 = iVar2;
      }
      else {
        *pcVar6 = cVar5;
        *param_7 = 1;
      }
    }
    if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar3 = "changed";
      if (*param_7 == 0) {
        pcVar3 = "not change";
      }
      printf("[RDMNGR_DEBUG]%s()/%d config[%d] %s\n","rdmngr_db_2_4g_do_relativity",0xaae,iVar7,
             pcVar3);
    }
    iVar7 = iVar7 + 1;
    param_7 = param_7 + 1;
    pcVar6 = pcVar6 + 0x54;
    param_5 = param_5 + 1;
  } while( true );
}

