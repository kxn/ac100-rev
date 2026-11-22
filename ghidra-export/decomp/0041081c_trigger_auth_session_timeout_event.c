// func trigger_auth_session_timeout_event @ 0041081c size=464

undefined4 trigger_auth_session_timeout_event(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_120 [128];
  char acStack_a0 [132];
  
  memset(acStack_a0,0,0x80);
  memset(auStack_120,0,0x80);
  if (param_1 != 0) {
    FUN_00407dd0();
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      memset(acStack_a0,0,0x80);
      snprintf(acStack_a0,0x80,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0xc),
               (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe),
               (uint)*(byte *)(param_1 + 0xf),(uint)*(byte *)(param_1 + 0x10),
               (uint)*(byte *)(param_1 + 0x11));
      uVar2 = json_object_new_string(acStack_a0);
      json_object_object_add(iVar1,"clientMac",uVar2);
      iVar3 = wsta_db_get_entry_by_mac(param_1 + 0xc,auStack_120);
      uVar2 = json_object_new_int(iVar3 == 0);
      json_object_object_add(iVar1,"association",uVar2);
      memset(acStack_a0,0,0x80);
      snprintf(acStack_a0,0x80,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x12),
               (uint)*(byte *)(param_1 + 0x13),(uint)*(byte *)(param_1 + 0x14),
               (uint)*(byte *)(param_1 + 0x15),(uint)*(byte *)(param_1 + 0x16),
               (uint)*(byte *)(param_1 + 0x17));
      uVar2 = json_object_new_string(acStack_a0);
      json_object_object_add(iVar1,"deviceMac",uVar2);
    }
    json_object_to_json_string_ext(iVar1,0);
    nms_event_notify(0x9ba7cc);
    if (iVar1 != 0) {
      json_object_put(iVar1);
    }
  }
  return 0;
}

