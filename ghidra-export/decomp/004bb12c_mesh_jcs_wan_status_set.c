// func mesh_jcs_wan_status_set @ 004bb12c size=360

void mesh_jcs_wan_status_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  char local_18 [8];
  
  uVar3 = 0xffffffff;
  iVar1 = json_object_object_get(param_1,"wan_status");
  if ((iVar1 != 0) &&
     ((iVar2 = json_object_get_type(iVar1), iVar2 == 3 ||
      (iVar2 = json_object_get_type(iVar1), iVar2 == 2)))) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_18[0] = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        local_18[0] = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "mesh_jcs_wan_status_set",0x6f8);
        }
        local_18[0] = -1;
      }
    }
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d wan_status: %d\n","mesh_jcs_wan_status_set",0x6f9,(int)local_18[0]
            );
    }
    uVar3 = 0;
    mesh_db_mesh_wan_status_set((int)local_18[0]);
    mesh_db_mesh_wan_status_get(local_18);
    mesh_pkt_wan_status_request_send_to_all((int)local_18[0]);
  }
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

