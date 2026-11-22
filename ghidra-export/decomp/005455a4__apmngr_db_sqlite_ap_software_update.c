// func _apmngr_db_sqlite_ap_software_update @ 005455a4 size=336

undefined4 _apmngr_db_sqlite_ap_software_update(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char acStack_448 [64];
  char acStack_408 [1024];
  
  memset(acStack_408,0,0x400);
  memset(acStack_448,0,0x40);
  uVar1 = *(uint *)(param_1 + 6);
  if ((*(int *)(param_1 + 2) == 0) && (param_1[4] == 0)) {
    if (uVar1 == 0) {
      if (*(int *)(param_1 + 8) == 0) {
        strncpy(acStack_448,"NULL",0x3f);
        goto LAB_00545634;
      }
      uVar3 = (uint)param_1[3];
    }
    else {
      uVar3 = (uint)param_1[3];
    }
  }
  else {
    uVar3 = (uint)param_1[3];
  }
  snprintf(acStack_448,0x40,"\'%2u.%2u.%2u.%4u.%2u.%2u.%5u\'",(uint)param_1[2],uVar3,
           (uint)param_1[4],uVar1 >> 0x10,(uVar1 << 0x10) >> 0x18,uVar1 & 0xff,
           *(undefined4 *)(param_1 + 8));
LAB_00545634:
  uVar4 = 0;
  snprintf(acStack_408,0x400,"UPDATE %s SET software_ver = %s WHERE entry_id = %d;",
           "ApEntryRun_table",acStack_448,(uint)*param_1);
  iVar2 = FUN_00407d60(DAT_007c58e8,acStack_408);
  if (((iVar2 != 0) && (uVar4 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d Failed to insert to AP-entry table.\n",
           "_apmngr_db_sqlite_ap_software_update",0x2f5);
  }
  return uVar4;
}

