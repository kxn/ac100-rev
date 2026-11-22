// func cw_priv_wechat_iplist_dump @ 005cb09c size=216

undefined4 cw_priv_wechat_iplist_dump(int param_1)

{
  size_t sVar1;
  char *__format;
  char *__s;
  undefined4 *puVar2;
  char acStack_48 [49];
  undefined1 local_17;
  
  puVar2 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\t\tType: (t=%d,l=%d) private wechat white ip list \r\n",
         (uint)*(ushort *)(param_1 + 0xc),(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tType: private wechat white ip list (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\t\tValue: %08x...\r\n",*puVar2);
  printf("\t\t\t\tsize: %d \r\n",*puVar2);
  __s = (char *)puVar2[1];
  if (__s != (char *)0x0) {
    sVar1 = strlen(__s);
    if (sVar1 < 0x32) {
      __format = "\t\t\t\twechat white ip list: %s \r\n";
    }
    else {
      memcpy(acStack_48,__s,0x31);
      local_17 = 0;
      __s = acStack_48;
      __format = "\t\t\t\twechat white ip list: %s... \r\n";
    }
    printf(__format,__s);
  }
  return 0;
}

