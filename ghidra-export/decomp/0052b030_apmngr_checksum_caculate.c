// func apmngr_checksum_caculate @ 0052b030 size=272

int apmngr_checksum_caculate(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_358 [104];
  undefined1 *local_2f0 [2];
  undefined1 auStack_2e8 [732];
  
  memset(local_2f0,0,0x2e0);
  memset(auStack_358,0,0x68);
  if (param_1 == (void *)0x0) {
    iVar1 = -1;
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Input ap entry is NULL.\n","apmngr_checksum_caculate",0x218);
    }
  }
  else {
    FUN_00408590(auStack_358);
    local_2f0[0] = auStack_358;
    memcpy(auStack_2e8,param_1,0x2d8);
    iVar1 = apmngr_callback_proc(5,local_2f0);
    if (((iVar1 != 0) && (apmngr_err_switch != '\0')) && (iVar2 = is_target_debug_ap(), iVar2 != 0))
    {
      printf("[APMNGR_ERROR]%s()/%d Failed to caculate AP\'s checksum for some data in other module is missing.\n"
             ,"apmngr_checksum_caculate",0x224);
    }
    FUN_00407e90((int)param_1 + 0x29a,auStack_358);
  }
  return iVar1;
}

