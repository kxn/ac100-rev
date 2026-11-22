// func mesh_cb_for_ap_leave @ 004bddf0 size=96

undefined4 mesh_cb_for_ap_leave(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if ((((iVar1 == 1) || (iVar1 == 3)) || (iVar1 == 2)) &&
     (iVar1 = mesh_db_discover_state_get(), iVar1 != 0)) {
    mesh_db_discover_list_delete_by_capid(*(undefined2 *)(param_1 + 0x10));
  }
  return 0;
}

