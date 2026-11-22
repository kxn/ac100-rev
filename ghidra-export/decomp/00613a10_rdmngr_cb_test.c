// func rdmngr_cb_test @ 00613a10 size=1

void rdmngr_cb_test(void)

{
  int iVar1;
  undefined1 auStack_40 [12];
  char *pcStack_34;
  code *pcStack_30;
  code *pcStack_2c;
  undefined4 uStack_c;
  
  memset(auStack_40,0,0x38);
  pcStack_34 = "rdmngr_test";
  pcStack_2c = rdmngr_cb_dis_test;
  pcStack_30 = rdmngr_cb_en_test;
  uStack_c = 10;
  iVar1 = rdmngr_callback_register(auStack_40);
  if (((iVar1 != 0) && (rdmngr_debug_switch != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_callback_register() failed.\n","rdmngr_cb_test",0xaf1);
  }
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_cb_test() OK.\n","rdmngr_cb_test",0xaf4);
  }
  return;
}

