// func _mesh_cb_child_capid_update @ 004bdd70 size=128

undefined4 _mesh_cb_child_capid_update(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_2 != 0) {
    mesh_db_ap_entry_delete(*(undefined2 *)(param_1 + 0xc));
    *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_2 + 0x10);
    *(undefined2 *)(param_1 + 0x16) = *(undefined2 *)(param_2 + 0x10);
    mesh_db_ap_entry_add(*(undefined2 *)(param_1 + 0xc),0,param_1 + 0x14,0);
    apmngr_ap_disconnect(param_1 + 0xc,1,0);
    apmngr_ap_capid_update(*(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_2 + 0x10));
    uVar1 = 0;
  }
  return uVar1;
}

