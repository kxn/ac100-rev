// func apupd_log_from_struct_to_json @ 00640c94 size=500

undefined4 apupd_log_from_struct_to_json(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  char acStack_4e8 [128];
  char acStack_468 [128];
  char acStack_3e8 [256];
  undefined1 auStack_2e8 [78];
  char acStack_29a [650];
  
  memset(acStack_468,0,0x80);
  memset(acStack_4e8,0,0x80);
  memset(auStack_2e8,0,0x2d8);
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_log_from_struct_to_json",0xa82);
    }
  }
  else {
    iVar1 = apmngr_db_entry_get_by_mac(param_1 + 0x38,auStack_2e8);
    pcVar4 = acStack_29a;
    if (iVar1 == -1) {
      pcVar4 = "---";
    }
    uVar2 = json_object_new_string(pcVar4);
    json_object_object_add(param_2,"name",uVar2);
    iVar1 = *(int *)(param_1 + 0x18);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    sprintf(acStack_468,"%04d/%02d/%02d %02d:%02d:%02d",*(int *)(param_1 + 0x20) + 0x76c,
            *(int *)(param_1 + 0x1c) + 1,iVar1,*(undefined4 *)(param_1 + 0x14),
            *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc));
    uVar2 = json_object_new_string(acStack_468);
    json_object_object_add(param_2,"fail_time",uVar2);
    sprintf(acStack_4e8,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x38),
            (uint)*(byte *)(param_1 + 0x39),(uint)*(byte *)(param_1 + 0x3a),
            (uint)*(byte *)(param_1 + 0x3b),(uint)*(byte *)(param_1 + 0x3c),
            (uint)*(byte *)(param_1 + 0x3d));
    uVar2 = json_object_new_string(acStack_4e8);
    json_object_object_add(param_2,"mac",uVar2);
    memset(acStack_3e8,0,0x100);
    uVar2 = 0;
    snprintf(acStack_3e8,0x100,"%d",(uint)*(byte *)(param_1 + 0x3e));
    uVar3 = json_object_new_string(acStack_3e8);
    json_object_object_add(param_2,"fail_type",uVar3);
  }
  return uVar2;
}

