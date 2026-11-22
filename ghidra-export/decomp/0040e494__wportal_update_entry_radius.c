// func _wportal_update_entry_radius @ 0040e494 size=536

void _wportal_update_entry_radius(int param_1)

{
  int iVar1;
  void *__s;
  size_t sVar2;
  undefined4 uVar3;
  timespec local_150;
  undefined1 auStack_148 [121];
  undefined1 auStack_cf [101];
  char acStack_6a [50];
  int local_38;
  undefined1 auStack_28 [24];
  
  if (param_1 == 0) {
    if (wportal_info_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[WPORTAL_INFO]%s()/%d invalid autEntry\n","_wportal_update_entry_radius",0x8bf);
    return;
  }
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d _wportal_update_entry_radius\n","_wportal_update_entry_radius",
           0x8c3);
  }
  memset(auStack_148,0,0x134);
  iVar1 = wportal_db_rds_srv_get_by_index(*(undefined4 *)(param_1 + 0x158),auStack_148);
  if (iVar1 == -1) {
    return;
  }
  if (local_38 == 0) {
    return;
  }
  __s = (void *)FUN_00408450(0x1f8,0x8cb);
  if (__s == (void *)0x0) {
    return;
  }
  memset(__s,0,0x1f8);
  *(int *)((int)__s + 0x19c) = local_38;
  memcpy((void *)((int)__s + 0x6b),(void *)(param_1 + 0x34),6);
  sVar2 = strlen(acStack_6a);
  memcpy((void *)((int)__s + 0xd6),acStack_6a,sVar2 + 1);
  memcpy((void *)((int)__s + 0x71),auStack_cf,100);
  clock_gettime(1,&local_150);
  *(__time_t *)((int)__s + 0x180) = local_150.tv_sec - *(int *)(param_1 + 0x154);
  uVar3 = *(undefined4 *)(param_1 + 0x160);
  *(undefined4 *)((int)__s + 0x17c) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)((int)__s + 0x178) = uVar3;
  FUN_0051a7a8(param_1 + 0x58,(int)__s + 0x184);
  memcpy((void *)((int)__s + 0x65),(void *)(param_1 + 0xc),6);
  sVar2 = strlen((char *)(param_1 + 0xa3));
  memcpy(__s,(char *)(param_1 + 0xa3),sVar2 + 1);
  if (g_portal_auth_mode == 1) {
    uVar3 = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    if (g_portal_auth_mode != 0) goto LAB_0040e5f0;
    uVar3 = *(undefined4 *)(param_1 + 0x14);
  }
  *(undefined4 *)((int)__s + 0x1a0) = uVar3;
LAB_0040e5f0:
  memcpy((void *)((int)__s + 0xfe),auStack_148,0x78);
  memcpy((void *)((int)__s + 0x1c8),auStack_28,0x14);
  uVar3 = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)((int)__s + 0x1e4) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)((int)__s + 0x1e0) = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x178);
  *(undefined4 *)((int)__s + 0x1ec) = *(undefined4 *)(param_1 + 0x17c);
  *(undefined4 *)((int)__s + 0x1e8) = uVar3;
  FUN_00407d70(__s);
  FUN_00407df0(__s);
  return;
}

