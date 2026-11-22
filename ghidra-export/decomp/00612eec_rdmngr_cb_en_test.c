// func rdmngr_cb_en_test @ 00612eec size=1

undefined4 rdmngr_cb_en_test(undefined4 param_1)

{
  int iVar1;
  
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d rdmngr_cb_en_test() rd_id:%d OK.\n","rdmngr_cb_en_test",0xada,
           param_1);
  }
  return 0;
}

