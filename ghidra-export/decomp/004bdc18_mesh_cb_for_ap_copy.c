// func mesh_cb_for_ap_copy @ 004bdc18 size=160

undefined4 mesh_cb_for_ap_copy(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = *(int *)(param_1 + 0x14);
    if ((iVar1 == 1) || (iVar1 == 3)) {
      iVar1 = *(int *)(param_2 + 0x14);
    }
    else {
      if (iVar1 != 2) {
        return 0;
      }
      iVar1 = *(int *)(param_2 + 0x14);
    }
    if (((iVar1 == 1) || (iVar1 == 3)) || (iVar1 == 2)) {
      mesh_db_ap_entry_child_foreach_proc
                (*(undefined2 *)(param_2 + 0x10),0,_mesh_cb_child_capid_update,param_1);
      mesh_db_ap_entry_child_foreach_proc
                (*(undefined2 *)(param_1 + 0x10),0,_mesh_cb_child_disconnect,param_1);
    }
  }
  return 0;
}

