// func transfer_rate_db_to_rate_md5 @ 0055cb78 size=600

void transfer_rate_db_to_rate_md5(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    uVar3 = 0x4a;
    pcVar4 = "NULL != rate_cfg";
  }
  else {
    if (param_2 != (uint *)0x0) {
      iVar6 = 0x10;
      memset(param_2,0,0x48);
      memcpy(param_2 + 9,(void *)(param_1 + 400),0xc);
      memcpy(param_2 + 0xc,(void *)(param_1 + 0x19c),0xc);
      memcpy(param_2 + 0xf,(void *)(param_1 + 0x1a8),0xc);
      iVar5 = param_1;
      do {
        if (*(int *)(iVar5 + 4) == 0) {
          iVar2 = *(int *)(iVar5 + 0x44);
        }
        else {
          uVar1 = rate_position_get();
          if (uVar1 != 0xffffffff) {
            *param_2 = *param_2 | 1 << (uVar1 & 0x1f);
          }
          iVar2 = *(int *)(iVar5 + 0x44);
        }
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar5 + 0x88);
        }
        else {
          uVar1 = rate_position_get();
          if (uVar1 != 0xffffffff) {
            param_2[1] = param_2[1] | 1 << (uVar1 & 0x1f);
          }
          iVar2 = *(int *)(iVar5 + 0x88);
        }
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar5 + 200);
        }
        else {
          uVar1 = rate_position_get();
          if (uVar1 != 0xffffffff) {
            param_2[3] = param_2[3] | 1 << (uVar1 & 0x1f);
          }
          iVar2 = *(int *)(iVar5 + 200);
        }
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar5 + 0x10c);
        }
        else {
          uVar1 = rate_position_get();
          if (uVar1 != 0xffffffff) {
            param_2[4] = param_2[4] | 1 << (uVar1 & 0x1f);
          }
          iVar2 = *(int *)(iVar5 + 0x10c);
        }
        if (iVar2 == 0) {
          iVar2 = *(int *)(iVar5 + 0x14c);
        }
        else {
          uVar1 = rate_position_get();
          if (uVar1 != 0xffffffff) {
            param_2[6] = param_2[6] | 1 << (uVar1 & 0x1f);
          }
          iVar2 = *(int *)(iVar5 + 0x14c);
        }
        if (iVar2 != 0) {
          uVar1 = rate_position_get();
          if (uVar1 != 0xffffffff) {
            param_2[7] = param_2[7] | 1 << (uVar1 & 0x1f);
          }
        }
        iVar6 = iVar6 + -1;
        iVar5 = iVar5 + 4;
      } while (iVar6 != 0);
      param_2[2] = *(uint *)(param_1 + 0x84);
      param_2[5] = *(uint *)(param_1 + 0x108);
      param_2[8] = *(uint *)(param_1 + 0x18c);
      param_2[9] = *(uint *)(param_1 + 400);
      param_2[10] = *(uint *)(param_1 + 0x194);
      param_2[0xb] = *(uint *)(param_1 + 0x198);
      param_2[0xc] = *(uint *)(param_1 + 0x19c);
      param_2[0xd] = *(uint *)(param_1 + 0x1a0);
      param_2[0xe] = *(uint *)(param_1 + 0x1a4);
      param_2[0xf] = *(uint *)(param_1 + 0x1a8);
      param_2[0x10] = *(uint *)(param_1 + 0x1ac);
      return;
    }
    uVar3 = 0x4b;
    pcVar4 = "NULL != rate_md5";
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","transfer_rate_db_to_rate_md5",uVar3,pcVar4);
  return;
}

