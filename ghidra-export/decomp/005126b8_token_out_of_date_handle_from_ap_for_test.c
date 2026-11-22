// func token_out_of_date_handle_from_ap_for_test @ 005126b8 size=1

void token_out_of_date_handle_from_ap_for_test(void)

{
  void *__s;
  undefined1 auStack_210 [92];
  undefined1 auStack_1b4 [424];
  
  memcpy(auStack_210,
         "{\"method\":\"do\",\"cloud_status\":{\"report_token\":{\"service_id\":\"test\",\"cloud_type\":\"public\"}}}"
         ,0x5c);
  memset(auStack_1b4,0,0x1a4);
  __s = (void *)FUN_00408450(0x1044,0x4ba);
  if (__s != (void *)0x0) {
    memset(__s,0,0x1044);
    *(undefined4 *)((int)__s + 0xc) = 0xe9;
    *(undefined4 *)((int)__s + 0x14) = 1;
    *(undefined4 *)((int)__s + 0x10) = 1;
    memcpy((void *)((int)__s + 0x38),auStack_210,0x200);
    FUN_004082d0(tdcp_from_ap_mutex,0xffffffff);
    FUN_004086b0(&g_tdcp_from_ap_list,__s);
    FUN_004084b0(tdcp_from_ap_cond);
    uac_mutex_give(tdcp_from_ap_mutex);
    return;
  }
  if (tdcp_err_switch == 0) {
    return;
  }
  printf("[TDCP_ERROR]%s()/%d malloc error\n","token_out_of_date_handle_from_ap_for_test",0x4bc);
  return;
}

