// func apmngr_multilink_callback_init @ 00530a3c size=164

undefined4 apmngr_multilink_callback_init(void)

{
  int iVar1;
  undefined4 uVar2;
  char *local_18;
  undefined4 local_14;
  code *local_10;
  code *local_c;
  
  local_18 = "apmngr";
  local_14 = 0x79000000;
  uVar2 = 0;
  local_10 = apmngr_multilink_switch_to_master;
  local_c = apmngr_multilink_switch_to_standby;
  iVar1 = multi_link_reg(&local_18);
  if (((iVar1 == -1) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_ERROR]%s()/%d register callback to multi link failed.\n",
           "apmngr_multilink_callback_init",0xcfc);
  }
  return uVar2;
}

