// func apmngr_db_entry_get_by_mac @ 0053a248 size=200

undefined4 apmngr_db_entry_get_by_mac(int param_1,void *param_2)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d mac is NULL.\n","apmngr_db_entry_get_by_mac",0x6d6);
    }
  }
  else {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = 0xffffffff;
    __src = (void *)FUN_00407fa0(g_apmngr_ap_hash,param_1);
    if ((__src != (void *)0x0) && (uVar2 = 0, param_2 != (void *)0x0)) {
      memcpy(param_2,__src,0x2d8);
    }
    FUN_00407f30(apmngr_db_mutex);
  }
  return uVar2;
}

