// func is_support_region_code @ 00529fc8 size=256

undefined4 is_support_region_code(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 in_stack_00000040;
  undefined2 in_stack_00000046;
  char in_stack_000002db;
  undefined1 local_178 [2];
  undefined2 local_176;
  undefined1 auStack_174 [356];
  int local_10;
  
  memset(auStack_174,0,0x168);
  local_176 = in_stack_00000046;
  iVar1 = apdb_hwver_exist_by_id(in_stack_00000040,local_178);
  if ((iVar1 == 1) &&
     (iVar1 = apdb_get_ap_by_id(in_stack_00000040,&stack0x00000218,auStack_174), iVar1 == 0)) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 * 0xc3;
      if ((int)(uint)*(byte *)(local_10 + 0x15) <= iVar1) {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (*(char *)(*(int *)(local_10 + 0x30) + iVar2) != in_stack_000002db);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_WARNING]%s()/%d Failed to find entry in AP database, join failed.\n",
             "is_support_region_code",0x480);
    }
  }
  return uVar3;
}

