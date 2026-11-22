// func apmngr_encrypt_alg_md5_v2 @ 00558e70 size=360

/* WARNING: Removing unreachable block (ram,0x00558ef8) */

undefined4 apmngr_encrypt_alg_md5_v2(byte *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char acStack_a8 [128];
  
  pcVar7 = "RDpbLfCPsJZ7fiv";
  iVar6 = 0;
  memset(acStack_a8,0,0x80);
  sVar1 = strlen((char *)param_1);
  sVar3 = 0xf;
  if (0xe < (int)sVar1) {
    sVar3 = sVar1;
  }
  for (; iVar6 < (int)sVar3; iVar6 = iVar6 + 1) {
    if (iVar6 < (int)sVar1) {
      uVar5 = (uint)*param_1;
      uVar4 = 0xbb;
      if (iVar6 < 0xf) {
        uVar4 = (uint)(byte)*pcVar7;
      }
    }
    else {
      uVar4 = (uint)(byte)*pcVar7;
      uVar5 = 0xbb;
    }
    sVar2 = strlen(acStack_a8);
    pcVar7 = (char *)((byte *)pcVar7 + 1);
    param_1 = param_1 + 1;
    snprintf(acStack_a8 + sVar2,0x80 - sVar2,"%c",(int)(char)(&UNK_006d03b0)[(uVar4 ^ uVar5) % 0xff]
            );
  }
  sVar3 = strlen(acStack_a8);
  snprintf(acStack_a8 + sVar3,0x80 - sVar3,"%c",0);
  sVar3 = strlen(acStack_a8);
  strncpy(param_2,acStack_a8,sVar3);
  return 0;
}

