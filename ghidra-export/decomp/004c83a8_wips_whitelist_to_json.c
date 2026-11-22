// func wips_whitelist_to_json @ 004c83a8 size=732

void wips_whitelist_to_json(int param_1,undefined4 param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  undefined2 local_3f8;
  char acStack_3f4 [260];
  undefined1 auStack_2f0 [18];
  ushort local_2de;
  undefined1 auStack_2a2 [654];
  
  local_408 = 0;
  local_404 = 0;
  local_400 = 0;
  local_3fc = 0;
  local_3f8 = 0;
  memset(auStack_2f0,0,0x2d8);
  wips_mac2str(param_1 + 0x10,&local_408);
  memset(acStack_3f4,0,0x100);
  snprintf(acStack_3f4,0x100,"%d",*(undefined4 *)(param_1 + 0xc));
  uVar2 = json_object_new_string(acStack_3f4);
  json_object_object_add(param_2,"whitelist_id",uVar2);
  uVar2 = json_object_new_string(&local_408);
  json_object_object_add(param_2,"mac",uVar2);
  uVar2 = json_object_new_string(param_1 + 0x16);
  json_object_object_add(param_2,"ssid",uVar2);
  memset(acStack_3f4,0,0x100);
  snprintf(acStack_3f4,0x100,"%d",*(undefined4 *)(param_1 + 0x48));
  uVar2 = json_object_new_string(acStack_3f4);
  json_object_object_add(param_2,"ssid_encode",uVar2);
  uVar1 = *(ushort *)(param_1 + 0x4c);
  if (uVar1 != 0xffff) {
    memset(acStack_3f4,0,0x100);
    snprintf(acStack_3f4,0x100,"%d",(uint)uVar1);
    uVar2 = json_object_new_string(acStack_3f4);
    json_object_object_add(param_2,"sensor_id",uVar2);
    memset(acStack_3f4,0,0x100);
    snprintf(acStack_3f4,0x100,"%d",*(undefined4 *)(param_1 + 0x50));
    uVar2 = json_object_new_string(acStack_3f4);
    json_object_object_add(param_2,"rssi",uVar2);
    apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x4c),auStack_2f0);
    uVar2 = json_object_new_string(auStack_2a2);
    json_object_object_add(param_2,"entry_name",uVar2);
    memset(acStack_3f4,0,0x100);
    snprintf(acStack_3f4,0x100,"%d",(uint)local_2de);
    uVar2 = json_object_new_string(acStack_3f4);
    json_object_object_add(param_2,"group_id",uVar2);
    memset(acStack_3f4,0,0x100);
    snprintf(acStack_3f4,0x100,"%d",*(undefined4 *)(param_1 + 0x54));
    uVar2 = json_object_new_string(acStack_3f4);
    json_object_object_add(param_2,"last_discover_time",uVar2);
  }
  memset(acStack_3f4,0,0x100);
  snprintf(acStack_3f4,0x100,"%d",*(undefined4 *)(param_1 + 0x58));
  uVar2 = json_object_new_string(acStack_3f4);
  json_object_object_add(param_2,"operation_time",uVar2);
  memset(acStack_3f4,0,0x100);
  snprintf(acStack_3f4,0x100,"%d",1);
  uVar2 = json_object_new_string(acStack_3f4);
  json_object_object_add(param_2,"editable",uVar2);
  return;
}

