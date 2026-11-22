// func wips_delete_whitelist_due_to_wserv @ 004cb3e8 size=168

undefined4 wips_delete_whitelist_due_to_wserv(void)

{
  int iVar1;
  int iVar2;
  int in_stack_0000012c;
  
  FUN_004082d0(wips_global_mutex,0xffffffff);
  for (iVar1 = FUN_004081b0(&g_white_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
    iVar2 = strncmp((char *)(iVar1 + 0x16),&stack0x00000130,0x32);
    if ((iVar2 == 0) && (*(int *)(iVar1 + 0x48) == in_stack_0000012c)) {
      whitelist_entry_delete(iVar1);
    }
  }
  FUN_00407f30(wips_global_mutex);
  return 0;
}

