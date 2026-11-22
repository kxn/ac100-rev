// func cw_ac_data_manager_session_delete_process @ 005895cc size=116

void cw_ac_data_manager_session_delete_process(int param_1)

{
  if (param_1 != 0) {
    memcpy((void *)(*(int *)(param_1 + 0xc) + 0x7c),(void *)(param_1 + 0x2c),0x14);
    *(undefined2 *)(*(int *)(param_1 + 0xc) + 0x90) = *(undefined2 *)(param_1 + 0x40);
    cw_fsm_ac_teardown(param_1);
    return;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_manager_session_delete_process",0x698,
         "session");
  return;
}

