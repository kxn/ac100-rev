// func wips_whitelist_entry_load @ 004ce5f0 size=188

undefined4 wips_whitelist_entry_load(void *param_1)

{
  void *__dest;
  undefined4 uVar1;
  
  __dest = (void *)FUN_00408450(0x5c,0xe79);
  if (__dest == (void *)0x0) {
    uVar1 = 0xffffffff;
    if (sensor_err_switch != '\0') {
      printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_whitelist_entry_load",0xe7c);
    }
  }
  else {
    memcpy(__dest,param_1,0x5c);
    FUN_004082d0(wips_global_mutex,0xffffffff);
    FUN_004086b0(&g_white_list,__dest);
    uVar1 = 0;
    FUN_00408440(g_whitelist_id_allocator,*(undefined4 *)((int)__dest + 0xc));
    FUN_00407f30(wips_global_mutex);
  }
  return uVar1;
}

