// func apmngr_ap_copy @ 00531ca8 size=464

undefined4 apmngr_ap_copy(undefined2 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  undefined4 uVar4;
  char *__s;
  undefined2 local_res0 [8];
  undefined1 *local_4c8;
  int local_4c4;
  undefined4 local_4c0;
  undefined1 auStack_4bc [14];
  undefined1 auStack_4ae [154];
  undefined1 auStack_414 [221];
  undefined1 auStack_337 [71];
  undefined1 auStack_2f0 [12];
  int local_2e4;
  uint local_2dc;
  int local_2b0 [3];
  char acStack_2a3 [376];
  undefined1 auStack_12b [275];
  
  uVar4 = 0xffffffff;
  local_res0[0] = param_1;
  memset(auStack_2f0,0,0x2d8);
  local_4c8 = (undefined1 *)0x0;
  local_4c4 = 0;
  local_4c0 = 0;
  memset(auStack_4bc,0,0x1c8);
  if (((((param_2 != 0) &&
        (iVar1 = apmngr_db_entry_get_by_id(local_res0[0],auStack_2f0), iVar1 == 0)) &&
       ((local_2dc < 2 || ((local_2dc == 3 || (local_2dc == 2)))))) &&
      (uVar4 = 0xffffffff, *(int *)(param_2 + 0x40) == local_2b0[0])) &&
     ((local_2e4 != 2 ||
      (((sVar2 = strlen(acStack_2a3 + 1), 3 < sVar2 &&
        (sVar3 = strlen((char *)(param_2 + 0x4e)), 3 < sVar3)) &&
       (acStack_2a3[sVar2] == *(char *)(param_2 + sVar3 + 0x4d))))))) {
    __s = (char *)(param_2 + 0x4e);
    memcpy(auStack_4bc,local_2b0,0x1c8);
    memset(auStack_4ae,0,0x9a);
    if (local_2e4 == 2) {
      sVar2 = strlen(__s);
      sVar2 = sVar2 - 3;
    }
    else {
      sVar2 = strlen(__s);
    }
    memcpy(auStack_4ae,__s,sVar2);
    uVar4 = 0xffffffff;
    memcpy(auStack_414,(void *)(param_2 + 0xe8),0x120);
    memcpy(auStack_337,auStack_12b,0x41);
    iVar1 = apmngr_ap_cfg_edit(local_res0[0],auStack_4bc);
    local_4c8 = auStack_2f0;
    if (iVar1 == 0) {
      uVar4 = 0;
      local_4c4 = param_2;
      local_4c0 = param_3;
      apmngr_evt_notify(8,&local_4c8);
      apmngr_ap_reboot(local_res0,1,1);
    }
  }
  return uVar4;
}

