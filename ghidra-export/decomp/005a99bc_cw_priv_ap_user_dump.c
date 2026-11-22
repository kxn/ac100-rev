// func cw_priv_ap_user_dump @ 005a99bc size=216

undefined4 cw_priv_ap_user_dump(int param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap user \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap user (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar2 = 0;
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: ");
  pcVar1 = pcVar3;
  do {
    iVar2 = iVar2 + 1;
    printf("%02x",(int)*pcVar1);
    pcVar1 = pcVar3 + iVar2;
  } while (iVar2 != 6);
  puts("...\r");
  printf("\t\t\t\tusername: %s \r\n ",pcVar3);
  printf("\t\t\t\tpassword: %s \r\n ",pcVar3 + 0x40);
  return 0;
}

