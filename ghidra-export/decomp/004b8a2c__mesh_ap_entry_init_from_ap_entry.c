// func _mesh_ap_entry_init_from_ap_entry @ 004b8a2c size=452

undefined4 _mesh_ap_entry_init_from_ap_entry(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  int local_2f8;
  undefined4 local_2f4;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined1 auStack_2e8 [519];
  char local_e1;
  
  local_2f4 = 0;
  local_2f0 = 0;
  local_2ec = 0;
  memset(auStack_2e8,0,0x2d8);
  iVar2 = *(int *)(param_1 + 0x14);
  local_2f8 = 0;
  if ((((iVar2 == 4) || (iVar2 == 8)) || (iVar2 == 6)) || (iVar2 == 5)) {
    local_2f4 = CONCAT22(*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x18));
  }
  bVar3 = true;
  if ((iVar2 != 1) && (iVar2 != 3)) {
    bVar3 = iVar2 == 2;
  }
  iVar2 = mesh_db_ap_entry_add(*(undefined2 *)(param_1 + 0x10),bVar3,&local_2f4,0);
  if (iVar2 == 0) {
    iVar2 = mesh_db_mesh_enable_get(&local_2f8);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x14);
      if ((local_2f8 != 0) && (iVar2 - 2U < 2)) {
        if (mesh_debug_switch == '\0') {
          uVar1 = *(undefined2 *)(param_1 + 0x10);
        }
        else {
          printf("[MESH_DEBUG]%s()/%d ap(%u) role %d ap mesh witch open \n",
                 "_mesh_ap_entry_init_from_ap_entry",0x146,(uint)*(ushort *)(param_1 + 0x10),iVar2);
          uVar1 = *(undefined2 *)(param_1 + 0x10);
        }
        apmngr_set_ap_mesh_switch(uVar1,1);
        iVar2 = *(int *)(param_1 + 0x14);
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 0x14);
    }
    if ((((iVar2 == 4) || (iVar2 == 8)) || (iVar2 == 6)) || (uVar4 = 0, iVar2 == 5)) {
      uVar4 = 0;
      iVar2 = mesh_db_mesh_enable_get(&local_2f8);
      if (((iVar2 == 0) && (local_2f8 != 0)) &&
         ((iVar2 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x18),auStack_2e8),
          iVar2 == 0 && (local_e1 == '\0')))) {
        apmngr_set_ap_mesh_switch(*(undefined2 *)(param_1 + 0x18),1);
      }
    }
  }
  else {
    uVar4 = 1;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Add ap entry(%d) failed\n","_mesh_ap_entry_init_from_ap_entry",
             0x13c,(uint)*(ushort *)(param_1 + 0x10));
    }
  }
  return uVar4;
}

