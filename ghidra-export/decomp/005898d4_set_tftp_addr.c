// func set_tftp_addr @ 005898d4 size=276

void set_tftp_addr(char *param_1)

{
  int iVar1;
  size_t sVar2;
  char *__dest;
  
  iVar1 = g_write_snapshot_data;
  if (((param_1 != (char *)0x0) &&
      (__dest = *(char **)(g_write_snapshot_data + 0x18), __dest != (char *)0x0)) &&
     (sVar2 = strlen(param_1), sVar2 + 1 < 0x201)) {
    strncpy(__dest,param_1,sVar2);
    sVar2 = strlen(param_1);
    *(undefined1 *)(*(int *)(iVar1 + 0x18) + sVar2) = 0;
    if (snapshot_store_debug_switch != 0) {
      printf("[SNAPSHOT_STORE_DEBUG]%s()/%d tftp_addr %s\n","set_tftp_addr",0x2eb,param_1);
    }
    if (snapshot_store_debug_switch != 0) {
      printf("[SNAPSHOT_STORE_DEBUG]%s()/%d g_write_snapshot_data->tftp_addr %s\n","set_tftp_addr",
             0x2ec,*(undefined4 *)(g_write_snapshot_data + 0x18));
    }
    tftp_server_enable = 1;
    return;
  }
  puts("set TFTP addr fail!");
  return;
}

