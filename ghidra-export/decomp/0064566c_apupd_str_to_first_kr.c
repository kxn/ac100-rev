// func apupd_str_to_first_kr @ 0064566c size=224

byte * apupd_str_to_first_kr(byte *param_1,char *param_2,undefined4 *param_3)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (param_1 != (byte *)0x0) goto LAB_006456b0;
  param_1 = (byte *)*param_3;
  bVar1 = *param_1;
  while (bVar1 != 0) {
    pcVar2 = strchr(param_2,(uint)bVar1);
    pbVar4 = param_1;
    if (pcVar2 == (char *)0x0) goto LAB_006456d8;
    param_1 = param_1 + 1;
LAB_006456b0:
    bVar1 = *param_1;
  }
  bVar1 = *param_1;
  pbVar3 = param_1;
  while (bVar1 != 0) {
    pcVar2 = strchr(param_2,(uint)bVar1);
    pbVar4 = pbVar3 + 1;
    if (pcVar2 != (char *)0x0) {
      *pbVar3 = 0;
      goto LAB_00645700;
    }
LAB_006456d8:
    pbVar3 = pbVar4;
    bVar1 = *pbVar4;
  }
  bVar1 = *pbVar3;
  pbVar4 = pbVar3;
  do {
    if (bVar1 == 0) {
      *param_3 = pbVar4;
LAB_00645710:
      if (*param_1 == 0) {
        param_1 = (byte *)0x0;
      }
      return param_1;
    }
    pcVar2 = strchr(param_2,(uint)*param_1);
    if (pcVar2 == (char *)0x0) {
      *param_3 = pbVar4;
      goto LAB_00645710;
    }
    pbVar4 = pbVar4 + 1;
LAB_00645700:
    bVar1 = *pbVar4;
  } while( true );
}

