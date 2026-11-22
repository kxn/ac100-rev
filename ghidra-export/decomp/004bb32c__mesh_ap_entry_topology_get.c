// func _mesh_ap_entry_topology_get @ 004bb32c size=692

undefined4 _mesh_ap_entry_topology_get(int param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_6e8 [32];
  char acStack_6c8 [256];
  undefined1 auStack_5c8 [72];
  undefined1 auStack_580 [656];
  undefined1 auStack_2f0 [72];
  undefined1 auStack_2a8 [660];
  
  memset(auStack_2f0,0,0x2d8);
  memset(auStack_5c8,0,0x2d8);
  memset(auStack_6e8,0,0x1e);
  param_2[2] = param_2[2] + 1;
  if (*param_2 < 1) {
    if (param_2[1] < 1) {
      return 0;
    }
    iVar2 = json_object_new_object();
    if (iVar2 == 0) {
      if (mesh_err_switch == '\0') {
        return 1;
      }
      printf("[MESH_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
             "_mesh_ap_entry_topology_get",0x675);
      return 1;
    }
    iVar3 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0xc),auStack_2f0);
    if (iVar3 == 0) {
      mac2str(auStack_2a8,auStack_6e8,0x1e);
      uVar4 = json_object_new_string(auStack_6e8);
      json_object_object_add(iVar2,"mac",uVar4);
      sVar1 = *(short *)(param_1 + 0x16);
    }
    else {
      sVar1 = *(short *)(param_1 + 0x16);
    }
    if (sVar1 != -1) {
      iVar3 = apmngr_db_entry_get_by_id(sVar1,auStack_5c8);
      if (iVar3 == 0) {
        mac2str(auStack_580,auStack_6e8,0x1e);
        uVar4 = json_object_new_string(auStack_6e8);
        json_object_object_add(iVar2,"parent_mac",uVar4);
      }
    }
    memset(acStack_6c8,0,0x100);
    snprintf(acStack_6c8,0x100,"%d",(uint)*(ushort *)(param_1 + 0xc));
    uVar4 = json_object_new_string(acStack_6c8);
    json_object_object_add(iVar2,"ap_id",uVar4);
    memset(acStack_6c8,0,0x100);
    snprintf(acStack_6c8,0x100,"%d",(int)*(short *)(param_1 + 0x16));
    uVar4 = json_object_new_string(acStack_6c8);
    json_object_object_add(iVar2,"parent_ap_id",uVar4);
    memset(acStack_6c8,0,0x100);
    snprintf(acStack_6c8,0x100,"%d",(int)*(short *)(param_1 + 0x14));
    uVar4 = json_object_new_string(acStack_6c8);
    json_object_object_add(iVar2,"cap_id",uVar4);
    uVar4 = mesh_db_uplink_type_str_get(*(undefined1 *)(param_1 + 0x18));
    uVar4 = json_object_new_string(uVar4);
    json_object_object_add(iVar2,"uplink_type",uVar4);
    memset(acStack_6c8,0,0x100);
    snprintf(acStack_6c8,0x100,"%d",*(undefined4 *)(param_1 + 0x1c));
    uVar4 = json_object_new_string(acStack_6c8);
    json_object_object_add(iVar2,"estimate_rate",uVar4);
    json_object_array_add(param_2[5],iVar2);
    param_2[1] = param_2[1] + -1;
  }
  else {
    *param_2 = *param_2 + -1;
  }
  return 0;
}

