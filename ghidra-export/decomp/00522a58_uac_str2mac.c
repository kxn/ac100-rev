// func uac_str2mac @ 00522a58 size=236

void uac_str2mac(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      cVar2 = uac_hex_char2int((int)*param_1);
      *param_2 = cVar2 * '\x10';
      pcVar1 = param_1 + 1;
      param_1 = param_1 + 3;
      cVar3 = uac_hex_char2int((int)*pcVar1);
      *param_2 = cVar2 * '\x10' + cVar3;
      param_2 = param_2 + 1;
    } while (iVar4 != 6);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","uac_str2mac",0xbe,"strMac && intMac");
  return;
}

