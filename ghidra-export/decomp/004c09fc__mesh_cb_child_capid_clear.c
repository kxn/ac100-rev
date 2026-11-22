// func _mesh_cb_child_capid_clear @ 004c09fc size=124

undefined4 _mesh_cb_child_capid_clear(int param_1)

{
  undefined2 uVar1;
  
  mesh_db_ap_entry_delete(*(undefined2 *)(param_1 + 0xc));
  if (*(short *)(param_1 + 0x14) == *(short *)(param_1 + 0x16)) {
    *(undefined2 *)(param_1 + 0x16) = 0xffff;
    uVar1 = *(undefined2 *)(param_1 + 0xc);
  }
  else {
    uVar1 = *(undefined2 *)(param_1 + 0xc);
  }
  *(undefined2 *)(param_1 + 0x14) = 0xffff;
  mesh_db_ap_entry_add(uVar1,0,param_1 + 0x14,0);
  apmngr_ap_disconnect(param_1 + 0xc,1,0);
  apmngr_ap_capid_update(*(undefined2 *)(param_1 + 0xc),0xffff);
  return 0;
}

