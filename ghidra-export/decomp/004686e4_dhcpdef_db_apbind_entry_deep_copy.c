// func dhcpdef_db_apbind_entry_deep_copy @ 004686e4 size=308

undefined4 dhcpdef_db_apbind_entry_deep_copy(void *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *__dest;
  char *pcVar3;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "dst && src";
    uVar2 = 0x309;
  }
  else {
    __dest = *(void **)((int)param_1 + 0xd);
    if ((__dest != (void *)0x0) && (*(int *)((int)param_2 + 0xd) != 0)) {
      memcpy(param_1,param_2,0x11);
      memcpy(__dest,*(void **)((int)param_2 + 0xd),DAT_0076708c << 2);
      *(void **)((int)param_1 + 0xd) = __dest;
      return 0;
    }
    if (g_dhcpdef_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "dst->svr_id_list && src->svr_id_list";
    uVar2 = 0x30a;
  }
  printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
         "dhcpdef_db_apbind_entry_deep_copy",uVar2,pcVar3);
  return 0xffffffff;
}

