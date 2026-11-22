// func apupd_str_to_kr @ 00645474 size=184

byte * apupd_str_to_kr(byte *param_1,char *param_2,undefined4 *param_3)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  if (param_1 != (byte *)0x0) goto LAB_006454b8;
  param_1 = (byte *)*param_3;
  bVar1 = *param_1;
  while (bVar1 != 0) {
    pcVar2 = strchr(param_2,(uint)bVar1);
    pbVar3 = param_1;
    if (pcVar2 == (char *)0x0) goto LAB_006454e0;
    param_1 = param_1 + 1;
LAB_006454b8:
    bVar1 = *param_1;
  }
  bVar1 = *param_1;
  pbVar4 = param_1;
  do {
    pbVar3 = pbVar4;
    if (bVar1 == 0) {
LAB_006454ec:
      *param_3 = pbVar3;
      if (*param_1 == 0) {
        param_1 = (byte *)0x0;
      }
      return param_1;
    }
    pcVar2 = strchr(param_2,(uint)bVar1);
    pbVar3 = pbVar4 + 1;
    if (pcVar2 != (char *)0x0) {
      *pbVar4 = 0;
      goto LAB_006454ec;
    }
LAB_006454e0:
    bVar1 = *pbVar3;
    pbVar4 = pbVar3;
  } while( true );
}

