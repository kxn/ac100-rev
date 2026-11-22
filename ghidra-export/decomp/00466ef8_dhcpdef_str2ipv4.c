// func dhcpdef_str2ipv4 @ 00466ef8 size=248

void dhcpdef_str2ipv4(char *param_1,undefined1 *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  char *local_30;
  char local_2c [20];
  
  local_30 = (char *)0x0;
  local_2c[0] = '\0';
  local_2c[1] = '\0';
  local_2c[2] = '\0';
  local_2c[3] = '\0';
  local_2c[4] = '\0';
  local_2c[5] = '\0';
  local_2c[6] = '\0';
  local_2c[7] = '\0';
  local_2c[8] = '\0';
  local_2c[9] = '\0';
  local_2c[10] = '\0';
  local_2c[0xb] = '\0';
  local_2c[0xc] = '\0';
  local_2c[0xd] = '\0';
  local_2c[0xe] = '\0';
  local_2c[0xf] = '\0';
  if ((param_1 == (char *)0x0) || (param_2 == (undefined1 *)0x0)) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","dhcpdef_str2ipv4",0xd8,"strIp && intIp");
  }
  else {
    strncpy(local_2c,param_1,0xf);
    pcVar1 = strtok_r(local_2c,".",&local_30);
    iVar2 = atoi(pcVar1);
    iVar4 = 1;
    *param_2 = (char)iVar2;
    do {
      pcVar1 = strtok_r((char *)0x0,".",&local_30);
      iVar2 = atoi(pcVar1);
      puVar3 = param_2 + iVar4;
      iVar4 = iVar4 + 1;
      *puVar3 = (char)iVar2;
    } while (iVar4 != 4);
  }
  return;
}

