// func cw_priv_ap_web_account_dump @ 005a9d30 size=364

undefined4 cw_priv_ap_web_account_dump(int param_1)

{
  char *__src;
  ushort *puVar1;
  char *local_60 [3];
  char acStack_54 [72];
  
  local_60[0] = "TP_MD5_V1";
  local_60[1] = "TP_MD5_V2";
  puVar1 = *(ushort **)(param_1 + 0x10);
  local_60[2] = "TP_RSA_V1";
  memset(acStack_54,0,0x40);
  printf("\t\tType: (t=%d,l=%d) private ap web account \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: private ap web account (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tencrypt algorithm: %d(%s)... \r\n",(uint)*puVar1,local_60[*puVar1]);
  printf("\t\t\t\tusername length: %d... \r\n",(uint)*(byte *)(puVar1 + 1));
  printf("\t\t\t\tpassword length: %d... \r\n",(uint)*(byte *)((int)puVar1 + 3));
  if ((*(char **)(puVar1 + 2) == (char *)0x0) || (*(byte *)(puVar1 + 1) == 0)) {
    puts("\t\t\t\tusername: is null \r");
    __src = *(char **)(puVar1 + 4);
  }
  else {
    strncpy(acStack_54,*(char **)(puVar1 + 2),(uint)*(byte *)(puVar1 + 1));
    printf("\t\t\t\tusername:%s\r\n",acStack_54);
    memset(acStack_54,0,0x40);
    __src = *(char **)(puVar1 + 4);
  }
  if ((__src == (char *)0x0) || (*(byte *)((int)puVar1 + 3) == 0)) {
    puts("\t\t\t\tpassword: is null \r");
  }
  else {
    strncpy(acStack_54,__src,(uint)*(byte *)((int)puVar1 + 3));
    printf("\t\t\t\tpassword:%s\r\n",acStack_54);
  }
  return 0;
}

