// func pre_handle_json_test @ 00512548 size=1

void pre_handle_json_test(void)

{
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined1 auStack_20c [108];
  undefined1 auStack_1a0 [412];
  
  memcpy(auStack_20c,
         "{\"method\":\"get\",\"cloud_config\":{\"table\":\"get_report_token\",\"filter\":[{\"service_id\":\"1\",\"token_type\":\"0\"}]}}"
         ,0x6c);
  memset(auStack_1a0,0,0x194);
  uStack_210 = 0;
  uStack_214 = 0;
  uStack_218 = 0;
  pre_handle_tdcp_request(auStack_20c,&uStack_210,&uStack_214,&uStack_218);
  if (tdcp_debug_switch != 0) {
    printf("[TDCP_DEBUG]%s()/%d pre handle json_str:%s,tdcp_type:%s,op:%d\n","pre_handle_json_test",
           0x49a,uStack_210,uStack_214,uStack_218);
  }
  return;
}

