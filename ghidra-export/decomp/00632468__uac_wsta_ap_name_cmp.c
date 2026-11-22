// func _uac_wsta_ap_name_cmp @ 00632468 size=168

bool _uac_wsta_ap_name_cmp(int param_1,char *param_2)

{
  size_t sVar1;
  byte *pbVar2;
  char *pcVar3;
  byte abStack_110 [256];
  
  memset(abStack_110,0,0x100);
  FUN_0063240c(*(undefined4 *)(param_1 + 0x20),abStack_110);
  sVar1 = strlen((char *)abStack_110);
  pbVar2 = abStack_110 + sVar1;
  while (pbVar2 = pbVar2 + -1, abStack_110 <= pbVar2) {
    if ((byte)(*pbVar2 + 0x9f) < 0x1a) {
      *pbVar2 = *pbVar2 & 0xdf;
    }
  }
  pcVar3 = strstr((char *)abStack_110,param_2);
  return pcVar3 == (char *)0x0;
}

