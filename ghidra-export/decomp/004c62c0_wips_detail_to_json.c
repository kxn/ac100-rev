// func wips_detail_to_json @ 004c62c0 size=672

void wips_detail_to_json(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  char acStack_3f0 [256];
  undefined1 auStack_2f0 [18];
  ushort local_2de;
  undefined1 auStack_2a2 [654];
  
  memset(auStack_2f0,0,0x2d8);
  memset(acStack_3f0,0,0x100);
  snprintf(acStack_3f0,0x100,"%d",*(undefined4 *)(param_1 + 0x20));
  uVar1 = json_object_new_string(acStack_3f0);
  json_object_object_add(param_2,"discovery_time",uVar1);
  memset(acStack_3f0,0,0x100);
  snprintf(acStack_3f0,0x100,"%d",*(undefined4 *)(param_1 + 0x24));
  uVar1 = json_object_new_string(acStack_3f0);
  json_object_object_add(param_2,"last_time",uVar1);
  memset(acStack_3f0,0,0x100);
  snprintf(acStack_3f0,0x100,"%d",*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20));
  uVar1 = json_object_new_string(acStack_3f0);
  json_object_object_add(param_2,"duration",uVar1);
  memset(acStack_3f0,0,0x100);
  snprintf(acStack_3f0,0x100,"%d",*(undefined4 *)(param_1 + 0x28));
  uVar1 = json_object_new_string(acStack_3f0);
  json_object_object_add(param_2,"wips_threat_type",uVar1);
  uVar2 = *(int *)(param_1 + 0x28) + 0xfecea807;
  if (uVar2 < 0xd) {
    pcVar3 = (&PTR_DAT_006a8334)[uVar2];
  }
  else {
    pcVar3 = "invalid name";
  }
  uVar1 = json_object_new_string(pcVar3);
  json_object_object_add(param_2,"wips_threat_name",uVar1);
  memset(acStack_3f0,0,0x100);
  snprintf(acStack_3f0,0x100,"%d",*(undefined4 *)(param_1 + 0x30));
  uVar1 = json_object_new_string(acStack_3f0);
  json_object_object_add(param_2,"rssi",uVar1);
  if (*(short *)(param_1 + 0x38) == -1) {
    uVar1 = json_object_new_string("---");
    json_object_object_add(param_2,"entry_name",uVar1);
    memset(acStack_3f0,0,0x100);
    uVar2 = 0xffffffff;
  }
  else {
    apmngr_db_entry_get_by_id(*(short *)(param_1 + 0x38),auStack_2f0);
    uVar1 = json_object_new_string(auStack_2a2);
    json_object_object_add(param_2,"entry_name",uVar1);
    memset(acStack_3f0,0,0x100);
    uVar2 = (uint)local_2de;
  }
  snprintf(acStack_3f0,0x100,"%d",uVar2);
  uVar1 = json_object_new_string(acStack_3f0);
  json_object_object_add(param_2,"group_id",uVar1);
  return;
}

