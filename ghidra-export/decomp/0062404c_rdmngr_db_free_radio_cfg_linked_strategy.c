// func rdmngr_db_free_radio_cfg_linked_strategy @ 0062404c size=116

void rdmngr_db_free_radio_cfg_linked_strategy(int param_1)

{
  int iVar1;
  
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_db_free_radio_cfg_linked_strategy ENTER\n",
           "rdmngr_db_free_radio_cfg_linked_strategy",0x16fa);
  }
  if (param_1 == 0) {
    return;
  }
  FUN_00407df0(param_1);
  return;
}

