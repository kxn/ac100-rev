// func rdmngr_db_msg_send @ 006201fc size=176

undefined4 rdmngr_db_msg_send(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_18;
  int local_14;
  
  if (param_2 != 0) {
    local_18 = param_1;
    local_14 = param_2;
    FUN_00407e80("rdmngr_db_msg_send");
    uVar1 = FUN_00407d40(g_rdmngr_msgq,&local_18,8,0xc9,5000);
    FUN_004082b0(1,"rdmngr_db_msg_send");
    if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d uac_msgQ_send(), ret = %d\n","rdmngr_db_msg_send",0x1219,uVar1);
    }
  }
  return 0;
}

