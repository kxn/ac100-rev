// func _get_bind_entry_json @ 00461980 size=808

undefined4 _get_bind_entry_json(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_28c;
  undefined1 local_288;
  char acStack_284 [260];
  undefined1 auStack_180 [218];
  char acStack_a6 [65];
  char local_65 [81];
  
  memset(acStack_284,0,0x101);
  local_298 = 0;
  local_294 = 0;
  local_290 = 0;
  local_28c = 0;
  local_288 = 0;
  memset(auStack_180,0,0x168);
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_get_bind_entry_json",0x4d5,
           "_get_bind_entry_json");
  }
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0xffffffff;
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend",
             "_get_bind_entry_json",0x4d6,"ap_entry && p_arg");
    }
  }
  else {
    iVar1 = json_object_new_object();
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend","_get_bind_entry_json"
               ,0x4db);
      }
    }
    else {
      snprintf(acStack_284,0x101,"%d",(uint)*(ushort *)(param_1 + 0x10));
      uVar2 = json_object_new_string(acStack_284);
      json_object_object_add(iVar1,"ap_id",uVar2);
      uVar2 = json_object_new_string(param_1 + 0x4e);
      json_object_object_add(iVar1,"name",uVar2);
      if (*(int *)(param_1 + 0xc) == 0) {
        pcVar4 = "template";
      }
      else {
        pcVar4 = "ap";
      }
      uVar2 = json_object_new_string(pcVar4);
      json_object_object_add(iVar1,"ap_type",uVar2);
      apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_180);
      pcVar4 = local_65;
      if (local_65[0] == '\0') {
        pcVar4 = acStack_a6;
      }
      strncpy(acStack_284,pcVar4,0x100);
      uVar2 = json_object_new_string(acStack_284);
      json_object_object_add(iVar1,"model",uVar2);
      dhcpdef_db_apbind_entry_shallow_get(*(undefined2 *)(param_1 + 0x10),&local_298);
      snprintf(acStack_284,0x101,"%d",CONCAT31(local_290._1_3_,local_28c._0_1_));
      uVar2 = json_object_new_string(acStack_284);
      json_object_object_add(iVar1,"bind_server_num",uVar2);
      snprintf(acStack_284,0x12,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*(byte *)(param_1 + 0x48),
               (uint)*(byte *)(param_1 + 0x49),(uint)*(byte *)(param_1 + 0x4a),
               (uint)*(byte *)(param_1 + 0x4b),(uint)*(byte *)(param_1 + 0x4c),
               (uint)*(byte *)(param_1 + 0x4d));
      uVar2 = json_object_new_string(acStack_284);
      json_object_object_add(iVar1,"mac",uVar2);
      if (local_290._0_1_ == '\0') {
        pcVar4 = "Led off";
      }
      else {
        pcVar4 = "Led on";
      }
      uVar2 = 0;
      uVar3 = json_object_new_string(pcVar4 + 4);
      json_object_object_add(iVar1,"enable",uVar3);
      json_object_array_add(*(undefined4 *)(param_2 + 0x1c),iVar1);
    }
  }
  return uVar2;
}

