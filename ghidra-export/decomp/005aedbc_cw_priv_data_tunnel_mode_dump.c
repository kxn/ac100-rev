// func cw_priv_data_tunnel_mode_dump @ 005aedbc size=220

undefined4 cw_priv_data_tunnel_mode_dump(int param_1)

{
  int iVar1;
  char *__format;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private data tunnel mode \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private data tunnel mode (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*piVar2);
  printf("\t\t\t\tdata tunnel mode: %u",*piVar2);
  iVar1 = *piVar2;
  if (iVar1 == 1) {
    __format = "(remote raw)";
  }
  else if (iVar1 == 0) {
    __format = "(remote cap)";
  }
  else if (iVar1 == 2) {
    __format = "(local)";
  }
  else {
    __format = "(unknown mode)";
  }
  printf(__format);
  puts("\r");
  return 0;
}

