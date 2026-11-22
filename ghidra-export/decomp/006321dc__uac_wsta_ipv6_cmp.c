// func _uac_wsta_ipv6_cmp @ 006321dc size=188

bool _uac_wsta_ipv6_cmp(int param_1,char *param_2)

{
  int iVar1;
  bool bVar3;
  char *pcVar2;
  char acStack_58 [68];
  
  iVar1 = strcmp("::",param_2);
  if (iVar1 == 0) {
    bVar3 = *(char *)(param_1 + 0x50) == '\x02';
  }
  else {
    bVar3 = true;
    if (*(char *)(param_1 + 0x50) == '\x02') {
      memset(acStack_58,0,0x40);
      FUN_00408190(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
                   *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
                   *(undefined4 *)(param_1 + 0x60),acStack_58,0x40,&DAT_00698ca0);
      pcVar2 = strstr(acStack_58,param_2);
      bVar3 = pcVar2 == (char *)0x0;
    }
  }
  return bVar3;
}

