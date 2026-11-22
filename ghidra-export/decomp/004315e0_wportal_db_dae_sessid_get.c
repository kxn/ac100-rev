// func wportal_db_dae_sessid_get @ 004315e0 size=252

undefined4 wportal_db_dae_sessid_get(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *__src;
  int iVar2;
  undefined4 local_118;
  undefined4 local_114;
  undefined1 auStack_110 [256];
  
  local_118 = 0;
  uVar1 = 0xffffffff;
  local_114 = 0;
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    sscanf((char *)(param_1 + 0x82),"%[a-z0-9]-%llu",auStack_110,&local_118);
    if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Get sessid: %llu\n","wportal_db_dae_sessid_get",0x163e);
    }
    uVar1 = 0xffffffff;
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    __src = (void *)FUN_004080c0(dm_sessid_rbtree,&local_118);
    if (__src != (void *)0x0) {
      uVar1 = 0;
      memcpy(param_2,__src,0x180);
    }
    FUN_00407f30(wportal_aut_mutex);
  }
  return uVar1;
}

