// func mesh_cb_for_ap_join @ 004bd590 size=320

undefined4 mesh_cb_for_ap_join(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 local_88;
  undefined2 local_86;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 auStack_7c [100];
  int local_18;
  
  memset(auStack_7c,0,0x68);
  iVar1 = *(int *)(param_1 + 0x14);
  local_84 = 0;
  local_80 = 0;
  if (((iVar1 == 4) || (iVar1 == 8)) || (iVar1 == 6)) {
    local_86 = *(undefined2 *)(param_1 + 0x18);
  }
  else {
    if (iVar1 != 5) {
      if (((iVar1 != 1) && (iVar1 != 3)) && (iVar1 != 2)) {
        return 0;
      }
      local_86 = *(undefined2 *)(param_1 + 0x10);
      uVar3 = 1;
      goto LAB_004bd628;
    }
    local_86 = *(undefined2 *)(param_1 + 0x18);
  }
  uVar3 = 0;
LAB_004bd628:
  local_88 = local_86;
  iVar1 = mesh_db_discover_entry_get(param_1 + 0x48,auStack_7c);
  if (iVar1 == 0) {
    if (local_18 == 1) {
      mesh_db_discover_pair_state_update(param_1 + 0x48,1,2);
      uVar2 = *(undefined2 *)(param_1 + 0x10);
    }
    else {
      uVar2 = *(undefined2 *)(param_1 + 0x10);
    }
  }
  else {
    uVar2 = *(undefined2 *)(param_1 + 0x10);
  }
  iVar1 = mesh_db_ap_entry_add(uVar2,uVar3,&local_88,0);
  uVar3 = 0;
  if ((iVar1 != 0) && (uVar3 = 0xffffffff, mesh_err_switch != '\0')) {
    printf("[MESH_ERROR]%s()/%d Add ap entry(%d) failed\n","mesh_cb_for_ap_join",0xb4,
           (uint)*(ushort *)(param_1 + 0x10));
  }
  return uVar3;
}

