// func balance_db_config_get @ 0045c5a0 size=184

undefined4 balance_db_config_get(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (void *)0x0) || (balance_com == 0)) {
    uVar2 = 0xffffffff;
    if ((g_balance_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[BALANCE_ERROR](%32s) %05d: inputs error.\r\n","balance_db_config_get",0x4a9);
    }
  }
  else {
    FUN_004082d0(balance_db_mutex,0xffffffff);
    uVar2 = 0;
    memcpy(param_1,(void *)(balance_com + 8),0x18);
    FUN_00407f30(balance_db_mutex);
  }
  return uVar2;
}

