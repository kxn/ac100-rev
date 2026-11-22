// func _uac_wsta_ip_cmp @ 00632298 size=188

bool _uac_wsta_ip_cmp(int param_1,char *param_2)

{
  int iVar1;
  bool bVar3;
  char *pcVar2;
  char acStack_58 [68];
  
  iVar1 = strcmp("0.0.0.0",param_2);
  if (iVar1 == 0) {
    bVar3 = *(char *)(param_1 + 0x3c) == '\x01';
  }
  else {
    bVar3 = true;
    if (*(char *)(param_1 + 0x3c) == '\x01') {
      memset(acStack_58,0,0x40);
      FUN_00408190(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                   *(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x48),
                   *(undefined4 *)(param_1 + 0x4c),acStack_58,0x40,"0.0.0.0");
      pcVar2 = strstr(acStack_58,param_2);
      bVar3 = pcVar2 == (char *)0x0;
    }
  }
  return bVar3;
}

