// func rdmngr_for_each_entry_checksum_calc @ 006122b8 size=312

undefined4 rdmngr_for_each_entry_checksum_calc(undefined4 *param_1,undefined4 *param_2)

{
  undefined2 uVar2;
  int iVar1;
  code *pcVar3;
  undefined1 auStack_340 [88];
  undefined1 auStack_2e8 [64];
  undefined4 local_2a8;
  undefined1 auStack_d0 [196];
  
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_340,0,0x54);
  memcpy(auStack_340,param_1,0x54);
  if (rdmngr_debug_switch == 0) {
    pcVar3 = (code *)*param_2;
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      pcVar3 = (code *)*param_2;
    }
    else {
      printf("[RDMNGR_DEBUG]%s()/%d rd_entry->id=%d, len=%d.\n",
             "rdmngr_for_each_entry_checksum_calc",0x79f,*param_1,0x32);
      pcVar3 = (code *)*param_2;
    }
  }
  (*pcVar3)(param_2[1],param_1 + 2,0x32);
  (*(code *)*param_2)(param_2[1],param_2 + 2,0x30);
  if (*(char *)(param_1 + 2) == '\x01') {
    uVar2 = rdmngr_db_generate_ap_id(*param_1);
    iVar1 = apmngr_db_entry_get_by_id(uVar2,auStack_2e8);
    if ((iVar1 == 0) &&
       (iVar1 = apdb_support_11ac_by_id
                          (local_2a8,auStack_d0,*(byte *)((int)param_1 + 3) & 0xf,
                           (int)*(char *)(param_1 + 2)), iVar1 != 0)) {
      (*(code *)*param_2)(param_2[1],param_2 + 0xe,0xc);
    }
  }
  return 0;
}

