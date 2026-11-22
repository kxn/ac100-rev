// func accrypt_n2rn @ 00666830 size=316

void accrypt_n2rn(int *param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    if (g_accrypt_error != 0) {
      pcVar2 = "[ACCRYPT_ERROR]%s()/%05d: input error.\r\n";
      uVar5 = 0x66;
LAB_00666954:
      printf(pcVar2,"accrypt_n2rn",uVar5);
      return;
    }
  }
  else {
    pcVar2 = (char *)malloc(0x10000000);
    if (pcVar2 == (char *)0x0) {
      if (g_accrypt_error != 0) {
        pcVar2 = "[ACCRYPT_ERROR]%s()/%05d: malloc failed.\r\n";
        uVar5 = 0x6e;
        goto LAB_00666954;
      }
    }
    else {
      memset(pcVar2,0,0x10000000);
      uVar6 = 0;
      uVar4 = 0;
      pcVar3 = pcVar2;
      while (uVar4 < *param_2) {
        cVar1 = *(char *)(*param_1 + uVar4);
        if (cVar1 == '\n') {
          *pcVar3 = '\r';
          uVar6 = uVar6 + 2;
          pcVar3[1] = '\n';
          uVar4 = uVar4 + 1;
          pcVar3 = pcVar3 + 2;
        }
        else {
          *pcVar3 = cVar1;
          uVar6 = uVar6 + 1;
          pcVar3 = pcVar3 + 1;
          uVar4 = uVar4 + 1;
        }
      }
      free((void *)*param_1);
      *param_1 = (int)pcVar2;
      *param_2 = uVar6;
    }
  }
  return;
}

