// func _uac_wsta_ssid_cmp @ 00632efc size=172

bool _uac_wsta_ssid_cmp(int param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  byte *pbVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 auStack_218 [304];
  byte abStack_e8 [220];
  
  iVar1 = uac_wsta_get_wserv_entry
                    (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                     *(undefined1 *)(param_1 + 0x25),auStack_218);
  bVar5 = true;
  if (iVar1 == 0) {
    sVar2 = strlen((char *)abStack_e8);
    pbVar3 = abStack_e8 + sVar2;
    while (pbVar3 = pbVar3 + -1, abStack_e8 <= pbVar3) {
      if ((byte)(*pbVar3 + 0x9f) < 0x1a) {
        *pbVar3 = *pbVar3 & 0xdf;
      }
    }
    pcVar4 = strstr((char *)abStack_e8,param_2);
    bVar5 = pcVar4 == (char *)0x0;
  }
  return bVar5;
}

