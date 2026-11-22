// func cw_priv_config_type_dump @ 005ae79c size=220

undefined4 cw_priv_config_type_dump(int param_1)

{
  int iVar1;
  char *__format;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private ap config type \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private ap config type (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x \r\n",*piVar2);
  printf("\t\t\t\tconfig type: %u ",*piVar2);
  iVar1 = *piVar2;
  if (iVar1 == 1) {
    __format = "(part config)";
  }
  else if (iVar1 == 0) {
    __format = "(no config)";
  }
  else if (iVar1 == 2) {
    __format = "(full config)";
  }
  else {
    __format = "(unknown value)";
  }
  printf(__format);
  puts("\r");
  return 0;
}

