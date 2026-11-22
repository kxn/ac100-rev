// func nms_call_wtp_online @ 0049dcf4 size=348

undefined4 nms_call_wtp_online(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *__format;
  char acStack_310 [40];
  undefined1 auStack_2e8 [20];
  int local_2d4;
  byte local_2a0;
  byte local_29f;
  byte local_29e;
  byte local_29d;
  byte local_29c;
  byte local_29b;
  
  memset(acStack_310,0,0x24);
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == -1) {
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_ERROR]%s()/%d get ap entry by id failed.\n";
    uVar2 = 0x211;
  }
  else {
    if (local_2d4 == 7) {
      return 0;
    }
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      sprintf(acStack_310,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a0,(uint)local_29f,
              (uint)local_29e,(uint)local_29d,(uint)local_29c,(uint)local_29b);
      uVar2 = json_object_new_string(acStack_310);
      json_object_object_add(iVar1,"devMac",uVar2);
      json_object_to_json_string_ext(iVar1,0);
      nms_event_notify(0x989a6b);
      json_object_put(iVar1);
      return 0;
    }
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_ERROR]%s()/%d malloc obj failed.\n\n";
    uVar2 = 0x21a;
  }
  printf(__format,"nms_call_wtp_online",uVar2);
  return 0xffffffff;
}

